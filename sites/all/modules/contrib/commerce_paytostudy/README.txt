Provides a PayToStudy payment method for Drupal Commerce.

Installation :

Install as any other module and add the Enable the payment method
in commerce payment rules. Do the required settings for payment processor.

To fetch the transaction details of specific order :

// Send the request.
$type = 'transaction-history';
module_load_include('inc', 'commerce_paytostudy', 'commerce_paytostudy');
$request = array(
  'paytostudy_post_request_url' => $payment_method['settings']['paytostudy_post_request_url'],
  'password_loginto' => $payment_method['settings']['password_loginto']',
  'username_loginto' => $payment_method['settings']['username_loginto'],
  'paymentDetails_adi_id' => $order->created . $order->order_number
);
$post_data = _commerce_paytostudy_build_post_request($request, $type);
$response = _commerce_paytostudy_send_request($payment_method['settings']['paytostudy_post_request_url'], $post_data);
