<?php
/**
 * @file
 * ulearn_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer ulearn'.
  $permissions['administer ulearn'] = array(
    'name' => 'administer ulearn',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'ulearn_settings',
  );

  // Exported permission: 'display site building menu'.
  $permissions['display site building menu'] = array(
    'name' => 'display site building menu',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
