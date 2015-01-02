<?php
/**
 * @file
 * new_nodes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function new_nodes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function new_nodes_node_info() {
  $items = array(
    'ajax_navigation' => array(
      'name' => t('AJAX Navigation'),
      'base' => 'node_content',
      'description' => t('Use this to manage content for an AJAX Navigation block. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
