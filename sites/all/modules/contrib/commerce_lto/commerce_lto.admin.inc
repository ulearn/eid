<?php
/**
 * @file
 * Administrative UI for commerce limited time offers.
 */

/**
 * Form to configure limited time offers.
 *
 * @param $form
 * @param $form_state
 */
function commerce_lto_settings_form($form, &$form_state) {

  $enabled_fields = variable_get('commerce_lto_enabled_fields', array());

  $form['caching'] = array(
    '#title' => t('Caching'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['caching']['commerce_lto_enable_cache'] = array(
    '#title' => t('Enable dedicated price cache.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('commerce_lto_enable_cache', TRUE),
  );

  $expiration_setting = variable_get('commerce_lto_cache_expiration', 'tomorrow');
  $form['caching']['commerce_lto_cache_expiration'] = array(
    '#title' => t('Defines the expiration timing of the cache'),
    '#description' => t('Define a <a href="http://www.php.net/manual/en/datetime.formats.relative.php">relative date</a> to set the expiration time of the cache items.'),
    '#type' => 'textfield',
    '#default_value' => $expiration_setting,
    '#states' => array(
      'visible' => array(
        '#edit-commerce-price-periods-enable-cache' => array('checked' => TRUE),
      ),
    ),
    '#field_suffix' => t(
      '%now modified with %expiration_setting is %then',
      array(
        '%now' => date(DATE_FORMAT_DATETIME),
        '%expiration_setting' => $expiration_setting,
        '%then' => date(DATE_FORMAT_DATETIME, strtotime($expiration_setting)),
      )
    ),
  );

  $form['price_period_fields'] = array(
    '#title' => t('Enable limited time pricing for these price fields'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $price_fields = commerce_info_fields('commerce_price', 'commerce_product');
  foreach ($price_fields as $field_name => $field_info) {
    $form['price_period_fields'][$field_name] = array(
      '#title' => $field_name,
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['price_period_fields'][$field_name]['time_unit_handling'] = array(
      '#title' => t('Time unit handling'),
      '#type' => 'checkbox',
      '#default_value' => (int) (!empty($enabled_fields[$field_name]['time_unit_handling'])),
    );
    $form['price_period_fields'][$field_name]['period_handling'] = array(
      '#title' => t('Price period handling'),
      '#type' => 'checkbox',
      '#default_value' => (int) (!empty($enabled_fields[$field_name]['period_handling'])),
    );
    $form['price_period_fields'][$field_name]['use_now_as_date'] = array(
      '#title' => t('Use current date for calculation'),
      '#description' => t('If enabled there\'s no date range selection for the user and the price that matches to the current date is used.'),
      '#type' => 'checkbox',
      '#return_value' => 1,
      '#default_value' => (!empty($enabled_fields[$field_name]['use_now_as_date'])),
      '#states' => array(
        'visible' => array(
          '#edit-price-period-fields input[name="price_period_fields[' . $field_name . '][period_handling]"]' => array('checked' => TRUE),
          '#edit-price-period-fields input[name="price_period_fields[' . $field_name . '][time_unit_handling]"]' => array('checked' => FALSE),
        ),
      ),
    );

    // Allow to set cardinality on this field
    // @TODO Before enabling this again make sure it has really no sideeffects
    // if ($field_name == 'commerce_price') {
    //   $form['price_period_fields'][$field_name]['commerce_lto_force_cardinality'] = array(
    //     '#title' => t('Set cardinality to unlimited on this field.'),
    //     '#description' => t('Since this field is locked you can force the cardinality here.'),
    //     '#type' => 'checkbox',
    //     '#default_value' => (int) ($field_info['cardinality'] == -1),
    //     '#tree' => FALSE,
    //    );
    // }
  }

  // @TODO Possibility to configure available time units.

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save Settings'),
  );

  return $form;
}

/**
 * Submit handler for the conversion settings form.
 * @param $form
 * @param $form_state
 */
function commerce_lto_settings_form_submit($form, &$form_state) {
  $enabled_fields = $form_state['values']['price_period_fields'];
  foreach ($enabled_fields as $field_name => $values) {
    if (!count(array_filter($values))) {
      unset($enabled_fields[$field_name]);
    }
  }
  variable_set('commerce_lto_enabled_fields', $enabled_fields);

  variable_set(
    'commerce_lto_enable_cache',
    $form_state['values']['commerce_lto_enable_cache']
  );
  variable_set(
    'commerce_lto_cache_expiration',
    $form_state['values']['commerce_lto_cache_expiration']
  );


  if (!empty($form_state['values']['commerce_lto_force_cardinality'])) {
    $field_info = field_info_field('commerce_price');
    $field_info['cardinality'] = -1;
    field_update_field($field_info);
    variable_set('commerce_lto_force_cardinality', TRUE);
  }
  else {
    if (variable_get('commerce_lto_force_cardinality', FALSE)) {
      $field_info = field_info_field('commerce_price');
      $field_info['cardinality'] = 1;
      field_update_field($field_info);
    }
    variable_set('commerce_lto_force_cardinality', FALSE);
  }

  // Ensure the necessary field on the line items is available.
  if ($enabled_fields) {
    commerce_lto_create_line_item_date_field();
  }
}
