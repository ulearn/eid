<?php
/**
 * @file
 * content_types_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_types_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_types_pages_node_info() {
  $items = array(
    'vsx_slide' => array(
      'name' => t('Slide'),
      'base' => 'node_content',
      'description' => t('Node type used for making Views Slideshow Slides.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
