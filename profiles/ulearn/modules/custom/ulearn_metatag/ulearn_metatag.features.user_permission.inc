<?php
/**
 * @file
 * ulearn_metatag.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_metatag_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'metatag',
  );

  return $permissions;
}
