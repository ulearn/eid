<?php
/**
 * @file
 * ulearn_blog.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ulearn_blog_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blog';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_blog'] = $strongarm;

  return $export;
}
