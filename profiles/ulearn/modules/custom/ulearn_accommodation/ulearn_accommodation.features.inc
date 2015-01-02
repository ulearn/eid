<?php
/**
 * @file
 * ulearn_accommodation.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function ulearn_accommodation_commerce_line_item_default_types() {
  $items = array(
    'accommodation' => array(
      'name' => 'Accommodation',
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
function ulearn_accommodation_commerce_product_default_types() {
  $items = array(
    'accommodation' => array(
      'type' => 'accommodation',
      'name' => 'Accommodation',
      'description' => 'Product type for ULearn accommodation.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ulearn_accommodation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ulearn_accommodation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ulearn_accommodation_node_info() {
  $items = array(
    'accommodation_display' => array(
      'name' => t('Accommodation'),
      'base' => 'node_content',
      'description' => t('Use <em>Accommodation</em> to add new accommodation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
