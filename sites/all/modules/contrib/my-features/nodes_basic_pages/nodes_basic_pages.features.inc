<?php
/**
 * @file
 * nodes_basic_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nodes_basic_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
