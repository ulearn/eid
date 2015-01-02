<?php
/**
 * @file
 * ulearn_commerce.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function ulearn_commerce_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Phone number for billing profile';
  $rule->name = 'phone_number_billing';
  $rule->field_name = 'field_user_phone';
  $rule->col = 'value';
  $rule->entity_type = 'commerce_customer_profile';
  $rule->bundle = 'billing';
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
  $export['phone_number_billing'] = $rule;

  return $export;
}
