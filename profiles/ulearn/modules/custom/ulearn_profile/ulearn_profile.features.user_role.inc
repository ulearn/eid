<?php
/**
 * @file
 * ulearn_profile.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ulearn_profile_user_default_roles() {
  $roles = array();

  // Exported role: student.
  $roles['student'] = array(
    'name' => 'student',
    'weight' => 5,
    'machine_name' => 'student',
  );

  // Exported role: team member.
  $roles['team member'] = array(
    'name' => 'team member',
    'weight' => 6,
    'machine_name' => 'team_member',
  );

  // Exported role: ulearn admin.
  $roles['ulearn admin'] = array(
    'name' => 'ulearn admin',
    'weight' => 3,
    'machine_name' => 'ulearn_admin',
  );

  return $roles;
}
