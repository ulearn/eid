<?php

/**
 * @file Rules integration for the Modal forms module.
 */

/**
 * Implements hook_rules_action_info().
 */
function modal_forms_rules_action_info() {
  return array(
    'modal_forms_aware_redirect' => array(
      'label' => t('Page redirect (modal forms aware)'),
      'group' => t('System'),
      'parameter' => array(
        'url' => array(
          'type' => 'uri',
          'label' => t('URL'),
          'description' => t('A Drupal path, path alias, or external URL to redirect to. Enter (optional) queries after "?" and (optional) anchor after "#".'),
        ),
        'force' => array(
          'type' => 'boolean',
          'label' => t('Force redirect'),
          'restriction' => 'input',
          'description' => t("Force the redirect even if another destination parameter is present. Per default Drupal would redirect to the path given as destination parameter, in case it is set. Usually the destination parameter is set by appending it to the URL, e.g. !example_url", array('!example_url' => 'http://example.com/user/login?destination=node/2')),
          'optional' => TRUE,
          'default value' => TRUE,
        ),
        'destination' => array(
          'type' => 'boolean',
          'label' => t('Append destination parameter'),
          'restriction' => 'input',
          'description' => t('Whether to append a destination parameter to the URL, so another redirect issued later on would lead back to the origin page.'),
          'optional' => TRUE,
          'default value' => FALSE,
        ),
      ),
      'access callback' => 'rules_system_integration_access',
    ),
  );
}

/**
 * Action: Modal forms aware page redirect.
 *
 */
function modal_forms_aware_redirect($url, $force = FALSE, $destination = FALSE) {
  if ((arg(0) === 'modal_forms') && (arg(1) === 'ajax')) {
    $options = array();
    if (isset($_GET['destination']) && !url_is_external($_GET['destination'])) {
      $options['query'] = array('destination' => $_GET['destination']);
    }
    $http_response_code = 302;
    drupal_alter('drupal_goto', $url, $options, $http_response_code);
    $_GET['destination'] = url($url, $options);
    return;
  }
  module_load_include('inc', 'rules', 'modules/system.eval');
  rules_action_drupal_goto($url, $force, $destination);
}
