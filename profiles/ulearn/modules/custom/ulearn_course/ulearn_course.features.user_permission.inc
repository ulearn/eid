<?php
/**
 * @file
 * ulearn_course.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_course_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer own ulearn_course_registration registration'.
  $permissions['administer own ulearn_course_registration registration'] = array(
    'name' => 'administer own ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer ulearn_course_registration registration'.
  $permissions['administer ulearn_course_registration registration'] = array(
    'name' => 'administer ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'configure ulearn commerce store'.
  $permissions['configure ulearn commerce store'] = array(
    'name' => 'configure ulearn commerce store',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'create course_display content'.
  $permissions['create course_display content'] = array(
    'name' => 'create course_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_course_unique_id'.
  $permissions['create field_course_unique_id'] = array(
    'name' => 'create field_course_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_registration_unique_id'.
  $permissions['create field_registration_unique_id'] = array(
    'name' => 'create field_registration_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ulearn_share_amount'.
  $permissions['create field_ulearn_share_amount'] = array(
    'name' => 'create field_ulearn_share_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create ulearn_course_registration registration'.
  $permissions['create ulearn_course_registration registration'] = array(
    'name' => 'create ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'student' => 'student',
      'team member' => 'team member',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create ulearn_course_registration registration other anonymous'.
  $permissions['create ulearn_course_registration registration other anonymous'] = array(
    'name' => 'create ulearn_course_registration registration other anonymous',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'student' => 'student',
      'team member' => 'team member',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create ulearn_course_registration registration other users'.
  $permissions['create ulearn_course_registration registration other users'] = array(
    'name' => 'create ulearn_course_registration registration other users',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete any course_display content'.
  $permissions['delete any course_display content'] = array(
    'name' => 'delete any course_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ulearn_course_registration registration'.
  $permissions['delete any ulearn_course_registration registration'] = array(
    'name' => 'delete any ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete own course_display content'.
  $permissions['delete own course_display content'] = array(
    'name' => 'delete own course_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ulearn_course_registration registration'.
  $permissions['delete own ulearn_course_registration registration'] = array(
    'name' => 'delete own ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'edit any course_display content'.
  $permissions['edit any course_display content'] = array(
    'name' => 'edit any course_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_course_unique_id'.
  $permissions['edit field_course_unique_id'] = array(
    'name' => 'edit field_course_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_registration_unique_id'.
  $permissions['edit field_registration_unique_id'] = array(
    'name' => 'edit field_registration_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ulearn_share_amount'.
  $permissions['edit field_ulearn_share_amount'] = array(
    'name' => 'edit field_ulearn_share_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own course_display content'.
  $permissions['edit own course_display content'] = array(
    'name' => 'edit own course_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_course_unique_id'.
  $permissions['edit own field_course_unique_id'] = array(
    'name' => 'edit own field_course_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_registration_unique_id'.
  $permissions['edit own field_registration_unique_id'] = array(
    'name' => 'edit own field_registration_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ulearn_share_amount'.
  $permissions['edit own field_ulearn_share_amount'] = array(
    'name' => 'edit own field_ulearn_share_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit ulearn_course_registration registration state'.
  $permissions['edit ulearn_course_registration registration state'] = array(
    'name' => 'edit ulearn_course_registration registration state',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'update any ulearn_course_registration registration'.
  $permissions['update any ulearn_course_registration registration'] = array(
    'name' => 'update any ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'update own ulearn_course_registration registration'.
  $permissions['update own ulearn_course_registration registration'] = array(
    'name' => 'update own ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view any unpublished course_display content'.
  $permissions['view any unpublished course_display content'] = array(
    'name' => 'view any unpublished course_display content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view field_course_unique_id'.
  $permissions['view field_course_unique_id'] = array(
    'name' => 'view field_course_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_registration_unique_id'.
  $permissions['view field_registration_unique_id'] = array(
    'name' => 'view field_registration_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ulearn_share_amount'.
  $permissions['view field_ulearn_share_amount'] = array(
    'name' => 'view field_ulearn_share_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_unique_id'.
  $permissions['view own field_course_unique_id'] = array(
    'name' => 'view own field_course_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_registration_unique_id'.
  $permissions['view own field_registration_unique_id'] = array(
    'name' => 'view own field_registration_unique_id',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ulearn_share_amount'.
  $permissions['view own field_ulearn_share_amount'] = array(
    'name' => 'view own field_ulearn_share_amount',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own ulearn_course_registration registration'.
  $permissions['view own ulearn_course_registration registration'] = array(
    'name' => 'view own ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view ulearn_course_registration registration'.
  $permissions['view ulearn_course_registration registration'] = array(
    'name' => 'view ulearn_course_registration registration',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'registration',
  );

  return $permissions;
}
