<?php
/**
 * @file
 * Commerce hook implementations for the Commerce Partial Payment module.
 */

/**
 * Implements hook_commerce_checkout_pane_info_alter().
 *
 * Override callbacks for some checkout panes that pertain to order payment and
 * completion.
 */
function commerce_partial_payment_commerce_checkout_pane_info_alter(&$checkout_panes) {
  // Override the validate and submit handlers for the commerce_payment pane so
  // that we can validate the amount and pass it into the payment method
  // callback.
  $checkout_panes['commerce_payment']['callbacks']['checkout_form_validate'] = 'commerce_partial_payment_checkout_validate';
  $checkout_panes['commerce_payment']['callbacks']['checkout_form_submit'] = 'commerce_partial_payment_checkout_submit';

  // Over the form callback for the checkout_completion_message pane so that we
  // can show a different message if they made a partial payment that did not
  // complete payment for the order.
  $checkout_panes['checkout_completion_message']['callbacks']['checkout_form'] = 'commerce_partial_payment_message_form';
}

/**
 * Implements hook_commerce_order_status_info().
 *
 * Adds a cart status for orders with partial payments.
 */
function commerce_partial_payment_commerce_order_status_info() {
  return array(
    'partial_payment' => array(
      'name' => 'partial_payment',
      'title' => t('Partial payment received'),
      'state' => 'pending',
      'cart' => TRUE,
    ),
  );
}
