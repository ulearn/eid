<?php
/**
 * @file
 * ulearn_course.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function ulearn_course_commerce_line_item_default_types() {
  $items = array(
    'general_courses' => array(
      'name' => 'General Courses',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function ulearn_course_commerce_product_default_types() {
  $items = array(
    'course' => array(
      'type' => 'course',
      'name' => 'Courses',
      'description' => 'ULearn General English courses.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ulearn_course_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "config_perms" && $api == "config_perms") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ulearn_course_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_custom_breadcrumbs_paths_features_default_settings().
 */
function ulearn_course_custom_breadcrumbs_paths_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: registration_display.
  $custom_breadcrumbs['registration_display'] = array(
    'name' => 'Registration display',
    'titles' => 'My profile
Course registrations
[current-page:title]',
    'paths' => 'user/[current-user:uid]
course-registrations
<nolink>',
    'visibility_php' => '',
    'specific_path' => 'registration/*',
    'language' => '',
    'machine_name' => 'registration_display',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_custom_breadcrumbs_views_features_default_settings().
 */
function ulearn_course_custom_breadcrumbs_views_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: course_registration_page.
  $custom_breadcrumbs['course_registration_page'] = array(
    'name' => 'Course registration page',
    'titles' => 'My profile
Course registrations',
    'paths' => 'user/[current-user:uid]
<nolink>',
    'visibility_php' => '',
    'views_path' => 'course-registrations',
    'language' => '',
    'machine_name' => 'course_registration_page',
  );

  // Exported custom breadcrumb: course_schedules.
  $custom_breadcrumbs['course_schedules'] = array(
    'name' => 'Course schedules',
    'titles' => 'My profile
Course schedules',
    'paths' => 'user/[current-user:uid]
<nolink>',
    'visibility_php' => '',
    'views_path' => 'course-schedules',
    'language' => '',
    'machine_name' => 'course_schedules',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_node_info().
 */
function ulearn_course_node_info() {
  $items = array(
    'course_display' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('Use <em>course display</em> to show ULearn courses.'),
      'has_title' => '1',
      'title_label' => t('Course title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_registration_type().
 */
function ulearn_course_default_registration_type() {
  $items = array();
  $items['ulearn_course_registration'] = entity_import('registration_type', '{
    "name" : "ulearn_course_registration",
    "label" : "Course registration",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
