<?php
/**
 * @file
 * ulearn_accommodation.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function ulearn_accommodation_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'accommodation_tabs';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Accommodation Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'accommodations',
      'display' => 'page_1',
      'args' => '',
      'title' => 'City Centre Apartments',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'accommodations',
      'display' => 'page_2',
      'args' => '',
      'title' => 'Host Family',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'accommodations',
      'display' => 'page_3',
      'args' => '',
      'title' => 'Student Residence',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Accommodation Tabs');
  t('City Centre Apartments');
  t('Host Family');
  t('Student Residence');

  $export['accommodation_tabs'] = $quicktabs;

  return $export;
}
