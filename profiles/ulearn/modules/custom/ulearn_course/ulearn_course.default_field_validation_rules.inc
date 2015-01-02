<?php
/**
 * @file
 * ulearn_course.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function ulearn_course_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Course unique values';
  $rule->name = 'course_unique_values';
  $rule->field_name = 'field_course_unique_id';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'course_display';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      30037204 => 0,
      174086182 => 0,
      88601972 => 0,
      66784200 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = '[field-name] already exists.';
  $export['course_unique_values'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Phone number';
  $rule->name = 'phone_number';
  $rule->field_name = 'field_user_phone';
  $rule->col = 'value';
  $rule->entity_type = 'registration';
  $rule->bundle = 'ulearn_course_registration';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '10',
    'max' => '',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      30037204 => 0,
      174086182 => 0,
      88601972 => 0,
      66784200 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'Phone number should have atleast 10 digits.';
  $export['phone_number'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Registration unique values';
  $rule->name = 'registration_unique_values';
  $rule->field_name = 'field_registration_unique_id';
  $rule->col = 'value';
  $rule->entity_type = 'registration';
  $rule->bundle = 'ulearn_course_registration';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      30037204 => 0,
      174086182 => 0,
      88601972 => 0,
      66784200 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = '[field-name] already exists.';
  $export['registration_unique_values'] = $rule;

  return $export;
}
