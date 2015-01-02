<?php
/**
 * @file
 * nodes_portfolio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nodes_portfolio_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nodes_portfolio_node_info() {
  $items = array(
    'detail_box' => array(
      'name' => t('Detail Box'),
      'base' => 'node_content',
      'description' => t('Use this to create content for the Detail Box View block. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'flexslider' => array(
      'name' => t('Flexslider'),
      'base' => 'node_content',
      'description' => t('Use this to manage content for a Flexslider block. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('Use this to manage your Portfolio content. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
