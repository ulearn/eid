<?php
/**
 * @file
 * ulearn_profile.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulearn_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'student' => 'student',
      'team member' => 'team member',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'student' => 'student',
      'team member' => 'team member',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access mailchimp activity'.
  $permissions['access mailchimp activity'] = array(
    'name' => 'access mailchimp activity',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'mailchimp_activity',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'student' => 'student',
      'team member' => 'team member',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'print',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer flickr'.
  $permissions['administer flickr'] = array(
    'name' => 'administer flickr',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'flickr',
  );

  // Exported permission: 'administer mailchimp'.
  $permissions['administer mailchimp'] = array(
    'name' => 'administer mailchimp',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'mailchimp',
  );

  // Exported permission: 'administer mailchimp activity'.
  $permissions['administer mailchimp activity'] = array(
    'name' => 'administer mailchimp activity',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'mailchimp_activity',
  );

  // Exported permission: 'administer mailchimp campaigns'.
  $permissions['administer mailchimp campaigns'] = array(
    'name' => 'administer mailchimp campaigns',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'mailchimp_campaign',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer string overrides'.
  $permissions['administer string overrides'] = array(
    'name' => 'administer string overrides',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'stringoverrides',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'cancel users with no custom roles'.
  $permissions['cancel users with no custom roles'] = array(
    'name' => 'cancel users with no custom roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role administrator'.
  $permissions['cancel users with role administrator'] = array(
    'name' => 'cancel users with role administrator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role administrator and other roles'.
  $permissions['cancel users with role administrator and other roles'] = array(
    'name' => 'cancel users with role administrator and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role anonymoususer'.
  $permissions['cancel users with role anonymoususer'] = array(
    'name' => 'cancel users with role anonymoususer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role anonymoususer and other roles'.
  $permissions['cancel users with role anonymoususer and other roles'] = array(
    'name' => 'cancel users with role anonymoususer and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role authenticateduser'.
  $permissions['cancel users with role authenticateduser'] = array(
    'name' => 'cancel users with role authenticateduser',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role authenticateduser and other roles'.
  $permissions['cancel users with role authenticateduser and other roles'] = array(
    'name' => 'cancel users with role authenticateduser and other roles',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role student'.
  $permissions['cancel users with role student'] = array(
    'name' => 'cancel users with role student',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role student and other roles'.
  $permissions['cancel users with role student and other roles'] = array(
    'name' => 'cancel users with role student and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role ulearnadmin'.
  $permissions['cancel users with role ulearnadmin'] = array(
    'name' => 'cancel users with role ulearnadmin',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role ulearnadmin and other roles'.
  $permissions['cancel users with role ulearnadmin and other roles'] = array(
    'name' => 'cancel users with role ulearnadmin and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'display site configuration menu'.
  $permissions['display site configuration menu'] = array(
    'name' => 'display site configuration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit users with no custom roles'.
  $permissions['edit users with no custom roles'] = array(
    'name' => 'edit users with no custom roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role administrator'.
  $permissions['edit users with role administrator'] = array(
    'name' => 'edit users with role administrator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role administrator and other roles'.
  $permissions['edit users with role administrator and other roles'] = array(
    'name' => 'edit users with role administrator and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role anonymoususer'.
  $permissions['edit users with role anonymoususer'] = array(
    'name' => 'edit users with role anonymoususer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role anonymoususer and other roles'.
  $permissions['edit users with role anonymoususer and other roles'] = array(
    'name' => 'edit users with role anonymoususer and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role authenticateduser'.
  $permissions['edit users with role authenticateduser'] = array(
    'name' => 'edit users with role authenticateduser',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role authenticateduser and other roles'.
  $permissions['edit users with role authenticateduser and other roles'] = array(
    'name' => 'edit users with role authenticateduser and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role student'.
  $permissions['edit users with role student'] = array(
    'name' => 'edit users with role student',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role student and other roles'.
  $permissions['edit users with role student and other roles'] = array(
    'name' => 'edit users with role student and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role ulearnadmin'.
  $permissions['edit users with role ulearnadmin'] = array(
    'name' => 'edit users with role ulearnadmin',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role ulearnadmin and other roles'.
  $permissions['edit users with role ulearnadmin and other roles'] = array(
    'name' => 'edit users with role ulearnadmin and other roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'view all flickr photos'.
  $permissions['view all flickr photos'] = array(
    'name' => 'view all flickr photos',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'flickr',
  );

  // Exported permission: 'view any unpublished article content'.
  $permissions['view any unpublished article content'] = array(
    'name' => 'view any unpublished article content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished page content'.
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view own flickr photos'.
  $permissions['view own flickr photos'] = array(
    'name' => 'view own flickr photos',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'flickr',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'ulearn admin' => 'ulearn admin',
    ),
    'module' => 'system',
  );

  return $permissions;
}
