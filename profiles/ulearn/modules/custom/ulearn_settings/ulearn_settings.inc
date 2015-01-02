<?php
/**
 * @file
 */

/**
 * Enabling blocks (theme, region..)
 *
 * @param Array $values
 * @example array(array(
 *    'module' => 'core_search',
 *    'delta' => 'form',
 *    'theme' => $default_theme,
 *    'status' => 1,
 *    'weight' => 0,
 *    'region' => 'footer',
 *    'visibility' => 1
 *    'pages' => '',
 *    'cache' => -1,
 *  ), ...)
 */
function ulearn_settings_block_enable($blocks = array()) {
  foreach ($blocks as $block) {
    db_merge('block')
      ->key(array('module' => $block['module']))
      ->key(array('delta'  => $block['delta']))
      ->key(array('theme' => $block['theme']))
      ->fields(array(
        'status' => (isset($block['status'])) ? $block['status'] : BLOCK_CUSTOM_DISABLED,
        'weight' => (isset($block['weight'])) ? $block['weight'] : 0,
        'region' => (isset($block['region'])) ? $block['region'] : -1,
        'visibility' => (isset($block['visibility'])) ? $block['visibility'] : 0,
        'pages'  => (isset($block['pages'])) ? $block['pages'] : '',
        'cache'  => (isset($block['cache'])) ? $block['cache'] : DRUPAL_NO_CACHE,
        'title'  => (isset($block['title'])) ? $block['title'] : '',
      ))
      ->execute();
  }
}