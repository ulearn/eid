<?php
/**
 * @file
 * ulearn_commerce.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_commerce_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access checkout'.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'student' => 'student',
      'team member' => 'team member',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'administer commerce_order entities'.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'administer commerce_product entities'.
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'configure order settings'.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities'.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle commerce_order'.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_product entities'.
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle course'.
  $permissions['create commerce_product entities of bundle course'] = array(
    'name' => 'create commerce_product entities of bundle course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle materials'.
  $permissions['create commerce_product entities of bundle materials'] = array(
    'name' => 'create commerce_product entities of bundle materials',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle product'.
  $permissions['create commerce_product entities of bundle product'] = array(
    'name' => 'create commerce_product entities of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle transport'.
  $permissions['create commerce_product entities of bundle transport'] = array(
    'name' => 'create commerce_product entities of bundle transport',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create product_display content'.
  $permissions['create product_display content'] = array(
    'name' => 'create product_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any product_display content'.
  $permissions['delete any product_display content'] = array(
    'name' => 'delete any product_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own product_display content'.
  $permissions['delete own product_display content'] = array(
    'name' => 'delete own product_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any commerce_order entity'.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle commerce_order'.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_product entity'.
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle course'.
  $permissions['edit any commerce_product entity of bundle course'] = array(
    'name' => 'edit any commerce_product entity of bundle course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle materials'.
  $permissions['edit any commerce_product entity of bundle materials'] = array(
    'name' => 'edit any commerce_product entity of bundle materials',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle product'.
  $permissions['edit any commerce_product entity of bundle product'] = array(
    'name' => 'edit any commerce_product entity of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle transport'.
  $permissions['edit any commerce_product entity of bundle transport'] = array(
    'name' => 'edit any commerce_product entity of bundle transport',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any product_display content'.
  $permissions['edit any product_display content'] = array(
    'name' => 'edit any product_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own commerce_order entities'.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle commerce_order'.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_product entities'.
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle course'.
  $permissions['edit own commerce_product entities of bundle course'] = array(
    'name' => 'edit own commerce_product entities of bundle course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle materials'.
  $permissions['edit own commerce_product entities of bundle materials'] = array(
    'name' => 'edit own commerce_product entities of bundle materials',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle product'.
  $permissions['edit own commerce_product entities of bundle product'] = array(
    'name' => 'edit own commerce_product entities of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle transport'.
  $permissions['edit own commerce_product entities of bundle transport'] = array(
    'name' => 'edit own commerce_product entities of bundle transport',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own product_display content'.
  $permissions['edit own product_display content'] = array(
    'name' => 'edit own product_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any commerce_order entity'.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle commerce_order'.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_product entity'.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'student' => 'student',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle course'.
  $permissions['view any commerce_product entity of bundle course'] = array(
    'name' => 'view any commerce_product entity of bundle course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle materials'.
  $permissions['view any commerce_product entity of bundle materials'] = array(
    'name' => 'view any commerce_product entity of bundle materials',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle product'.
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle transport'.
  $permissions['view any commerce_product entity of bundle transport'] = array(
    'name' => 'view any commerce_product entity of bundle transport',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle commerce_order'.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_product entities'.
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle course'.
  $permissions['view own commerce_product entities of bundle course'] = array(
    'name' => 'view own commerce_product entities of bundle course',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle materials'.
  $permissions['view own commerce_product entities of bundle materials'] = array(
    'name' => 'view own commerce_product entities of bundle materials',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle product'.
  $permissions['view own commerce_product entities of bundle product'] = array(
    'name' => 'view own commerce_product entities of bundle product',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle transport'.
  $permissions['view own commerce_product entities of bundle transport'] = array(
    'name' => 'view own commerce_product entities of bundle transport',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view payments'.
  $permissions['view payments'] = array(
    'name' => 'view payments',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'commerce_payment',
  );

  return $permissions;
}
