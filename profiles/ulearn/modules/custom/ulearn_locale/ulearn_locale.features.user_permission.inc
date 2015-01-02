<?php
/**
 * @file
 * ulearn_locale.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_locale_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer content translations'.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'locale',
  );

  return $permissions;
}
