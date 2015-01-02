<?php
/**
 * @file
 * ulearn_course.config_perms.inc
 */

/**
 * Implements hook_config_perms().
 */
function ulearn_course_config_perms() {
  $export = array();

  $config_perms = new stdClass();
  $config_perms->disabled = FALSE; /* Edit this to true to make a default config_perms disabled initially */
  $config_perms->api_version = 1;
  $config_perms->machine_name = 'configure_ulearn_commerce_store';
  $config_perms->status = TRUE;
  $config_perms->name = 'configure ulearn commerce store';
  $config_perms->path = array(
    0 => 'admin/commerce',
    1 => 'admin/commerce/*',
  );
  $export['configure_ulearn_commerce_store'] = $config_perms;

  return $export;
}
