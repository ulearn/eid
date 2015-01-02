<?php
/**
 * @file
 * ulearn_special_courses.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulearn_special_courses_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'commerce_line_item-special_courses-field_batch_start_date'
  $field_instances['commerce_line_item-special_courses-field_batch_start_date'] = array(
    'bundle' => 'special_courses',
    'commerce_cart_settings' => array(
      'field_access' => 1,
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'field_formatter_label' => '',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_batch_start_date',
    'label' => 'Batch start date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'l, F j, Y',
        'input_format_custom' => '',
        'label_position' => 'none',
        'text_parts' => array(),
        'year_range' => '-0:+5',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'commerce_product-special_course-field_course_registration'
  $field_instances['commerce_product-special_course-field_course_registration'] = array(
    'bundle' => 'special_course',
    'default_value' => array(
      0 => array(
        'registration_type' => 'ulearn_course_registration',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_course_registration',
    'label' => 'Registration',
    'required' => 0,
    'settings' => array(
      'default_registration_settings' => array(
        'capacity' => 0,
        'reminder' => array(
          'reminder_settings' => array(
            'reminder_date' => NULL,
            'reminder_template' => '',
          ),
          'send_reminder' => 0,
        ),
        'scheduling' => array(
          'close' => NULL,
          'open' => NULL,
        ),
        'settings' => array(
          'from_address' => 'info@ulearnschool.com',
          'maximum_spaces' => 1,
          'multiple_registrations' => 0,
        ),
        'status' => 1,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'registration',
      'settings' => array(),
      'type' => 'registration_select',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'commerce_product-special_course-field_course_weeks'
  $field_instances['commerce_product-special_course-field_course_weeks'] = array(
    'bundle' => 'special_course',
    'default_value' => array(
      0 => array(
        'set_id' => 'week_options',
        'set_details' => array(
          'field_course_week_options' => array(
            'default' => '',
            'enabled' => 1,
            'options' => array(
              1 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 1,
              ),
              2 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 2,
              ),
              3 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 3,
              ),
              4 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 4,
              ),
              5 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 5,
              ),
              6 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 6,
              ),
              7 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 7,
              ),
              8 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 8,
              ),
              9 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 9,
              ),
              10 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 10,
              ),
              11 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 11,
              ),
              12 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 12,
              ),
              13 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 13,
              ),
              14 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 14,
              ),
              15 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 15,
              ),
              16 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 16,
              ),
              17 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 17,
              ),
              18 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 18,
              ),
              19 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 19,
              ),
              20 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 20,
              ),
              21 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 21,
              ),
              22 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 22,
              ),
              23 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 23,
              ),
              24 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 24,
              ),
              25 => array(
                'calculate' => 'per_item',
                'currency_code' => 'USD',
                'enabled' => 1,
                'price' => 0,
                'price_op' => 'plus',
                'weight' => 25,
              ),
            ),
            'required' => 1,
          ),
        ),
      ),
    ),
    'default_value_function' => 'field_default_token_default_value_function',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'commerce_pricing_attributes',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'commerce_pricing_attributes_form',
        'weight' => 4,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_course_weeks',
    'label' => 'Weeks',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'commerce_pricing_attributes',
      'settings' => array(),
      'type' => 'commerce_pricing_attributes_custom_widget',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-special_course-body'
  $field_instances['node-special_course-body'] = array(
    'bundle' => 'special_course',
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
        'weight' => 2,
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
    'label' => 'Description',
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
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-special_course-field_course_display_picture'
  $field_instances['node-special_course-field_course_display_picture'] = array(
    'bundle' => 'special_course',
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
        'module' => 'image',
        'settings' => array(
          'field_formatter_label' => '',
          'image_link' => '',
          'image_style' => 'adaptive_thumbnail',
        ),
        'type' => 'image',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_course_display_picture',
    'label' => 'Picture',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'courses',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'adaptive_thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-special_course-field_course_unique_id'
  $field_instances['node-special_course-field_course_unique_id'] = array(
    'bundle' => 'special_course',
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
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'field_formatter_label' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_course_unique_id',
    'label' => 'Course ID',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 20,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-special_course-field_special_course_reference'
  $field_instances['node-special_course-field_special_course_reference'] = array(
    'bundle' => 'special_course',
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
          'combine' => 1,
          'default_quantity' => 1,
          'field_formatter_label' => '',
          'line_item_type' => 'special_courses',
          'show_quantity' => 0,
          'show_single_product_attributes' => 0,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_special_course_reference',
    'label' => 'Special course reference',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'accommodation' => 0,
        'course' => 0,
        'materials' => 0,
        'product' => 0,
        'special_course' => 'special_course',
        'transport' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => FALSE,
          'autogenerate_title' => 1,
          'delete_references' => 0,
          'label_plural' => 'products',
          'label_singular' => 'product',
          'match_operator' => 'CONTAINS',
          'override_labels' => 0,
        ),
      ),
      'type' => 'inline_entity_form_single',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Batch start date');
  t('Course ID');
  t('Description');
  t('Picture');
  t('Registration');
  t('Special course reference');
  t('Weeks');

  return $field_instances;
}
