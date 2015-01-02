<?php
/**
* @file
* Define a default rule to manage limited time princing.
*/

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_lto_default_rules_configuration() {
  $rules = array();

  $reaction_rule = rules_reaction_rule();
  $reaction_rule->label = 'Commerce Limited Time Offers - Price Calculation';
  $reaction_rule
  ->event('commerce_product_calculate_sell_price')
  ->action('commerce_lto_calculate_product_price', array(
    'commerce_line_item:select' => 'commerce-line-item',
  ));
  $reaction_rule->weight = -1;
  $reaction_rule->active = count(commerce_lto_get_enabled_price_fields()) > 0;
  $rules['commerce_lto_calculate_product_price'] = $reaction_rule;

  return $rules;
}
