<?php

/**
 * @file
 * Views plugin definitions
 *
 * @author Mathew Winstone <mwinstone@coldfrontlabs.ca>
 */

/**
 * Implements hook_views_plugins().
 */
function bvt_views_plugins() {
  return array(
    'style' => array(
      'bvt_tables' => array(
        'title' => t('Better Tables'),
        'help' => t('Displays rows in a table with more options than standard Views tables.'),
        'handler' => 'bvt_views_plugin_style_tables',
        'theme' => 'views_view_bvt_tables',
        'uses row plugin' => FALSE,
        'uses row class' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}