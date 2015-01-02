<?php
/**
 * @file
 * API documentation for the Commerce Partial Payment module.
 */

/**
 * Allows other modules to determine if a user may make a partial payment for an
 * order.
 *
 * This hook will only be invoked if the user has already passed the "make
 * partial payments" permission check. If any implementation returns FALSE the
 * user will be deined access. Implementations of this hook should return one of
 * three values:
 * - TRUE: The user should be granted access.
 * - FALSE: The user should not be granted access.
 * - NULL (or nothing): The current hook implementation has no opiniion in
 *   whether or not the user should be allowed access.
 *
 * @param stdClass $order
 *   Commerce order entity that the payment would be applied to.
 *
 * @return boolean
 *   Whether or not the user may make a partial payment for the order.
 */
function hook_commerce_partial_payment_access($order) {
  return user_access('make partial payments');
}

/**
 * Notifies other modules when a partial payment has been applied to an order.
 *
 * This hook will only fire if the payment is sucesfull. If the payment fails,
 * e.g. credit card is denied, then this hook will not be invoked.
 *
 * @param stdClass $order
 *   The order that the payment was applied to.
 * @param array $amount
 *   The amount of the partial payment, formatted as a commerce_price away.
 */
function hook_commerce_partial_paryment_received($order, $amount) {
  drupal_set_message(t(
    'Payment in the amount of !amount applied to order !order.',
    array(
      '!amount' => commerce_currency_format($amount['amount'], $amount['currency_code']),
      '!order' => $order->order_id,
    )
  ));
}
