<?php
/**
 * @file
 * ulearn_special_courses.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function ulearn_special_courses_commerce_line_item_default_types() {
  $items = array(
    'special_courses' => array(
      'name' => 'Special courses',
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
function ulearn_special_courses_commerce_product_default_types() {
  $items = array(
    'special_course' => array(
      'type' => 'special_course',
      'name' => 'Special course',
      'description' => 'ULearn Special course.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ulearn_special_courses_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ulearn_special_courses_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ulearn_special_courses_node_info() {
  $items = array(
    'special_course' => array(
      'name' => t('Special course'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
