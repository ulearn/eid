<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_google_analytics_rules_action_info() {
  return array(
    // Add rules action which sends the analytics code
    'commerce_google_analytics_send_order' => array(
      'label' => t('Send order to google analytics'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Order in checkout'),
        ),
        'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'description' => t("Select ga_push method. Server-side methods are recommended"),
          'options list' => 'ga_push_get_methods_option_list_ecommerce',
          'default value' => GA_PUSH_METHOD_DEFAULT,
          'optional' => FALSE,
        ),
      ),
      'callback' => array(
        'execute' => 'commerce_google_analytics_send_order'
      ),
    ),
  );
}