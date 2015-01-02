<?php
/**
 * @file
 * ulearn_special_courses.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_special_courses_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create commerce_product entities of bundle special_course'.
  $permissions['create commerce_product entities of bundle special_course'] = array(
    'name' => 'create commerce_product entities of bundle special_course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create special_course content'.
  $permissions['create special_course content'] = array(
    'name' => 'create special_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any special_course content'.
  $permissions['delete any special_course content'] = array(
    'name' => 'delete any special_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own special_course content'.
  $permissions['delete own special_course content'] = array(
    'name' => 'delete own special_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any commerce_product entity of bundle special_course'.
  $permissions['edit any commerce_product entity of bundle special_course'] = array(
    'name' => 'edit any commerce_product entity of bundle special_course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any special_course content'.
  $permissions['edit any special_course content'] = array(
    'name' => 'edit any special_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own commerce_product entities of bundle special_course'.
  $permissions['edit own commerce_product entities of bundle special_course'] = array(
    'name' => 'edit own commerce_product entities of bundle special_course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own special_course content'.
  $permissions['edit own special_course content'] = array(
    'name' => 'edit own special_course content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any commerce_product entity of bundle special_course'.
  $permissions['view any commerce_product entity of bundle special_course'] = array(
    'name' => 'view any commerce_product entity of bundle special_course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle special_course'.
  $permissions['view own commerce_product entities of bundle special_course'] = array(
    'name' => 'view own commerce_product entities of bundle special_course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  return $permissions;
}
