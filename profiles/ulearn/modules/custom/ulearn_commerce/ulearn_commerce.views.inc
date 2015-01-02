<?php

/**
 * Views integration for ULearn Course module.
 */

/**
 * Implements hook_views_data()
 */
function ulearn_commerce_views_data() {
  $data = array();

  // Expose payment instructions for order.
  $data['commerce_order']['ulearn_commerce_payment_instructions'] = array(
    'title' => t('Payment instructions'),
    'help' => t('Payment instructions configured for each payment method.'),
    'field' => array(
      'title' => t('Payment instructions'),
      'help' => t('Payment instructions configured for each payment method.'),
      'handler' => 'ulearn_commerce_payment_instructions',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_query_alter().
 */
function ulearn_commerce_views_query_alter(&$view, &$query) {
  if ($view->name == 'registration_display') {
    // Add condition for commerce product id to display proper course data
    // on registration display page.
    // Get the first argument that is registration_id.
    // TODO Check if there is any other way where we can get this value using
    // views api instead of getting it directly from view object.
    $registration_id = $view->args[0];
    $registration = registration_load($registration_id);
    if (isset($registration->registration_id)) {
      $product_id = $registration->entity_id;
      $group = empty($query->options['group']) ? $query->options['group'] : 0;
      // Add where clause in views query object for product id.
      $query->add_where($group, 'commerce_product_field_data_commerce_product.product_id', $product_id, '=');
    }
  }
}
