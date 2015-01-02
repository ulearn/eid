<?php

/**
* Implements hook_variable_info().
*/
function ulearn_contact_variable_info($options) {
  $variables['ulearn_contact_admin_mail_[mail_part]'] = array(
    'type' => 'mail_html',
    'title' => t('Mail', array(), $options),
    'default' => array(
      'subject' => t('[Contact Submission] [entity:field-subject]', array(), $options),
      'body' => t('[entity:textexport-table]', array(), $options),
    ),
    'description' => t('Admin mail variable with subject and body.', array(), $options),
    'group' => 'ulearn_contact',
    'optional' => TRUE,

  );
  $variables['ulearn_contact_personal_mail_[mail_part]'] = array(
    'type' => 'mail_html',
    'title' => t('Mail', array(), $options),
    'default' => array(
      'subject' => t('[Contact Submission] [entity:field-subject]', array(), $options),
      'body' => t('Personal mail body.', array(), $options),
    ),
    'description' => t('Personal mail variable with subject and body.', array(), $options),
    'group' => 'ulearn_contact',
    'optional' => TRUE,
  );
  return $variables;
}



/**
 * Implements hook_variable_group_info().
 */
function ulearn_contact_variable_group_info() {
  $groups['ulearn_contact'] = array(
    'title' => t('Ulearn'),
    'description' => t('Variable mail of different types.'),
    'access' => 'administer ulearn',
    'path' => array('admin/config/ulearn/variable/ulearn_contact'),
  );
  return $groups;
}

