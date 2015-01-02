<?php
/**
 * @file
 * Rules hook implementations for the Commerce Partial Payment module.
 */

/**
 * Implements hook_rules_event_info().
 */
function commerce_partial_payment_rules_event_info() {
  return array(
    'commerce_partial_paryment_received' => array(
      'label' => t('After a partial payment has been recieved'),
      'group' => t('Commerce Partial Payment'),
      'variables' => array(
        'commerce_order' => array(
          'label' => t('Order'),
          'type' => 'commerce_order',
          'description' => t('The order that the payment was made against.'),
        ),
        'payment_amount' => array(
          'label' => t('Payment Amount'),
          'type' => 'commerce_price',
          'description' => t('The amount of the partial payment.'),
        ),
      ),
    ),
  );
}
