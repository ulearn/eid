<?php

/**
 * Views integration for ULearn Course module.
 */

/**
 * Implements hook_views_data()
 */
function ulearn_course_views_data() {
  $data = array();

  // Expose line item share amount.
  $data['commerce_line_item']['ulearn_course_share_amount'] = array(
    'title' => t('ULearn Amount'),
    'help' => t('Calculated amount for ULearn share.'),
    'field' => array(
      'title' => t('ULearn share amount'),
      'help' => t('ULearn share amount for line item.'),
      'handler' => 'ulearn_course_line_item_share_amount',
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
function ulearn_course_views_query_alter(&$view, &$query) {
  // Commerce registration uses alias as commerce_registration_order for
  // commerce_order table. After adding relationship 'Representative payment
  // transaction', it gives SQL error as unknown coloumn commerce_order.order_id
  // for the subquery. We are updating this thing here so we can properly use
  // that relationship with commerce registration.
  if (module_exists('commerce_registration') && !empty($query->table_queue['commerce_payment_transaction_commerce_order']['join']->left_query)) {
    $left_query = $query->table_queue['commerce_payment_transaction_commerce_order']['join']->left_query;
    $query->table_queue['commerce_payment_transaction_commerce_order']['join']->left_query = str_replace('commerce_order.order_id', 'commerce_order_registration.order_id', $left_query);
  }
}
