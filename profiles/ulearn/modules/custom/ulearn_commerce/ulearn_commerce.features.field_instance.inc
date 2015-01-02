<?php
/**
 * @file
 * ulearn_commerce.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulearn_commerce_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'commerce_customer_profile-billing-commerce_customer_address'
  $field_instances['commerce_customer_profile-billing-commerce_customer_address'] = array(
    'bundle' => 'billing',
    'default_value' => array(
      0 => array(
        'element_key' => 'commerce_customer_profile|billing|commerce_customer_address|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'locality' => '',
        'administrative_area' => '',
        'postal_code' => '',
        'country' => 'GB',
        'first_name' => '',
        'last_name' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'administrator' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'field_formatter_label' => '',
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'customer' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'field_formatter_label' => '',
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'field_formatter_label' => '',
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'commerce_customer_address',
    'label' => 'Address',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'format_handlers' => array(
          'address' => 'address',
          'name-full' => 'name-full',
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'commerce_customer_profile-billing-field_foreign_exchange_limit'
  $field_instances['commerce_customer_profile-billing-field_foreign_exchange_limit'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'default_value_label_token' => 0,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'field_foreign_exchange_limit',
    'label' => 'Will you exceed the US$25,000 foreign exchange limit in the calender year 01 April - 31 March',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'commerce_customer_profile-billing-field_terms_and_conditins'
  $field_instances['commerce_customer_profile-billing-field_terms_and_conditins'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'default_value_label_token' => 0,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'field_terms_and_conditins',
    'label' => 'Terms and conditions',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'commerce_customer_profile-billing-field_user_phone'
  $field_instances['commerce_customer_profile-billing-field_user_phone'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_plain',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'field_user_phone',
    'label' => 'Phone number',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '',
      ),
      'type' => 'telephone_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'commerce_option-week_options-field_course_week_options'
  $field_instances['commerce_option-week_options-field_course_week_options'] = array(
    'bundle' => 'week_options',
    'default_value' => NULL,
    'default_value_label_token' => 0,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_option',
    'field_name' => 'field_course_week_options',
    'label' => 'Weeks',
    'required' => 0,
    'settings' => array(
      'commerce_pricing_attributes' => array(
        1 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 1,
        ),
        2 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 2,
        ),
        3 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 3,
        ),
        4 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 4,
        ),
        5 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 5,
        ),
        6 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 6,
        ),
        7 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 7,
        ),
        8 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 8,
        ),
        9 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 9,
        ),
        10 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 10,
        ),
        11 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 11,
        ),
        12 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 12,
        ),
        13 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 13,
        ),
        14 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 14,
        ),
        15 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 15,
        ),
        16 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 16,
        ),
        17 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 17,
        ),
        18 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 18,
        ),
        19 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 19,
        ),
        20 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 20,
        ),
        21 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 21,
        ),
        22 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 22,
        ),
        23 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 23,
        ),
        24 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 24,
        ),
        25 => array(
          'calculate' => 'per_item',
          'currency_code' => 'EUR',
          'enabled' => 1,
          'price' => 0,
          'price_op' => 'plus',
          'weight' => 25,
        ),
        '_none' => array(
          'weight' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'commerce_product-accommodation-commerce_price'
  $field_instances['commerce_product-accommodation-commerce_price'] = array(
    'bundle' => 'accommodation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'commerce_line_item_diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'commerce_line_item_display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_components',
        'weight' => 0,
      ),
      'diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_rss' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_index' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_result' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'commerce_price',
    'label' => 'Price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'commerce_product-materials-commerce_price'
  $field_instances['commerce_product-materials-commerce_price'] = array(
    'bundle' => 'materials',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'commerce_line_item_diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'commerce_line_item_display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_components',
        'weight' => 0,
      ),
      'diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_rss' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_index' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_result' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'commerce_price',
    'label' => 'Price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'commerce_product-transport-commerce_price'
  $field_instances['commerce_product-transport-commerce_price'] = array(
    'bundle' => 'transport',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'commerce_line_item_diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'commerce_line_item_display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_components',
        'weight' => 0,
      ),
      'diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_diff_standard' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_rss' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_index' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_search_result' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'commerce_price',
    'label' => 'Price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-product_display-body'
  $field_instances['node-product_display-body'] = array(
    'bundle' => 'product_display',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkout_pane' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-product_display-field_order'
  $field_instances['node-product_display-field_order'] = array(
    'bundle' => 'product_display',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkout_pane' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_formatter_label' => '',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_order',
    'label' => 'Order',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-product_display-field_product_reference'
  $field_instances['node-product_display-field_product_reference'] = array(
    'bundle' => 'product_display',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkout_pane' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'field_formatter_label' => '',
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_reference',
    'label' => 'Product reference',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'accommodation' => 'accommodation',
        'course' => 0,
        'materials' => 'materials',
        'product' => 0,
        'transport' => 'transport',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'commerce_product/autocomplete',
        'fields' => array(),
        'size' => 60,
        'type_settings' => array(),
      ),
      'type' => 'inline_entity_form',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Body');
  t('Order');
  t('Phone number');
  t('Price');
  t('Product reference');
  t('Terms and conditions');
  t('Weeks');
  t('Will you exceed the US$25,000 foreign exchange limit in the calender year 01 April - 31 March');

  return $field_instances;
}
