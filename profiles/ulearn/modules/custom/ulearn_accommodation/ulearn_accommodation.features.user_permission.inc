<?php
/**
 * @file
 * ulearn_accommodation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_accommodation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create accommodation_display content'.
  $permissions['create accommodation_display content'] = array(
    'name' => 'create accommodation_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create commerce_product entities of bundle accommodation'.
  $permissions['create commerce_product entities of bundle accommodation'] = array(
    'name' => 'create commerce_product entities of bundle accommodation',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'delete any accommodation_display content'.
  $permissions['delete any accommodation_display content'] = array(
    'name' => 'delete any accommodation_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own accommodation_display content'.
  $permissions['delete own accommodation_display content'] = array(
    'name' => 'delete own accommodation_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any accommodation_display content'.
  $permissions['edit any accommodation_display content'] = array(
    'name' => 'edit any accommodation_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any commerce_product entity of bundle accommodation'.
  $permissions['edit any commerce_product entity of bundle accommodation'] = array(
    'name' => 'edit any commerce_product entity of bundle accommodation',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own accommodation_display content'.
  $permissions['edit own accommodation_display content'] = array(
    'name' => 'edit own accommodation_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own commerce_product entities of bundle accommodation'.
  $permissions['edit own commerce_product entities of bundle accommodation'] = array(
    'name' => 'edit own commerce_product entities of bundle accommodation',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle accommodation'.
  $permissions['view any commerce_product entity of bundle accommodation'] = array(
    'name' => 'view any commerce_product entity of bundle accommodation',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle accommodation'.
  $permissions['view own commerce_product entities of bundle accommodation'] = array(
    'name' => 'view own commerce_product entities of bundle accommodation',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  return $permissions;
}
