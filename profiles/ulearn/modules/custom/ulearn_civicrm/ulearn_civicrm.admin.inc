<?php

/**
 * @file
 * Administrative forms and callbacks for Ulearn CiviCRM module.
 */

/**
 * CiviCRM settings form for ULearn.
 */
function ulearn_civicrm_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['ulearn_civicrm_markup'] = array(
    '#markup' => t('Configure CiviCRM parameters that will be used to create contributions, membership and activity after course registration. Make sure you have also configured Commerce CiviCRM module <a href="@href">here</a>.', array('@href' => url('admin/commerce/config/civicrm'))),
  );

  // Product types.
  $form['ulearn_civicrm_products'] = array(
    '#type' => 'fieldset',
    '#title' => t('Product types'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $product_types = variable_get('ulearn_civicrm_product_types', array('accommodation' => 'accommodation', 'course' => 'course'));

  // Product types for creating contributions.
  $form['ulearn_civicrm_products']['ulearn_civicrm_product_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Product types for contributions'),
    '#options' => ulearn_commerce_available_product_types(),
    '#default_value' => $product_types,
    '#description' => t('Select product types for which contribution will be created after registration. Separate contribution will be created for each product type.'),
    '#ajax' => array(
      'callback' => 'ulearn_civicrm_update_product_options',
    ),
  );

  $membership_product_types = !empty($form_state['values']['ulearn_civicrm_product_types']) ? ulearn_civicrm_membership_product_types_options($form_state['values']['ulearn_civicrm_product_types']) : ulearn_civicrm_membership_product_types_options($product_types);

  // Product types for creating memberships.
  $form['ulearn_civicrm_products']['ulearn_civicrm_membership_product_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Product types for memberships'),
    '#options' => $membership_product_types,
    '#default_value' => variable_get('ulearn_civicrm_membership_product_types', array('course' => 'course', 'accommodation' => 'accommodation')),
    '#description' => t('Select product types for which membership will be created after registration. Separate membership will be created for each product type..'),
    '#prefix' => '<div class="ulearn-civicrm-replace-product-types">',
    '#suffix' => '</div>',
  );

  if (civicrm_initialize()) {

    // Other parameters.
    $form['ulearn_civicrm_params'] = array(
      '#type' => 'fieldset',
      '#title' => t('Other parameters'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    // Contribution.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_contribution'] = array(
      '#type' => 'fieldset',
      '#title' => t('Contribution'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    // Mapping: Commerce order status <-> Contribution status.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_contribution']['ulearn_civicrm_status_mapping'] = array(
      '#type' => 'fieldset',
      '#title' => t('Contribution status mapping'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $contribution_statuses = ulearn_civicrm_options('contribution_status');
    foreach (commerce_order_state_get_title() as $order_state => $state_title) {
      $form['ulearn_civicrm_params']['ulearn_civicrm_params_contribution']['ulearn_civicrm_status_mapping']['ulearn_civicrm_status_mapping_order_state_' . $order_state] = array(
        '#type' => 'select',
        '#title' => t('Order state: %state', array('%state' => $state_title)),
        '#options' => $contribution_statuses,
        '#default_value' => variable_get('ulearn_civicrm_status_mapping_order_state_' . $order_state, 1),
      );
    }

    // Mapping: Commerce payment method <-> Payment instrument.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_contribution']['ulearn_civicrm_payment_mapping'] = array(
      '#type' => 'fieldset',
      '#title' => t('Payment instrument mapping'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $payment_instruments = ulearn_civicrm_options('payment_instrument');
    foreach (ulearn_commerce_payment_method_options() as $method_id => $method_title) {
      $form['ulearn_civicrm_params']['ulearn_civicrm_params_contribution']['ulearn_civicrm_payment_mapping']['ulearn_civicrm_payment_mapping_payment_method_' . $method_id] = array(
        '#type' => 'select',
        '#title' => t('Payment method: %method', array('%method' => $method_title)),
        '#options' => $payment_instruments,
        '#default_value' => variable_get('ulearn_civicrm_payment_mapping_payment_method_' . $method_id, 6),
      );
    }

    // Membership.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_membership'] = array(
      '#type' => 'fieldset',
      '#title' => t('Membership'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    // Membership type.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_membership']['ulearn_civicrm_membership_type'] = array(
      '#type' => 'select',
      '#title' => t('Membership type'),
      '#options' => ulearn_civicrm_membership_types(),
      '#default_value' => variable_get('ulearn_civicrm_membership_type', 2),
      '#description' => t('Select membership type that will be used to create membership.'),
    );

    // Membership status.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_membership']['ulearn_civicrm_membership_status'] = array(
      '#type' => 'select',
      '#title' => t('Membership status'),
      '#options' => ulearn_civicrm_membership_statuses(),
      '#default_value' => variable_get('ulearn_civicrm_membership_status', 2),
      '#description' => t('Select membership status that will be used to create membership.'),
    );

    // Activity.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_activity'] = array(
      '#type' => 'fieldset',
      '#title' => t('Activity'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    // Activity type.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_activity']['ulearn_civicrm_activity_type'] = array(
      '#type' => 'select',
      '#title' => t('Activity type'),
      '#options' => ulearn_civicrm_activity_types(),
      '#default_value' => variable_get('ulearn_civicrm_activity_type', 2),
      '#description' => t('Select type of activity that will be created after registering for course.'),
    );

    // Activity status.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_activity']['ulearn_civicrm_activity_status'] = array(
      '#type' => 'select',
      '#title' => t('Activity status'),
      '#options' => ulearn_civicrm_options('activity_status'),
      '#default_value' => variable_get('ulearn_civicrm_activity_status', 1),
      '#description' => t('Select activity status used for created activity.'),
    );
    // Activity priority.
    $form['ulearn_civicrm_params']['ulearn_civicrm_params_activity']['ulearn_civicrm_activity_priority'] = array(
      '#type' => 'select',
      '#title' => t('Activity priority'),
      '#options' => CRM_Core_PseudoConstant::get('CRM_Activity_DAO_Activity', 'priority_id'),
      '#default_value' => variable_get('ulearn_civicrm_activity_priority', 2),
      '#description' => t('Select activity priority used for created activity.'),
    );
  }

  return system_settings_form($form);
}

/**
 * Ajax callback to update product options.
 */
function ulearn_civicrm_update_product_options($form, $form_state) {
  $product_types = $form_state['values']['ulearn_civicrm_product_types'];
  $element = $form['ulearn_civicrm_products']['ulearn_civicrm_membership_product_types'];
  $element['#options'] = ulearn_civicrm_membership_product_types_options($product_types);
  $commands[] = ajax_command_replace('.ulearn-civicrm-replace-product-types', drupal_render($element));
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Get product types for membership.
 */
function ulearn_civicrm_membership_product_types_options($product_types) {
  $types = array();
  $commerce_product_types = commerce_product_types();
  foreach ($product_types as $key => $value) {
    if (!empty($value)) {
      $types[$key] = $commerce_product_types[$key]['name'];
    }
  }
  return $types;
}

/**
 * Get civicrm options.
 */
function ulearn_civicrm_options($name) {
  $options = array();
  if (!isset($name)) {
    return $options;
  }
  $option_group_params = array(
    'version' => 3,
    'sequential' => 1,
    'name' => $name,
  );
  $option_group = civicrm_api3('OptionGroup', 'getsingle', $option_group_params);

  if (!empty($option_group['id'])) {
    $options_params = array(
      'version' => 3,
      'sequential' => 1,
      'option_group_id' => $option_group['id'],
    );
    $option_values = civicrm_api3('OptionValue', 'get', $options_params);
    if (!empty($option_values['values'])) {
      foreach ($option_values['values'] as $option_value) {
        $options[$option_value['value']] = $option_value['label'];
      }
    }
  }
  return $options;
}

/**
 * Get options for civicrm membership types.
 */
function ulearn_civicrm_membership_types() {
  $options = array();
  $params = array(
    'version' => 3,
    'sequential' => 1,
  );
  $membership_types = civicrm_api3('MembershipType', 'get', $params);
  if (!empty($membership_types['values'])) {
    foreach ($membership_types['values'] as $membership_type) {
      $options[$membership_type['id']] = $membership_type['name'];
    }
  }
  return $options;
}

/**
 * Get options for civicrm membership statuses.
 */
function ulearn_civicrm_membership_statuses() {
  $options = array();
  $params = array(
    'version' => 3,
    'sequential' => 1,
  );
  $membership_statuses = civicrm_api3('MembershipStatus', 'get', $params);
  if (!empty($membership_statuses['values'])) {
    foreach ($membership_statuses['values'] as $membership_status) {
      $options[$membership_status['id']] = $membership_status['label'];
    }
  }
  return $options;
}

/**
 * Get options for civicrm membership types.
 */
function ulearn_civicrm_activity_types() {
  $options = array();
  $activity_types = civicrm_api3('activity_type', 'get', array());
  if (!empty($activity_types['values'])) {
    $options = $activity_types['values'];
  }
  return $options;
}
