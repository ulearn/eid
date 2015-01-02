<?php

/**
* Implements hook_variable_info().
*/
function ulearn_course_variable_info($options) {
  $variables['ulearn_course_admin_mail_[mail_part]'] = array(
    'type' => 'mail_html',
    'title' => t('Mail', array(), $options),
    'default' => array(
      'subject' => t('[site:name]: New course is added.', array(), $options),
      'body' => t('New Course [node:url] is added by [node:author] in [node:field-course-school].', array(), $options),
    ),
    'description' => t('Admin mail variable with subject and body.', array(), $options),
    'group' => 'ulearn_course',
    'optional' => TRUE,

  );

  $variables['ulearn_course_default_registration_fee'] = array(
    'type' => 'number',
    'title' => t('Registration fee for course', array(), $options),
    'default' => 50,
    'group' => 'ulearn_course',
    'optional' => TRUE,
  );
  return $variables;
}

/**
 * Implements hook_variable_group_info().
 */
function ulearn_course_variable_group_info() {
  $groups['ulearn_course'] = array(
    'title' => t('Ulearn'),
    'description' => t('Variable mail of different types.'),
    'access' => 'administer ulearn',
    'path' => array('admin/config/ulearn/variable/ulearn_course'),
  );
  return $groups;
}

