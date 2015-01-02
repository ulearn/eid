<?php

/**
 * @file
 * Provides functionality to be used at install time.
 */

/**
 * Implements hook_install_tasks().
 */
function ulearn_install_tasks(&$install_state) {
  // Generate an install task to install required modules.
  $tasks = array();
  $tasks['ulearn_configure_civicrm'] = array(
    'display_name' => st('Install CiviCRM'),
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  $tasks['ulearn_rebuild_node_access'] = array();
  $tasks['ulearn_wrapup'] = array();
  return $tasks;
}

/**
 * Task callback for Install and configure CiviCRM.
 */
function ulearn_configure_civicrm(&$install_state) {
  $operations = array();

  // Install CiviCRM.
  $operations[] = array('ulearn_install_civicrm_database', array());
  $operations[] = array('ulearn_install_civicrm', array());

  $batch = array(
    'title' => t('Install and configure CiviCRM'),
    'init_message' => t('Installing CiviCRM'),
    'operations' => $operations,
  );

  return $batch;
}

/**
 * Setup database with CiviCRM structure and data.
 */
function ulearn_install_civicrm_database(&$context) {
  // Get path to CiviCRM.
  $civicrm_path = drupal_get_path('module', 'civicrm');
  // $civicrm_path contains /drupal which is not necesary.
  $civicrm_path = str_replace('/drupal', '', $civicrm_path);
  // Path to CiviCRM sql files.
  $sql_path = DRUPAL_ROOT . '/' . $civicrm_path . '/sql';
  // Get the constant CIVICRM_DSN from civicrm.settings.php
  require_once DRUPAL_ROOT . '/sites/default/civicrm.settings.php';

  // Decide data file and acl file for default language.
  $data_file = $sql_path . '/civicrm_data.mysql';
  $acl_file = $sql_path . '/civicrm_acl.mysql';

  // Import sql files into database.
  _ulearn_install_civicrm_source(CIVICRM_DSN, $sql_path . '/civicrm.mysql');
  _ulearn_install_civicrm_source(CIVICRM_DSN, $data_file);
  _ulearn_install_civicrm_source(CIVICRM_DSN, $acl_file);

  $context['message'] = t('Configuring CiviCRM.');
}

/**
 * Imports sql file into database.
 */
function _ulearn_install_civicrm_source($dsn, $fileName, $lineMode = FALSE) {
  // Check if file exists at path.
  if (!file_exists($fileName)) {
    return;
  }

  $civicrm_path = drupal_get_path('module', 'civicrm');
  // $civicrm_path contains /drupal which is not necesary.
  $civicrm_path = str_replace('/drupal', '', $civicrm_path);
  require_once $civicrm_path . '/packages/DB.php';
  $db = DB::connect($dsn);

  if (PEAR::isError($db)) {
    die("Cannot open $dsn: " . $db->getMessage());
  }

  if (!$lineMode) {
    $string = file_get_contents($fileName);
    // change \r\n to fix windows issues
    $string = str_replace("\r\n", "\n", $string);

    //get rid of comments starting with # and --

    $string = preg_replace("/^#[^\n]*$/m", "\n", $string);
    $string = preg_replace("/^(--[^-]).*/m", "\n", $string);

    $queries = preg_split('/;$/m', $string);
    foreach ($queries as $query) {
      $query = trim($query);
      if (!empty($query)) {
        $res = &$db->query($query);
        if (PEAR::isError($res)) {
          die("Cannot execute $query: " . $res->getMessage());
        }
      }
    }
  }
  else {
    $fd = fopen($fileName, "r");
    while ($string = fgets($fd)) {
      $string = preg_replace("/^#[^\n]*$/m", "\n", $string);
      $string = preg_replace("/^(--[^-]).*/m", "\n", $string);

      $string = trim($string);
      if (!empty($string)) {
        $res = &$db->query($string);
        if (PEAR::isError($res)) {
          die("Cannot execute $string: " . $res->getMessage());
        }
      }
    }
  }
}

/**
 * Install CiviCRM.
 */
function ulearn_install_civicrm(&$context) {
  // Enable CiviCRM module.
  module_enable(array('civicrm'));
  global $base_url;
  if (civicrm_initialize()) {
    $param = array();
    // Setup CiviCRM resource URL.
    $params['userFrameworkResourceURL'] = $base_url . '/' . str_replace('drupal', '', drupal_get_path('module', 'civicrm'));
    $result = civicrm_api('setting', 'create', $params + array('version' => 3));
    CRM_Core_BAO_ConfigSetting::create($params);

    // Reconstruct the config.
    $config = CRM_Core_Config::singleton(TRUE, TRUE);
    CRM_Core_BAO_Navigation::resetNavigation();
  }
  $context['message'] = t('CiviCRM installed.');
}

/**
 * Post installation task: Rebuild node access database.
 */
function ulearn_rebuild_node_access(&$install_state) {
  node_access_rebuild();
  // Flush all caches to ensure that any full bootstraps during the installer
  // do not leave stale cached data, and that any content types or other items
  // registered by the install profile are registered correctly.
  drupal_flush_all_caches();
}

/**
 * Post installation task: Perform comman tasks.
 */
function ulearn_wrapup(&$install_state) {
  drupal_flush_all_caches();
  
  // Configure permission names for urls:
  config_perms_cache_rebuild();

  // Revert feature which gets overrriden
  features_revert(
    array(
      'ulearn_base' => array('user_permission'),
      'ulearn_commerce' => array('user_permission'),
      'ulearn_course' => array('user_permission'),
      'ulearn_school' => array('field_instance', 'user_permission'),
      'ulearn_profile' => array('user_permission', 'variable'),
      'ulearn_settings' => array('user_permission', 'filter'),
    )
  );

  // Make sure the core commerce settings are in sync.
  commerce_currencies(FALSE, TRUE);

  // Enable default content module.
  module_enable(array('ulearn_default_content'));

  // Enable ULearn CiviCRM module. Make sure CiviCRM is installed.
  if (module_exists('civicrm')) {
    module_enable(array('ulearn_civicrm'));
  }

  //rebuild menu
  menu_rebuild();

  // Flush all caches to ensure that any full bootstraps during the installer
  // do not leave stale cached data, and that any content types or other items
  // registered by the install profile are registered correctly.
  drupal_flush_all_caches();
}
