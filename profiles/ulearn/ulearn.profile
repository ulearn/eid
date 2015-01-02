<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function ulearn_form_install_configure_form_alter(&$form, $form_state) {
  // Hide some messages from various modules that are just too chatty!
  drupal_get_messages('status');
  drupal_get_messages('warning');

  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'Ulearn';

  // Set default country for site as GB
  $form['server_settings']['site_default_country']['#default_value'] = 'GB';

  // Set default timezone to 'Atlantic/Canary' +00:00
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Atlantic/Canary';
  unset($form['server_settings']['date_default_timezone']['#attributes']);

  // Use "admin" as the default username.
  $form['admin_account']['account']['name']['#default_value'] = 'admin';

  // Set the default admin password.
  $form['admin_account']['account']['pass']['#value'] = 'admin';

  // Hide Update Notifications.
  $form['update_notifications']['#access'] = FALSE;

  // Add informations about the default username and password.
  $form['admin_account']['account']['ulearn_name'] = array(
    '#type' => 'item', '#title' => st('Username'),
    '#markup' => 'admin'
  );
  $form['admin_account']['account']['ulearn_password'] = array(
    '#type' => 'item', '#title' => st('Password'),
    '#markup' => 'admin'
  );
  $form['admin_account']['override_account_informations'] = array(
    '#type' => 'checkbox',
    '#title' => t('Change my username and password.'),
  );
  $form['admin_account']['setup_account'] = array(
    '#type' => 'container',
    '#parents' => array('admin_account'),
    '#states' => array(
      'invisible' => array(
        'input[name="override_account_informations"]' => array('checked' => FALSE),
      ),
    ),
  );
  
  // Make a "copy" of the original name and pass form fields.
  $form['admin_account']['setup_account']['account']['name'] = $form['admin_account']['account']['name'];
  $form['admin_account']['setup_account']['account']['pass'] = $form['admin_account']['account']['pass'];
  $form['admin_account']['setup_account']['account']['pass']['#value'] = array('pass1' => 'admin', 'pass2' => 'admin');

  // Use "admin" as the default username.
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['name']['#access'] = FALSE;

  // Set the default admin password.
  $form['admin_account']['account']['pass']['#value'] = 'admin';

  // Make the password "hidden".
  $form['admin_account']['account']['pass']['#type'] = 'hidden';
  $form['admin_account']['account']['mail']['#access'] = FALSE;

  // Configure ULearn admin emails.
  $form['admin_account']['account']['ulearn_global_admin_email'] = array(
    '#title' => t('ULearn admin email'),
    '#type' => 'textarea',
    '#default_value' => variable_get('ulearn_global_admin_email', ''),
    '#rows' => 2,
    '#description' => t('Comma separeted list of email ids to which site wide emails should be sent.'),
  );

  // Add a custom validation that needs to be trigger before the original one,
  // where we can copy the site's mail as the admin account's mail.
  array_unshift($form['#validate'], 'ulearn_install_custom_setting');

  // Add submit to store our variable.
  $form['#submit'][] = 'ulearn_install_custom_submit';
}

/**
 * Validate callback; Populate the admin account mail, user and password with
 * custom values.
 */
function ulearn_install_custom_setting(&$form, &$form_state) {
  $form_state['values']['account']['mail'] = $form_state['values']['site_mail'];
  // Use our custom values only the corresponding checkbox is checked.
  if ($form_state['values']['override_account_informations'] == TRUE) {
    if ($form_state['input']['pass']['pass1'] == $form_state['input']['pass']['pass2']) {
      $form_state['values']['account']['name'] = $form_state['values']['name'];
      $form_state['values']['account']['pass'] = $form_state['input']['pass']['pass1'];
    }
    else {
      form_set_error('pass', t('The specified passwords do not match.'));
    }
  }
}

/**
 * Submit callback: Stores custom variable.
 */
function ulearn_install_custom_submit(&$form, &$form_state) {
 $values = $form_state['values'];
  variable_set('ulearn_global_admin_email', $values['account']['ulearn_global_admin_email']);
}

// Include only when in install mode. MAINTENANCE_MODE is defined in
// install.php and in drush_core_site_install().
if (defined('MAINTENANCE_MODE') && MAINTENANCE_MODE == 'install') {
  include_once('ulearn.install.inc');
}
