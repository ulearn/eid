<?php

/*
 * Settings form
 */
function commerce_paytostudy_settings_form($settings = NULL) {
  $form = array();

  // Settings for Pay to Study
  $settings = (array) $settings + array(
    'username_loginto' => '',
    'password_loginto' => '',
    'convertOnly' => FALSE,
    'paytostudy_post_request_url' => 'https://test-xml-service.studentfees.com/paymentservice.dll',
    'bank_account_id' => '',
    'debug_mode' => FALSE,
  );

  $form['username_loginto'] = array(
    '#type' => 'textfield',
    '#title' => t('Pay to study Username'),
    '#description' => t('Pay to study service username'),
    '#default_value' => $settings['username_loginto'],
    '#required' => TRUE,
  );

  $form['password_loginto'] = array(
    '#type' => 'textfield',
    '#title' => t('Pay to Study password'),
    '#description' => t('Pay to study service password'),
    '#default_value' => $settings['password_loginto'],
    '#required' => TRUE,
  );

  $form['convertOnly'] = array(
    '#type' => 'checkbox',
    '#title' => t('Convert Only'),
    '#description' => t('If you set this to true or 1, the transaction won\'t be processed and you will get the converted amount into the user\'s currency based on the user\'s country '),
    '#default_value' => $settings['convertOnly'],
  );

  $form['paytostudy_post_request_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Pay to Study post request url'),
    '#description' => t('Request url for Pay to Study post service'),
    '#default_value' => $settings['paytostudy_post_request_url'],
    '#required' => TRUE,
  );
  
  $form['bank_account_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Bank account ID'),
    '#description' => t('Bank account ID'),
    '#default_value' => $settings['bank_account_id'],
    '#required' => TRUE,
  );

  $form['paytostudy_instructions'] = array(
    '#type' => 'textarea',
    '#title' => t('Payment instructions'),
    '#description' => t('Instructions for customers on the checkout page. Use &lt;br /&gt; for line break.'),
    '#default_value' => isset($settings['paytostudy_instructions']) ? $settings['paytostudy_instructions'] : '',
    '#required' => FALSE,
    '#rows' => 3,
  );

  $form['paytostudy_logo_url'] = array(
    '#type' => 'textfield',
    '#title' => t('PaytoStudy logo URl'),
    '#description' => t('PaytoStudy logo path.'),
    '#default_value' => isset($settings['paytostudy_logo_url']) ? $settings['paytostudy_logo_url'] : '',
    '#required' => FALSE,
  );

  $form['paytostudy_phone_field_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Customer profile phone field name'),
    '#description' => t('Machine name of the phone field to fetch phone number of user, which is mandatory to send in request'),
    '#default_value' => isset($settings['paytostudy_phone_field_name']) ? $settings['paytostudy_phone_field_name'] : '',
    '#required' => FALSE,
  );

  $form['debug_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debug mode'),
    '#description' => t('If debug mode is enabled, the request and response will be logged in watchdog.'),
    '#default_value' => $settings['debug_mode'],
  );
  
  return $form;
}

/**
 * Payment method callback: submit form.
 */
function commerce_paytostudy_submit_form($payment_method, $pane_values, $checkout_pane, $order) {
  $form = array();

  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);

  $settings = $payment_method['settings'];
  $logo = '';
  if(!empty($payment_method['settings']['paytostudy_logo_url'])) {
    $logo = _commerce_paytostudy_logo($payment_method['settings']['paytostudy_logo_url']);
  }

  $instruction = $settings['paytostudy_instructions'] . '!logo';

  $form['who_is_making_the_paymet'] = array(
    '#title' => t('Who is making the payment?'),
    '#type' => 'select',
    '#options' => array('Student' => t('Student')),
    '#default_value' => 'Student',
  );

  $address = $order_wrapper->commerce_customer_shipping->commerce_customer_address->value();

  $countries = country_get_list();
  $form['country_pay_from'] = array(
    '#title' => t('What country are you paying from?'),
    '#type' => 'select',
    '#options' => array($address['country'] => $countries[$address['country']]),
    '#default_value' => $address['country'],
  );

  // Payer CPF number - only for Brazil.
  if ($address['country'] == 'BR') {
    $form['payer_cpf'] = array(
      '#title' => t('CPF number'),
      '#type' => 'textfield',
      '#description' => t('The CPF number must be provided in the following format: nnn.nnn.nnn-nn: (where n is a digit 0-9).'),
      '#required' => TRUE,
    );
  }

  // Payer SSN - only for USA.
  if ($address['country'] == 'US') {
    $form['payer_ssn'] = array(
      '#title' => t('SSN Number'),
      '#type' => 'textfield',
      '#description' => t('The Payer Social Security Number (SSN).'),
      '#required' => TRUE,
    );
  }

  $form['instruction'] = array(
    '#markup' => t($instruction, array(
      '!logo' => $logo,
      )
    ),
  );

  return $form;
}

/**
 * Payment method callback: submit form submission.
 */
function commerce_paytostudy_submit_form_submit($payment_method, $pane_form, $pane_values, $order, $charge) {
  $settings = $payment_method['settings'];
  $profile = commerce_customer_profile_load($order->commerce_customer_shipping[LANGUAGE_NONE][0]['profile_id']);
  $address = $profile->commerce_customer_address[LANGUAGE_NONE][0];
  $currency_code = $order->commerce_order_total[LANGUAGE_NONE][0]['currency_code'];
  $order_amount = commerce_currency_amount_to_decimal($order->commerce_order_total[LANGUAGE_NONE][0]['amount'], $currency_code);
  $request_timestamp = $order->created;

  $request = array();
  $request['paytostudy_post_request_url'] = isset($payment_method['settings']['paytostudy_post_request_url']) ? $payment_method['settings']['paytostudy_post_request_url'] : 'https://test-xml-service.studentfees.com/paymentservice.dl';
  $request['username_loginto'] = $payment_method['settings']['username_loginto'];
  $request['password_loginto'] = $payment_method['settings']['password_loginto'];
  $request['bank_account_id'] = $payment_method['settings']['bank_account_id'];
  $request['convertOnly'] = $payment_method['settings']['convertOnly'];
  $request['who_is_making_the_paymet'] = $pane_values['who_is_making_the_paymet'];
  $request['payer_name'] = isset($address['name_line']) ? $address['name_line'] : '';
  $request['student_name'] = isset($address['name_line']) ? $address['name_line'] : '';
  $request['external_unique_id'] = $request_timestamp . $order->order_number;
  $request['country_pay_from'] = isset($address['country']) ? drupal_strtolower($address['country']) : '';
  $request['home_address'] = isset($address['thoroughfare']) ? $address['thoroughfare'] : '' . isset($address['locality']) ? $address['locality'] : '' . isset($address['administrative_area']) ? $address['administrative_area'] : '';
  // India (foreign exchange limit).
  if ($address['country'] == 'IN') {
    $india_fee_exceed = $profile->field_foreign_exchange_limit[LANGUAGE_NONE][0]['value'];
    $request['india_fee_exceed'] = $india_fee_exceed;
  }

  // USA (SSN Number).
  if ($address['country'] == 'US') {
    $ssn_number = $pane_values['payer_ssn'];
    $request['payer_ssn'] = $ssn_number;
    $request['state'] = $address['country'] . '-' . $address['administrative_area'];
  }

  // Brazil (Payer CPF number).
  if ($address['country'] == 'BR') {
    $cpf_number = $pane_values['payer_cpf'];
    $request['payer_cpf'] = $cpf_number;
  }

  $request['email'] = $order->mail;
  $request['paying_for'] = $order->type;
  $request['payment_amount'] = $order_amount;
  $request['adi_id'] = $request_timestamp . $order->order_number;

  $phone_field_name = $payment_method['settings']['paytostudy_phone_field_name'];
  if(isset($profile->{$phone_field_name})) {
    $phone_number = $profile->{$phone_field_name}['und'][0]['value'];
    $request['phone_number'] = $phone_number;
  }
  else {
    // Get this field from billing profile.
    $billing_profile = commerce_customer_profile_load($order->commerce_customer_billing[LANGUAGE_NONE][0]['profile_id']);
    $phone_number = $billing_profile->{$phone_field_name}[LANGUAGE_NONE][0]['value'];
    $request['phone_number'] = $phone_number;
  }

  // Send the payment request.
  commerce_paytostudy_do_payment_request($payment_method, $request, $order);
}

/**
 * Do a payment authorization request.
 */
function commerce_paytostudy_do_payment_request($payment_method, $request, &$order) {
  // Send the request.
  $type = 'make-payment';
  $url = $request['paytostudy_post_request_url'];
  $post_data = _commerce_paytostudy_build_post_request($request, $type);
  $response = _commerce_paytostudy_send_request($url, $post_data);

  // If debug mode is enabled, log the request and response
   if($payment_method['settings']['debug_mode']) {
    watchdog('commerce_paytostudy', 'Request Data : <pre>' . print_r( $request, true) . '</pre>');
    watchdog('commerce_paytostudy', 'Response Data : <pre>' . print_r( $response, true) . '</pre>');
  }

  // Verify response.
  $success = _commerce_paytostudy_verify_response($type, $request, $response, $order, $payment_method);

  // Successful payment.
  if ($success) {
    // Save the transaction.
    $transaction = commerce_paytostudy_transaction($payment_method, $order, $response);
    $order->data['commerce_paytostudy']['transaction'] = $response;
  }
  // Payment failure.
  else {
    drupal_set_message(t('We were unable to process your request; reason provided by Pay to Study: %message. If the problem persists, contact us to complete your order.', array('%message' => $response['operation_errormessage'])), 'warning');
    watchdog('commerce_paytostudy', 'Payment failed: %message', array('%message' => $response['operation_errormessage']), WATCHDOG_WARNING);
    if (empty($_SESSION['paytostudy_failures'])) {
      $_SESSION['paytostud_failures'] = 0;
    }
    $_SESSION['paytostud_failures']++;
    drupal_goto('checkout');
  }
}

/**
 * Creates a payment transaction for the specified charge amount.
 */
function commerce_paytostudy_transaction($payment_method, $order, $response) {
  // Save the transaction
  $transaction = commerce_payment_transaction_new('commerce_paytostudy', $order->order_id);
  $transaction->amount = $order->commerce_order_total['und'][0]['amount'];
  $transaction->currency_code = $order->commerce_order_total['und'][0]['currency_code'];
  $transaction->remote_id = $response['transfer_referencenumber'];
  $transaction->message = '';
  $transaction->message_variables = array();
  foreach($response as $type => $value) {
    $type_name = $type;
    $type_name = str_replace('_', ' ', $type_name);
    $transaction->message .= ucwords($type_name) . ' - @' . $type . ', ';
    $transaction->message_variables['@' . $type] = $value;
  }
  trim($transaction->message);

  $transaction->instance_id = $payment_method['instance_id'];
  $transaction->status = COMMERCE_PAYMENT_STATUS_PENDING;
  commerce_payment_transaction_save($transaction);
  return $transaction;
}

/**
 * Returns a PaytoStudy logo.
 */
function _commerce_paytostudy_logo($logo_path) {
  $variables = array(
    'path' => $logo_path,
    'title' => t('Pay to Study'),
    'alt' => t('Pay to Study logo'),
    'attributes' => array(
      'class' => array('commerce-paytostudy-logo'),
    ),
  );
  $logo = theme('image', $variables);

  return $logo;
}

/**
 * Generate Post Data
 *
 * @param request
 *     An array with all the transaction data.
 */
function _commerce_paytostudy_build_post_request($request, $type) {
  switch ($type) {
    case 'make-payment':
      return _commerce_paytostudy_build_post_request_make_payment($request);
    case 'transaction-history':
      return _commerce_paytostudy_build_post_request_transaction_history($request);
  }
}

/**
 * Generate an "make-payment" post request.
 */
function _commerce_paytostudy_build_post_request_make_payment($request) {
  // generate the request_data array
  $request_data = $request;

  // Generate post string for payment request
  $post_array = array();
  $post_string_array = array();
  if (!is_array($request_data)) {
    return false;
  }

  $fields_string = '';
  foreach($request_data as $key=>$value) { $fields_string .= urlencode($key) .'='.urlencode($value).'&'; }
  rtrim($fields_string, '&');

  return $fields_string;
}

/**
 * Generate an "transaction-history" post request.
 */
function _commerce_paytostudy_build_post_request_transaction_history($request) {
  // generate the request_data array
  $request_data = array();
  $request_data['paytostudy_post_request_url'] = $request['paytostudy_post_request_url'];
  $request_data['password_loginto'] = $request['password_loginto'];
  $request_data['username_loginto'] = $request['username_loginto'];
  $request_data['paymentDetails_adi_id'] = $request['paymentDetails_adi_id'];
  $request_data['PaymentDetails'] = TRUE;

  // Generate post string for payment request
  $post_array = array();
  $post_string_array = array();
  if (!is_array($request_data)) {
    return false;
  }

  $fields_string = '';
  foreach($request_data as $key=>$value) { $fields_string .= urlencode($key) .'='.urlencode($value).'&'; }
  rtrim($fields_string, '&');

  return $fields_string;
}

/**
 * Process the PaytoStudy response.
 *
 * @param $type
 *   Message response type.
 * @param $response
 *   Parsed response as an array.
 * @param $request
 *   Transaction details array.
 * @param $order
 *   Commerce order object.
 * @param $payment_method
 *   Payment method array.
 */
function _commerce_paytostudy_verify_response($type, $request, &$response, $order, $payment_method) {
  if (!isset($response['operation_result'])) {
    watchdog('commerce_paytostudy', 'No results code, something has gone wrong with the transaction.', array(), WATCHDOG_ERROR);
    $response['user_message'] = 'No results code, something has gone wrong with the transaction';
    drupal_goto('checkout/' . $order->order_number . '/payment');
  }

  $success = FALSE;

  // Check for the operation result
  if ($response['operation_result'] != 'ok') {
    watchdog('commerce_paytostudy', 'Transaction request failed for order @order_id.', array('@order_id' => $order->order_number));
    $response['user_message'] = $response['operation_errormessage'];
  }
  else {
    $success = TRUE;
  }

  return $success;
}
