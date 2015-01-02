<?php
/**
 * @file
 * ulearn_commerce.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function ulearn_commerce_commerce_product_default_types() {
  $items = array(
    'materials' => array(
      'type' => 'materials',
      'name' => 'Materials',
      'description' => 'Product type for ULearn course materials.',
      'help' => '',
      'revision' => 1,
    ),
    'transport' => array(
      'type' => 'transport',
      'name' => 'Transport',
      'description' => 'Product type for ULearn transports.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ulearn_commerce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ulearn_commerce_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('Use <em>product display</em> to show ULearn accommodation, materials and transports.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
