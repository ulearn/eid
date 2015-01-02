<?php
/**
 * @file
 * my_portfolio.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function my_portfolio_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_portfolio';
  $strongarm->value = 1;
  $export['i18n_node_extended_portfolio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_portfolio';
  $strongarm->value = array();
  $export['i18n_node_options_portfolio'] = $strongarm;

  return $export;
}
