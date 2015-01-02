<?php

/**
 * @file
 * Rules integration for ULearn commerce module.
 */

/**
 * Implements hook_rules_action_info().
 */
function ulearn_commerce_rules_action_info() {
  return array(
    'ulearn_commerce_log_user_in' => array(
      'label' => 'Log in user',
      'parameter' => array(
        'account' => array('type' => 'user', 'label' => t('User')),
      ),
      'group' => t('System'),
    ),
    'ulearn_commerce_line_item_unit_price_add' => array(
      'label' => t('Add seasonal amount to the unit price'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line item'),
        ),
        'component_name' => array(
          'type' => 'text',
          'label' => t('Price component type'),
          'description' => t('Price components track changes to prices made during the price calculation process, and they are carried over from the unit price to the total price of a line item. When an order total is calculated, it combines all the components of every line item on the order. When the unit price is altered by this action, the selected type of price component will be added to its data array and reflected in the order total display when it is formatted with components showing. Defaults to base price, which displays as the order Subtotal.'),
          'options list' => 'ulearn_commerce_line_item_price_component_options_list',
          'default value' => 'base_price',
        ),
        'round_mode' => array(
          'type' => 'integer',
          'label' => t('Price rounding mode'),
          'description' => t('Round the resulting price amount after performing this operation.'),
          'options list' => 'commerce_round_mode_options_list',
          'default value' => COMMERCE_ROUND_HALF_UP,
        ),
      ),
      'group' => t('Commerce Line Item'),
    ),
  );
}

/**
 * Rules action callback to login the user provided in the function parameter.
 */
function ulearn_commerce_log_user_in($account) {
  // Log user in if allowed.
  if (variable_get('ulearn_commerce_enable_checkout_login', TRUE)) {
    global $user;
    $user = user_load($account->uid);
    user_login_finalize();
    // Redirect user to edit account page if allowed.
    if (variable_get('ulearn_commerce_redirect_user', TRUE)) {
      $url = 'user/' . $user->uid . '/edit';
      $force = TRUE;
      // We don't invoke drupal_goto() right now, as this would end the the current
      // page execution unpredictly for modules. So we'll take over drupal_goto()
      // calls from somewhere else via hook_drupal_goto_alter() and make sure
      // a drupal_goto() is invoked before the page is output with
      // rules_page_build().
      $GLOBALS['_rules_action_drupal_goto_do'] = array($url, $force);
    }
  }
}

/**
 * Rules action callback for adding seasonal amount to line item.
 */
function ulearn_commerce_line_item_unit_price_add($line_item, $component_name, $round_mode) {
  $amount = 0;
  $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
  $unit_price = commerce_price_wrapper_value($line_item_wrapper, 'commerce_unit_price', TRUE);

  if (isset($line_item_wrapper->commerce_product) && $line_item_wrapper->commerce_product->type->value() == 'course') {
    $product_id = $line_item_wrapper->commerce_product->product_id->value();
    $peak_enabled = $line_item_wrapper->commerce_product->field_course_in_peak_season->value();
    if ($peak_enabled) {
      $item_id = !empty($_SESSION['ulearn_course_selected_week'][$product_id]) ? $_SESSION['ulearn_course_selected_week'][$product_id] : NULL;
      // Get selected week.
      $week = !empty($_SESSION['ulearn_course_selected_week_option'][$product_id]) ? $_SESSION['ulearn_course_selected_week_option'][$product_id] : NULL;

      $item = field_collection_item_load($item_id);

      if (isset($item->item_id) && !empty($week)) {
        $start_date = $item->field_course_batch_start_date[LANGUAGE_NONE][0]['value'];
        // $start_date has format as YYYY-MM-DD 00:00:00. Get its timestamp.
        $start_date_timestamp = strtotime($start_date);

        $start_dates = array();
        $start_dates[] = $start_date_timestamp;
        for ($week_number = 1; $week_number <= $week; $week_number++) {
          // If week number is 1, we don't need to add more start dates
          // as we have already added that in array above.
          if ($week_number == 1) {
            continue;
          }
          $plus_week = $week_number - 1;
          $start_dates[] = strtotime('+' . $plus_week . ' weeks', $start_date_timestamp);
        }

        $courses_config = variable_get('ulearn_courses', array());
        $peak_season_config = !empty($courses_config['peak_season_fieldset']['peak_field_wrapper']) ? $courses_config['peak_season_fieldset']['peak_field_wrapper'] : array();
        foreach ($start_dates as $batch_date) {
          foreach ($peak_season_config as $k => $peak) {
            $peak_timestamp = strtotime($peak['peak_season_start_date']);
            if ($peak_timestamp == $batch_date) {
              $add_amount = !empty($peak['peak_season_amount']) ? $peak['peak_season_amount'] : 0;
              $amount += commerce_currency_decimal_to_amount($add_amount, $unit_price['currency_code'], FALSE);
            }
          }
        }
      }

      // Calculate the updated amount and create a price array representing the
      // difference between it and the current amount.
      $current_amount = $unit_price['amount'];
      $updated_amount = commerce_round($round_mode, $current_amount + $amount);

      $difference = array(
        'amount' => $updated_amount - $current_amount,
        'currency_code' => $unit_price['currency_code'],
        'data' => array(),
      );

      // Set the amount of the unit price and add the difference as a component.
      $line_item_wrapper->commerce_unit_price->amount = $updated_amount;

      $line_item_wrapper->commerce_unit_price->data = commerce_price_component_add(
        $line_item_wrapper->commerce_unit_price->value(),
        $component_name,
        $difference,
        TRUE
      );
    }
  }
}

/**
 * Options list callback: price component selection list.
 */
function ulearn_commerce_line_item_price_component_options_list() {
  return commerce_price_component_titles();
}
