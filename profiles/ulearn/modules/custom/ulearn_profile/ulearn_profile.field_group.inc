<?php
/**
 * @file
 * ulearn_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulearn_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other_details|user|user|form';
  $field_group->group_name = 'group_other_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other details',
    'weight' => '12',
    'children' => array(
      0 => 'field_user_dislikes',
      1 => 'field_user_experience',
      2 => 'field_user_likes',
      3 => 'field_user_teaching_philosophy',
      4 => 'field_user_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Other details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-other-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_other_details|user|user|form'] = $field_group;

  return $export;
}
