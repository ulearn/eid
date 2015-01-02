<?php

/**
 * @file
 * Variable hooks for ULearn Commerce module.
 */

/**
 * Implements hook_variable_group_info().
 */
function ulearn_commerce_variable_group_info() {
  $groups['ulearn_commerce'] = array(
    'title' => t('Ulearn Commerce'),
    'description' => t('Variable mail of different types.'),
    'access' => 'administer ulearn',
    'path' => array('admin/config/ulearn/variable/ulearn_commerce'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function ulearn_commerce_variable_info($options) {
  $variables['ulearn_commerce_order_created_mail_[mail_part]'] = array(
    'type' => 'mail_html',
    'title' => t('Order created email', array(), $options),
    'default' => array(
      'subject' => t('Your order at [site:name]', array(), $options),
      'body' => t('Thanks for your order!!', array(), $options),
    ),
    'description' => t('Admin mail variable with subject and body.', array(), $options),
    'group' => 'ulearn_commerce',
    'optional' => TRUE,
  );

  $variables['ulearn_commerce_order_admin_mail_[mail_part]'] = array(
    'type' => 'mail_html',
    'title' => t('Order admin email', array(), $options),
    'default' => array(
      'subject' => t('New order at [site:name]', array(), $options),
      'body' => t('New order has been placed !!', array(), $options),
    ),
    'description' => t('Admin mail variable with subject and body.', array(), $options),
    'group' => 'ulearn_commerce',
    'optional' => TRUE,
  );

  // Instructions per payment processor.
  foreach (commerce_payment_method_options_list() as $method => $method_title) {
    $message_variables = ulearn_commerce_payment_transaction_message_variables_help($method);
    $help = !empty($message_variables) ? '<br />' . t('Extra tokens: @tokens.', array('@tokens' => implode(', ', $message_variables))) : '';
    $variables['ulearn_commerce_payment_instructions_' . $method] = array(
      'type' => 'text_format',
      'title' => t('@payment_method instructions', array('@payment_method' => $method_title), $options),
      'default' => array(
        'value' => t('You have used %payment_method for this transaction.', array('%payment_method' => $method_title)),
        'format' => 'full_html',
      ),
      'group' => 'ulearn_commerce',
      'optional' => TRUE,
      'description' => t('Configure instructions for %payment_method. You can use replacement patterns from below.', array('%payment_method' => $method_title)) . $help,
    );
  }

  // Per country instructions for PaytoStudy.
  $countries = array('IN' => 'India', 'RU' => 'Russia');
  foreach ($countries as $country_code => $country_name) {
    $variables['ulearn_commerce_paytostudy_instructions_' . $country_code] = array(
      'type' => 'text_format',
      'title' => t('PaytoStudy instructions for !name', array('!name' => $country_name)),
      'default' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'group' => 'ulearn_commerce',
      'optional' => TRUE,
      'description' => t('Configure instructions for PaytoStudy for !name. You can use replacement patterns from below.', array('!name' => $country_name)),
    );
  }

  $variables['ulearn_commerce_paytostudy_instructions_other'] = array(
    'type' => 'text_format',
    'title' => t('PaytoStudy instructions for other countries'),
    'default' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'group' => 'ulearn_commerce',
    'optional' => TRUE,
    'description' => t('Configure instructions for PaytoStudy for other countries. You can use replacement patterns from below.'),
  );

  $variables['ulearn_commerce_pay_reception_instructions'] = array(
    'type' => 'text_format',
    'title' => t('Pay Cash / Credit Card In Reception Instructions'),
    'default' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'group' => 'ulearn_commerce',
    'optional' => TRUE,
    'description' => t('Configurable instructions for the Pay Cash / Credit Card In Reception payment method to display on checkout completion page. Do not include script to embed map here. You can include it at !global-settings.', array('!global-settings' => '<a href="' . url('admin/config/ulearn/global-settings') . '">Global settings</a>')),
  );

  return $variables;
}
