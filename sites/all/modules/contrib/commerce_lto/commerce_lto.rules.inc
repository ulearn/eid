<?php
/**
 * @file
 * Define the rules to calculate the price for a product with period based
 * prices.
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_lto_rules_action_info() {
  $actions = array();

  $actions['commerce_lto_calculate_product_price'] = array(
    'label' => t('Calculates a limited time price.'),
    'parameter' => array(
      'commerce_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Commerce Line Item'),
      ),
      'commerce_lto_field' => array(
        'type' => 'text',
        'label' => t('Commerce price field with date support to use'),
        'options list' => 'commerce_lto_get_enabled_price_fields',
        'optional' => TRUE,
        'default value' => 'default',
      ),
    ),
    'group' => t('Commerce Limited Time Offers'),
  );
  return $actions;
}

/**
 * Calculates the limited time price.
 */
function commerce_lto_calculate_product_price($line_item, $commerce_lto_field = 'default') {
  $wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);

  // If no price field is set - try to fetch the default.
  if ($commerce_lto_field == 'default') {
    $fields = commerce_lto_get_enabled_price_fields();
    if (!($commerce_lto_field = reset($fields))) {
      // If no default field is available - skip.
      return;
    }
  }

  // If there's no field set on the line item - use the defined field defaults.
  if (empty($line_item->commerce_lto_date_range)) {
    if ($field_instance = field_info_instance('commerce_line_item', 'commerce_lto_date_range', $line_item->type)) {
      $field = field_info_field('commerce_lto_date_range');

      module_load_include('inc', 'date_api', 'date_api_elements');
      $timezone = date_get_timezone($field['settings']['tz_handling'], date_default_timezone());
      if (is_array($timezone)) {
        $timezone = $timezone['timezone'];
      }

      $start_date = date_local_date(array(), array(), 0, array('value' => ''), $timezone, $field, $field_instance, 'value');
      $end_date = date_local_date(array(), array(), 0, array('value2' => ''), $timezone, $field, $field_instance, 'value2');
      $date_format = DATE_FORMAT_DATE;
      if (count(array_intersect(array('hour', 'minute', 'second'), $field['settings']['granularity']))) {
        $date_format = DATE_FORMAT_DATETIME;
      }
      $line_item->commerce_lto_date_range[LANGUAGE_NONE][0]['value'] = $start_date->format($date_format);
      $line_item->commerce_lto_date_range[LANGUAGE_NONE][0]['value2'] = $end_date->format($date_format);
    }
    else {
      return;
    }
  }

  $date_range = $wrapper->commerce_lto_date_range->value();
  $start_date = new DateTime($date_range['value'], new DateTimeZone('UTC'));
  $end_date = new DateTime($date_range['value2'], new DateTimeZone('UTC'));
  $date_based_price = commerce_lto_calculate_price($wrapper->commerce_product->value(), $commerce_lto_field, $start_date, $end_date);
  if (!$date_based_price) {
    $date_based_price['amount'] = 0;
  }
  $date_based_price['currency_code'] = $wrapper->commerce_unit_price->currency_code->value();


  // Set the amount of the unit price.
  $wrapper->commerce_unit_price = $date_based_price;

  $wrapper->commerce_unit_price->data = commerce_price_component_add(
    $wrapper->commerce_unit_price->value(),
    'base_price',
    $date_based_price,
    TRUE
  );
}
