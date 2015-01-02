<?php
/**
 * @file
 * my_portfolio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function my_portfolio_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
