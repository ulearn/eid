<?php

/**
 * Field handler to return payment instructions.
 */
class ulearn_commerce_payment_instructions extends views_handler_field {

  function construct() {
    parent::construct();

    $this->additional_fields['order_id'] = 'order_id';
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Load the order.
    $order_id = $this->get_value($values, 'order_id');
    $order = commerce_order_load($order_id);

    if (!empty($order->data['payment_method'])) {
      // Get the payment method instance.
      $payment_method = commerce_payment_method_instance_load($order->data['payment_method']);
      $method_id = $payment_method['method_id'];

      // Get payment transaction.
      $transactions =  commerce_payment_transaction_load_multiple(array(), array('order_id' => $order_id, 'payment_method' => $method_id));
      $transaction = reset($transactions);
      // Render only for pending transaction.
      if ($transaction->status == 'pending') {
        $message_variables = ulearn_commerce_payment_transaction_message_variables($method_id, $order);
        // Get configured payment instructions.
        if ($method_id == 'commerce_paytostudy') {
          $replace = ulearn_commerce_paytostudy_payment_instructions($order, $message_variables);
        }
        else {
          $instructions = variable_get_value('ulearn_commerce_payment_instructions_' . $method_id);
          // Replace if there are any tokens for order.
          $replace = token_replace($instructions['value'], array('commerce-order' => $order), array('clear' => TRUE));
          $replace = t($replace, $message_variables);
        }
        return $replace;
      }
    }
  }
}
