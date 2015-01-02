<?php

/**
 * @file
 * Provides placeholder tokens for ULearn commerce.
 */

/**
 * Implements hook_token_info_alter().
 */
function ulearn_commerce_token_info_alter(&$data) {
  $data['tokens']['commerce-order']['payment-method-instructions'] = array(
    'name' => t('Payment method instructions'),
    'description' => t('Configurable instructions for the payment method selected by the customer during checkout.'),
  );
  $data['tokens']['commerce-order']['paytostudy-country-instructions'] = array(
    'name' => t('Countrywise PaytoStudy instructions'),
    'description' => t('Configurable instructions for the PaytoStudy depend on selected country while checkout.'),
  );
  $data['tokens']['commerce-order']['pay-reception-instructions'] = array(
    'name' => t('Pay Cash / Credit Card In Reception Instructions'),
    'description' => t('Configurable instructions for the Pay Cash / Credit Card In Reception payment method.'),
  );
}

/**
 * Implements hook_tokens().
 */
function ulearn_commerce_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'commerce-order' && !empty($data['commerce-order'])) {
    $order = $data['commerce-order'];

    if (!empty($order->data['payment_method'])) {
      $payment_method = commerce_payment_method_instance_load($order->data['payment_method']);
      $method_id = $payment_method['method_id'];

      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'payment-method-instructions':
            $message_variables = ulearn_commerce_payment_transaction_message_variables($method_id, $order);

            if ($method_id == 'commerce_paytostudy') {
              $replacements[$original] = ulearn_commerce_paytostudy_payment_instructions($order, $message_variables);
            }
            else {
              $instructions = variable_get_value('ulearn_commerce_payment_instructions_' . $method_id);
              // Do not keep variables as it is if those are not available.
              $help = ulearn_commerce_payment_transaction_message_variables_help($method_id);
              foreach ($help as $variable) {
                if (!isset($message_variables[$variable])) {
                  $message_variables[$variable] = '-';
                }
              }

              $replace = token_replace($instructions['value'], array('commerce-order' => $order), array('clear' => TRUE));
              $replacements[$original] = t($replace, $message_variables);
            }
            break;

          case 'paytostudy-country-instructions':
            list($method_id, $payment_method) = explode('|', $order->data['payment_method']);

            if ($method_id == 'commerce_paytostudy') {
              $countries = array('IN', 'RU');
              $profile = commerce_customer_profile_load($order->commerce_customer_shipping[LANGUAGE_NONE][0]['profile_id']);

              $address = $profile->commerce_customer_address[LANGUAGE_NONE][0];

              $country_code = $address['country'];
              if (in_array($country_code, $countries)) {
                $variable = 'ulearn_commerce_paytostudy_instructions_' . $country_code;
              }
              else {
                $variable = 'ulearn_commerce_paytostudy_instructions_other';
              }
              $instructions = variable_get_value($variable);
              $replace = check_markup($instructions['value'], $instructions['format']);
              $replacements[$original] = $replace;
            }
            else {
              $replacements[$original] = '';
            }
            break;

          case 'pay-reception-instructions':
            list($method_id, $payment_method) = explode('|', $order->data['payment_method']);
            $replace = '';
            if ($method_id == 'bank_transfer') {
              $instructions = variable_get_value('ulearn_commerce_pay_reception_instructions');
              $replace = check_markup($instructions['value'], $instructions['format']);
            }
            $replacements[$original] = $replace;
            break;
        }
      }
    }
    else {
      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'payment-method-instructions':
          case 'paytostudy-country-instructions':
            $replacements[$original] = '';
            break;
        }
      }
    }
  }

  return $replacements;
}
