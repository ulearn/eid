<?php
/**
 * @file
 * ulearn_slideshow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_slideshow_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create banner_slideshow content'.
  $permissions['create banner_slideshow content'] = array(
    'name' => 'create banner_slideshow content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any banner_slideshow content'.
  $permissions['delete any banner_slideshow content'] = array(
    'name' => 'delete any banner_slideshow content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own banner_slideshow content'.
  $permissions['delete own banner_slideshow content'] = array(
    'name' => 'delete own banner_slideshow content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any banner_slideshow content'.
  $permissions['edit any banner_slideshow content'] = array(
    'name' => 'edit any banner_slideshow content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own banner_slideshow content'.
  $permissions['edit own banner_slideshow content'] = array(
    'name' => 'edit own banner_slideshow content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'update banner_slideshow_queue entityqueue'.
  $permissions['update banner_slideshow_queue entityqueue'] = array(
    'name' => 'update banner_slideshow_queue entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update small_banner_queue entityqueue'.
  $permissions['update small_banner_queue entityqueue'] = array(
    'name' => 'update small_banner_queue entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'entityqueue',
  );

  return $permissions;
}
