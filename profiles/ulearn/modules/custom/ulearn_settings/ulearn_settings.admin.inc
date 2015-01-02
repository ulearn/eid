<?php

/**
 * @file
 * Administrative forms and callbacks for Ulearn settings module.
 */

/**
 * Global settings form for ULearn.
 */
function ulearn_settings_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['#tree'] = TRUE;

    // Site configuration.
  $form['ulearn_settings_site'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );

  // Site name.
  $form['ulearn_settings_site']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site name'),
    '#default_value' => variable_get('site_name', 'Drupal'),
    '#required' => TRUE,
  );

  $form['ulearn_settings_site']['logo'] = array(
    '#type' => 'fieldset',
    '#title' => t('Logo image settings'),
    '#description' => t('If toggled on, the following logo will be displayed.'),
    '#attributes' => array('class' => array('theme-settings-bottom')),
  );
  $form['ulearn_settings_site']['logo']['default_logo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the default logo'),
    '#default_value' => theme_get_setting('default_logo'),
    '#tree' => FALSE,
    '#description' => t('Check here if you want the theme to use the logo supplied with it.')
  );
  $form['ulearn_settings_site']['logo']['settings'] = array(
    '#type' => 'container',
    '#states' => array(
      // Hide the logo settings when using the default logo.
      'invisible' => array(
        'input[name="default_logo"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['ulearn_settings_site']['logo']['settings']['logo_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to custom logo'),
    '#description' => t('The path to the file you would like to use as your logo file instead of the default logo.'),
    '#default_value' => theme_get_setting('logo_path'),
  );

  $form['ulearn_settings_site']['logo']['settings']['logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Upload logo image'),
    '#maxlength' => 40,
    '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
  );

  // Site frontpage.
  $form['ulearn_settings_site']['site_frontpage'] = array(
    '#type' => 'textfield',
    '#title' => t('Default front page'),
    '#default_value' => (variable_get('site_frontpage') != 'node' ? drupal_get_path_alias(variable_get('site_frontpage', 'node')) : ''),
    '#size' => 40,
    '#description' => t('Optionally, specify a relative URL to display as the front page.  Leave blank to display the default content feed.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
  );

  // 403 page.
  $form['ulearn_settings_site']['site_403'] = array(
    '#type' => 'textfield',
    '#title' => t('Default 403 (access denied) page'),
    '#default_value' => variable_get('site_403', ''),
    '#size' => 40,
    '#description' => t('This page is displayed when the requested document is denied to the current user. Leave blank to display a generic "access denied" page.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
  );

  // 404 page.
  $form['ulearn_settings_site']['site_404'] = array(
    '#type' => 'textfield',
    '#title' => t('Default 404 (not found) page'),
    '#default_value' => variable_get('site_404', ''),
    '#size' => 40,
    '#description' => t('This page is displayed when no other content matches the requested document. Leave blank to display a generic "page not found" page.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
  );

  $form['ulearn_settings_site']['maintenance_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Put site into maintenance mode'),
    '#default_value' => variable_get('maintenance_mode', 0),
    '#description' => t('This will put your site into maintenance mode. Only administrators are able to access site to perform maintenance; all other visitors see the maintenance mode message configured below. Authorized users can log in directly via the <a href="@user-login">user login</a> page.', array('@user-login' => url('user'))),
  );
  $form['ulearn_settings_site']['maintenance_mode_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Maintenance mode message'),
    '#default_value' => variable_get('maintenance_mode_message', t('@site is currently under maintenance. We should be back shortly. Thank you for your patience.', array('@site' => variable_get('site_name', 'Drupal')))),
    '#description' => t('Message to show visitors when the site is in maintenance mode.')
  );

  // Global admin email ids.
  $form['ulearn_settings_site']['ulearn_global_admin_email'] = array(
    '#title' => t('ULearn admin email'),
    '#type' => 'textarea',
    '#default_value' => variable_get('ulearn_global_admin_email', ''),
    '#rows' => 2,
    '#description' => t('Comma separeted list of email ids to which site wide emails should be sent.'),
  );

  // Courses related configuration.
  $form['ulearn_courses'] = array(
    '#type' => 'fieldset',
    '#title' => t('Courses'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $courses_config = variable_get('ulearn_courses', array());

  // Pattern for unique registration id.
  $form['ulearn_courses']['ulearn_course_registration_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Registration ID pattern'),
    '#required' => TRUE,
    '#size' => 80,
    '#default_value' => !empty($courses_config['ulearn_course_registration_pattern']) ? $courses_config['ulearn_course_registration_pattern'] : '[node:field-course-unique-id]-[registration:registration-id]',
    '#description' => t('Pattern used to decide registration id for course registration.'),
    '#suffix' => theme('token_tree', array('token_types' => array('site', 'node', 'registration', 'random'), 'global_types' => FALSE)),
  );

  // Share amount.
  $form['ulearn_courses']['ulearn_course_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount for ULearn'),
    '#field_suffix' => '%',
    '#required' => TRUE,
    '#size' => 5,
    '#default_value' => !empty($courses_config['ulearn_course_amount']) ? $courses_config['ulearn_course_amount'] : 0,
    '#rules' => array('range[0,100]'),
    '#description' => t('Percentage amount that will be used to calculate ULearn share for each course registration (should be in 0 - 100). You can override this amount while adding new course.'),
  );

  // Number of weeks.
  $form['ulearn_courses']['ulearn_course_weeks'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of weeks'),
    '#required' => TRUE,
    '#size' => 5,
    '#default_value' => !empty($courses_config['ulearn_course_weeks']) ? $courses_config['ulearn_course_weeks'] : 10,
    '#rules' => array('numeric', 'range[10,100]'),
    '#description' => t('Number of weeks that will be available while adding/updating course. <strong>WARNING: Reducing the number may cause data loss.</strong>'),
  );

  // Friday as a week end day.
  $form['ulearn_courses']['ulearn_course_week_end_friday'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make Friday as a end day of week.'),
    '#default_value' => $courses_config['ulearn_course_week_end_friday'],
    '#description' => t('To make Friday as a end date of week, start day of week must set to Monday while adding the course.'),
  );

  // Global config for Peak season rate.
  $form['ulearn_courses']['peak_season_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Peak season rates'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="peak-season-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  $currency_code = variable_get('commerce_default_currency', 'EUR');
  $peak_season_config = !empty($courses_config['peak_season_fieldset']['peak_field_wrapper']) ? $courses_config['peak_season_fieldset']['peak_field_wrapper'] : array();

  // Build the fieldset with the proper number of fieldsets containing required
  // fields. We'll use $form_state['num_peak_fieldsets'] to determine the number of
  // textfields to build.
  $fieldsets_count = count($peak_season_config);
  if (empty($form_state['num_peak_fieldsets'])) {
    $form_state['num_peak_fieldsets'] = !empty($fieldsets_count) ? $fieldsets_count : 1;
  }
  for ($i = 0; $i < $form_state['num_peak_fieldsets']; $i++) {
    $form['ulearn_courses']['peak_season_fieldset']['peak_field_wrapper'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Peak season details'),
      '#collapsible' => FALSE,
    );
    $start_date = !empty($peak_season_config[$i]['peak_season_start_date']) ? $peak_season_config[$i]['peak_season_start_date'] : NULL;
    $formatted_date = NULL;
    if (!empty($start_date)) {
      $start_date_timestamp = strtotime($start_date);
      $formatted_date = format_date($start_date_timestamp, 'custom', 'Y-m-d 00:00:00');
    }

    $form['ulearn_courses']['peak_season_fieldset']['peak_field_wrapper'][$i]['peak_season_start_date'] = array(
      '#type' => 'date_popup',
      '#title' => t('Start date'),
      '#date_format' => variable_get('date_format_ulearn_date_format', 'l, F j, Y'),
      '#date_label_position' => 'none',
      '#default_value' => $formatted_date,
    );
    $form['ulearn_courses']['peak_season_fieldset']['peak_field_wrapper'][$i]['peak_season_amount'] = array(
      '#type' => 'textfield',
      '#title' => t('Amount'),
      '#default_value' => !empty($peak_season_config[$i]['peak_season_amount']) ? $peak_season_config[$i]['peak_season_amount'] : 0,
      '#size' => 10,
      '#field_suffix' => $currency_code,
    );
  }


  $form['ulearn_courses']['peak_season_fieldset']['add_peak_season'] = array(
    '#type' => 'submit',
    '#value' => t('Add one more'),
    '#submit' => array('ulearn_settings_add_more_add_one'),
    '#ajax' => array(
      'callback' => 'ulearn_settings_add_more_callback',
      'wrapper' => 'peak-season-fieldset-wrapper',
    ),
  );

  if ($form_state['num_peak_fieldsets'] > 1) {
    $form['ulearn_courses']['peak_season_fieldset']['remove_peak_season'] = array(
      '#type' => 'submit',
      '#value' => t('Remove one'),
      '#submit' => array('ulearn_settings_add_more_remove_one'),
      '#ajax' => array(
        'callback' => 'ulearn_settings_add_more_callback',
        'wrapper' => 'peak-season-fieldset-wrapper',
      ),
    );
  }

  // Commerce related configuration.
  $form['ulearn_commerce'] = array(
    '#type' => 'fieldset',
    '#title' => t('Commerce'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => FALSE,
  );

  // Transaction status that will be used to mark order
  // as 'completed' for student paytostudy transaction.
  $form['ulearn_commerce']['ulearn_commerce_paytostudy_transaction_status'] = array(
    '#type' => 'select',
    '#title' => t('PaytoStudy transaction status'),
    '#options' => ulearn_commerce_paytostudy_transaction_statuses(),
    '#default_value' => variable_get('ulearn_commerce_paytostudy_transaction_status', 'Pending'),
    '#description' => t('Transaction status that will be used to mark order as \'completed\' for student\'s PaytoStudy transaction.'),
  );

  // Add to cart text.
  $form['ulearn_commerce']['ulearn_commerce_add_to_cart_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Add to cart text'),
    '#size' => 30,
    '#default_value' => variable_get('ulearn_commerce_add_to_cart_text', ''),
    '#description' => t('Default text for \'Add to cart\' button. Keep blank for default text.'),
  );

  // SSL info text.
  $form['ulearn_commerce']['ulearn_commerce_ssl_info_text'] = array(
    '#type' => 'textfield',
    '#title' => t('SSL info text'),
    '#size' => 60,
    '#default_value' => variable_get('ulearn_commerce_ssl_info_text', 'Credit card details are transferred using SSL.'),
    '#description' => t('Default text for SSL info on Credit card payment pane.'),
  );

  // Product types to restrict quantity.
  $form['ulearn_commerce']['ulearn_commerce_product_types'] = array(
    '#title' => t('Restrict quantity for product types'),
    '#type' => 'checkboxes',
    '#options' => ulearn_commerce_available_product_types(),
    '#description' => t('Only single quantity of selected product types will be allowed.'),
    '#default_value' => variable_get('ulearn_commerce_product_types', array()),
  );
  
  // Title of checkout complete page.
  $form['ulearn_commerce']['ulearn_commerce_checkout_completion_title'] = array(
    '#title' => 'Checkout completion page title',
    '#type' => 'textfield',
    '#default_value' => variable_get('ulearn_commerce_checkout_completion_title', ''),
  );

  // Checkout completion message.
  $checkout_message = variable_get('commerce_checkout_completion_message', commerce_checkout_completion_message_default());
  $form['ulearn_commerce']['commerce_checkout_completion_message'] = array(
    '#type' => 'text_format',
    '#title' => t('Checkout completion message'),
    '#default_value' => $checkout_message['value'],
    '#format' => $checkout_message['format'],
    '#access' => filter_access(filter_format_load($checkout_message['format'])),
  );

  $form['ulearn_commerce']['ulearn_commerce_pay_reception_embed_map'] = array(
    '#type' => 'fieldset',
    '#title' => t('Embed script for Pay Cash / Credit Card In Reception method.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['ulearn_commerce']['ulearn_commerce_pay_reception_embed_map']['ulearn_commerce_pay_reception_embed_map_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display map using script.'),
    '#default_value' => variable_get('ulearn_commerce_pay_reception_embed_map_display', TRUE),
    '#description' => t('Display map for Pay Cash / Credit Card In Reception method using below script.'),
  );

  $form['ulearn_commerce']['ulearn_commerce_pay_reception_embed_map']['ulearn_commerce_pay_reception_embed_map_script'] = array(
    '#type' => 'textarea',
    '#title' => t('Embed script for map'),
    '#default_value' => variable_get('ulearn_commerce_pay_reception_embed_map_script', ''),
    '#description' => t('Embed script for map that will be displayed if Pay Cash / Credit Card In Reception method is selected.'),
  );

  // Provide token support.
  $var_info = array(
    'site' => array(
      'type' => 'site',
      'label' => t('Site information'),
      'description' => t('Site-wide settings and other global information.'),
    ),
    'commerce_order' => array(
      'label' => t('Order'),
      'type' => 'commerce_order',
    ),
  );
  $form['ulearn_commerce']['ulearn_commerce_help'] = RulesTokenEvaluator::help($var_info);

  // Partial payment configuration.
  $form['ulearn_commerce']['ulearn_commerce_payment_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Partial payment configuration'),
    '#collapsible' => FALSE,
  );

  // Payment methods that allow partial payment.
  $form['ulearn_commerce']['ulearn_commerce_payment_config']['ulearn_commerce_pay_later_methods'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Payment methods'),
    '#options' => array('commerce_realex_remote|commerce_payment_credit_card' => t('Credit card')),
    '#default_value' => variable_get('ulearn_commerce_pay_later_methods', array()),
    '#description' => t('Select payment methods that allows partial payment. Currently only allowed for credit card.'),
  );

  // Partial payment amount.
  $form['ulearn_commerce']['ulearn_commerce_payment_config']['ulearn_commerce_pay_later_amount'] = array(
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => t('Partial payment amount'),
    '#default_value' => variable_get('ulearn_commerce_pay_later_amount', 50),
    '#description' => t('Set partial payment amount.'),
    '#field_suffix' => 'EUR',
  );

  // Default text when paytostudy is not available.
  $value = array(
    'value' => t('We are unable to process currency conversion. Reason provided by PaytoStudy: !paytostudy-error. Please select different payment method.'),
    'format' => 'full_html',
  );
  $paytostudy_not_avail = variable_get('ulearn_commerce_paytostudy_not_avail', $value);

  $form['ulearn_commerce']['ulearn_commerce_paytostudy_not_avail'] = array(
    '#type' => 'text_format',
    '#title' => t('PaytoStudy not available text'),
    '#default_value' => $paytostudy_not_avail['value'],
    '#format' => $paytostudy_not_avail['format'],
    '#description' => t('Default text to display on checkout review page when PaytoStudy is not available for selected country. Use token !paytostudy-error for error message returned from PaytoStudy.')
  );

  $form['#validate'][] = 'ulearn_settings_admin_settings_validate';
  // Add our submit later so we can clean up
  // unnecessary variables created for theme settings.
  $form = system_settings_form($form);
  $form['#submit'][] = 'ulearn_settings_admin_settings_submit';

  return $form;
}

/**
 * Submit handler for Add one more button.
 */
function ulearn_settings_add_more_add_one($form, &$form_state) {
  $form_state['num_peak_fieldsets']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for Remove one button.
 */
function ulearn_settings_add_more_remove_one($form, &$form_state) {
  if ($form_state['num_peak_fieldsets'] > 1) {
    $form_state['num_peak_fieldsets']--;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Callback for both ajax enabled buttons.
 */
function ulearn_settings_add_more_callback($form, $form_state) {
  return $form['ulearn_courses']['peak_season_fieldset'];
}

/**
 * Validates the ulearn admin settings form.
 */
function ulearn_settings_admin_settings_validate($form, &$form_state) {
  // Load system.admin.inc from system module.
  module_load_include('inc', 'system', 'system.admin');

  // Check for empty front page path.
  if (empty($form_state['values']['site_frontpage'])) {
    // Set to default "node".
    form_set_value($form['ulearn_settings_site']['site_frontpage'], 'node', $form_state);
  }
  else {
    // Get the normal path of the front page.
    form_set_value($form['ulearn_settings_site']['site_frontpage'], drupal_get_normal_path($form_state['values']['site_frontpage']), $form_state);
  }
  // Validate front page path.
  if (!drupal_valid_path($form_state['values']['site_frontpage'])) {
    form_set_error('site_frontpage', t("The path '%path' is either invalid or you do not have access to it.", array('%path' => $form_state['values']['site_frontpage'])));
  }
  // Get the normal paths of both error pages.
  if (!empty($form_state['values']['site_403'])) {
    form_set_value($form['ulearn_settings_site']['site_403'], drupal_get_normal_path($form_state['values']['site_403']), $form_state);
  }
  if (!empty($form_state['values']['site_404'])) {
    form_set_value($form['ulearn_settings_site']['site_404'], drupal_get_normal_path($form_state['values']['site_404']), $form_state);
  }
  // Validate 403 error path.
  if (!empty($form_state['values']['site_403']) && !drupal_valid_path($form_state['values']['site_403'])) {
    form_set_error('site_403', t("The path '%path' is either invalid or you do not have access to it.", array('%path' => $form_state['values']['site_403'])));
  }
  // Validate 404 error path.
  if (!empty($form_state['values']['site_404']) && !drupal_valid_path($form_state['values']['site_404'])) {
    form_set_error('site_404', t("The path '%path' is either invalid or you do not have access to it.", array('%path' => $form_state['values']['site_404'])));
  }

  // Handle file uploads.
  $validators = array('file_validate_is_image' => array());

  // Check for a new uploaded logo.
  $file = file_save_upload('logo_upload', $validators);
  if (isset($file)) {
    // File upload was attempted.
    if ($file) {
      // Put the temporary file in form_values so we can save it on submit.
      $form_state['values']['logo_upload'] = $file;
    }
    else {
      // File upload failed.
      form_set_error('logo_upload', t('The logo could not be uploaded.'));
    }
  }

  $validators = array('file_validate_extensions' => array('ico png gif jpg jpeg apng svg'));

  // If the user provided a path for a logo file,
  // make sure a file exists at that path.
  if ($form_state['values']['logo_path']) {
    $path = _system_theme_settings_validate_path($form_state['values']['logo_path']);
    if (!$path) {
      form_set_error('logo_path', t('The custom logo path is invalid.'));
    }
  }
}

/**
 * Submit handler for ulearn admin settings form.
 */
function ulearn_settings_admin_settings_submit($form, &$form_state) {
  // Load system.admin.inc from system module.
  module_load_include('inc', 'system', 'system.admin');

  $values = $form_state['values'];

  // If the user uploaded a new logo, save it to a permanent location
  // and use it in place of the default theme-provided file.
  if ($file = $values['logo_upload']) {
    unset($values['logo_upload']);
    $filename = file_unmanaged_copy($file->uri);
    $values['default_logo'] = 0;
    $values['logo_path'] = $filename;
    $values['toggle_logo'] = 1;
  }
  // If the user entered a path relative to the system files directory for
  // a logo or favicon, store a public:// URI so the theme system can handle it.
  if (!empty($values['logo_path'])) {
    $values['logo_path'] = _system_theme_settings_validate_path($values['logo_path']);
  }
  // Save default theme settings.
  $default_theme = variable_get('theme_default', 'at_ulearn');
  $theme_settings = variable_get('theme_' . $default_theme . '_settings', array());
  foreach (array('toggle_logo', 'default_logo', 'logo_path') as $key) {
    if (isset($values[$key])) {
      $theme_settings[$key] = $values[$key];
    }
  }
  variable_set('theme_' . $default_theme . '_settings', $theme_settings);

  // Remove unnecessary variables created by system_settings_form.
  foreach (array('default_logo', 'logo_path', 'logo_upload') as $key) {
    variable_del($key);
  }

  // Update instance of course weeks field to
  // avoid warnings for increased number of weeks.
  $instance = field_info_instance('commerce_option', 'field_course_week_options', 'week_options');
  $options_settings = $instance['settings']['commerce_pricing_attributes'];
  $week_number = $values['ulearn_course_weeks'];
  // Prepare week options array as required.
  $options = array();
  for ($i = 1; $i <= $week_number; $i++) {
    // Use defaults for old options.
    $options[$i] = array(
      'enabled' => isset($options_settings[$i]['enabled']) ? $options_settings[$i]['enabled'] : TRUE,
      'price_op' => isset($options_settings[$i]['price_op']) ? $options_settings[$i]['price_op'] : 'plus',
      'price' => isset($options_settings[$i]['price']) ? $options_settings[$i]['price'] : '0',
      'currency_code' => isset($options_settings[$i]['currency_code']) ? $options_settings[$i]['currency_code'] : commerce_default_currency(),
      'calculate' => isset($options_settings[$i]['calculate']) ? $options_settings[$i]['calculate'] : 'per_item',
      'weight' => $i,
    );
  }
  // Use empty option if available.
  if (isset($options_settings['_none'])) {
    $options['_none'] = $options_settings['_none'];
  }

  $instance['settings']['commerce_pricing_attributes'] = $options;
  field_update_instance($instance);
}

/**
 * Group Email settings form for ULearn by module.
 */
function ulearn_settings_variables_email_settings_form($name = NULL) {
  variable_include();
  module_load_include('inc', 'variable_admin', 'variable_admin');
  $build['message']['#markup'] = _variable_admin_realm_message();
  $realm_options = _variable_admin_realm_options();

  // Groups overview
  $build['modules'] = array(
    '#type' => 'vertical_tabs',
  );

  foreach (system_list('module_enabled') as $module) {
    if((strpos($module->name,"ulearn_") !== FALSE) || ($module->name == 'user')) {

      $param = $module->name;
      if ($module->name == 'user') {
        // Only allow user emails.
        $param = 'user_mails';
      }

      if ($variables = variable_list_group($param)) {
        $build['modules'][$module->name] = array(
          '#type' => 'fieldset',
          '#title' => $module->info['name'],
          '#collapsible' => TRUE, '#collapsed' => TRUE,
          '#description' => $module->info['description'] . ' ' . l(t('Edit module variables'), 'admin/config/ulearn/variables/' . $module->name),
          '#group' => 'modules',
        );
        $build['modules'][$module->name]['list'] = variable_admin_group_list($variables, $realm_options);
      }
    }
  }
  return $build;
}
