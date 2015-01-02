<?php
/**
 * @file
 * Default rules hook implementations for the Commerce Partial Payment module.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_partial_payment_default_rules_configuration() {
  $rules = array();

  // Add a reaction rule to update an order to the default status of the partial
  // payment received after completing checkout with an order that still has a
  // balance.
  $rule = rules_reaction_rule();

  $rule->label = t('Update the order status on checkout completion with a partial payment');
  $rule->active = TRUE;

  $rule
    ->event('commerce_checkout_complete')
    ->condition(
      'commerce_payment_order_balance_comparison',
      array(
        'data:select' => 'commerce_order',
        'operator' => '>',
        'value' => 0,
      )
    )
    ->action(
      'commerce_order_update_status',
      array(
        'commerce_order:select' => 'commerce-order',
        'order_status' => 'partial_payment',
      )
    );

  $rules['commerce_partial_payment_order_status_update'] = $rule;

  return $rules;
}

/**
 * Implements hook_default_rules_configuration_alter().
 *
 * Modify the default order status update rule to make sure the order's balane
 * is zero before changing its status.
 */
function commerce_partial_payment_default_rules_configuration_alter(&$rules) {
  if (isset($rules['commerce_checkout_order_status_update'])) {
    $rules['commerce_checkout_order_status_update']->condition(
      'commerce_payment_order_balance_comparison',
      array(
        'data:select' => 'commerce_order',
        'operator' => '<=',
        'value' => 0,
      )
    );
  }
}
