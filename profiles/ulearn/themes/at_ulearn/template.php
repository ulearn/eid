<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 * 
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "adaptivetheme_subtheme".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function at_ulearn_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.
  
  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function at_ulearn_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function at_ulearn_preprocess_page(&$vars) {
}
function at_ulearn_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function at_ulearn_preprocess_node(&$vars) {
}
function at_ulearn_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function at_ulearn_preprocess_comment(&$vars) {
}
function at_ulearn_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function at_ulearn_preprocess_block(&$vars) {
}
function at_ulearn_process_block(&$vars) {
}
// */

/**
 * Implements hook_form_FORM_ID_alter() for install_select_profile().
 *
 * Allows the default profile selection and unset pantheon
 */
function at_ulearn_form_install_select_profile_form_alter(&$form, &$form_state, $form_id) {
  $form['profile']['ulearn']['#title'] = 'Ulearn Booking platform';
  $form['profile']['ulearn']['#attributes'] = array('checked' => 'checked'); 
  unset($form['profile']['Pantheon']);
  drupal_set_title('Step 1 : Select installation profile');
}

/**
 * Override or insert variables into the maintenance page template.
 */
function at_ulearn_preprocess_maintenance_page(&$vars) {
  // Process some variable before install task is finish
  if (variable_get('install_task') != 'done') {
    $vars['site_name'] = 'Ulearn Booking System ';
    if($vars['title'] == 'Choose language') {
       $vars['title'] = 'Step 2 : Select installation language';
    }
    if($vars['title'] == 'Installing Drupal') {
       $vars['title'] = 'Step 3 : Installing Ulearn Booking system';
    }
    if($vars['title'] == 'Configure site') {
       $vars['title'] = 'Step 4 : Configure site information';
    }
  }
}

/**
 * Override variables for user-picture.tpl.php.
 */
function at_ulearn_preprocess_user_picture(&$variables) {
  if (module_exists('user_picture_field')) {
    // Do not display default user picture.
    $variables['user_picture'] = NULL;
  }
}