<?php

/**
 * @file
 * Administrative callbacks for ULearn migration module.
 */

/**
 * ULearn migrate configuration form.
 */
function ulearn_migrate_config_form($form, $form_state) {
  $form = array();

  // Database name.
  $form['ulearn_migrate_database_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Database name',
    '#default_value' => variable_get('ulearn_migrate_database_name', ''),
    '#description' => t('Please enter the name of the database from which we need to migrate content.'),
    '#required' => TRUE,
  );

  // Database user.
  $form['ulearn_migrate_database_user'] = array(
    '#type' => 'textfield',
    '#title' => 'Database user',
    '#default_value' => variable_get('ulearn_migrate_database_user', ''),
    '#required' => TRUE,
  );

  // Database password.
  $form['ulearn_migrate_database_pass'] = array(
    '#type' => 'textfield',
    '#title' => 'Database password',
    '#default_value' => variable_get('ulearn_migrate_database_pass', ''),
    '#required' => TRUE,
  );

  // Database host.
  $form['ulearn_migrate_database_host'] = array(
    '#type' => 'textfield',
    '#title' => 'Database host',
    '#default_value' => variable_get('ulearn_migrate_database_host', 'localhost'),
    '#description' => t('If your database is located on a different server, change this.'),
    '#required' => TRUE,
  );

  // Database port.
  $form['ulearn_migrate_database_port'] = array(
    '#type' => 'textfield',
    '#title' => 'Database Port',
    '#default_value' => variable_get('ulearn_migrate_database_port', ''),
    '#required' => TRUE,
  );

  // Migrated files path.
  $form['ulearn_migrate_server_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Remote server URL',
    '#default_value' => variable_get('ulearn_migrate_server_url', ''),
    '#description' => t('Please enter the remote server URL. E.g http://www.ulearn.ie'),
    '#required' => TRUE,
  );

  $form['#validate'] = array('ulearn_migrate_validate_db_connection');

  return system_settings_form($form);
}

/**
 * Validates database connection settings.
 */
function ulearn_migrate_validate_db_connection($form, $form_state) {
  $values = $form_state['values'];
  $other_database = array(
    'database' => $values['ulearn_migrate_database_name'],
    'username' => $values['ulearn_migrate_database_user'],
    'password' => $values['ulearn_migrate_database_pass'],
    'host'     => $values['ulearn_migrate_database_host'],
    'port'     => $values['ulearn_migrate_database_port'],
    'driver'   => 'mysql'
  );

  $result = ulearn_migrate_db_connect($other_database);
  if (!$result['status']) {
    form_set_error('', t('Failed to connect to your database server. The server reports the following message: @message', array('@message' => $result['message'])));
  }
}
