<?php
/**
 * @file
 * ulearn_settings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ulearn_settings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'full_screen';
  $context->description = 'Full Screen - No Right Sidebar';
  $context->tag = 'full-screen';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/2441' => 'node/2441',
        'prices' => 'prices',
        '*/prices' => '*/prices',
        'precios' => 'precios',
        'videos' => 'videos',
        'ulearn-english-school-dublin-event-zine' => 'ulearn-english-school-dublin-event-zine',
        'ulearn-english-school-dublin-social-events-page' => 'ulearn-english-school-dublin-social-events-page',
        'escola-de-inglês-dublin-eventos-sociais' => 'escola-de-inglês-dublin-eventos-sociais',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'goodnex' => array(
        'disable' => array(
          'header_left' => 0,
          'header_right' => 0,
          'header_menu' => 0,
          'header_search' => 0,
          'slider-home' => 0,
          'before_content_no_wrap' => 0,
          'before_content' => 0,
          'content' => 0,
          'after_content' => 0,
          'after_content_no_wrap' => 0,
          'sidebar_left' => 0,
          'sidebar_right' => 0,
          'footer_1' => 0,
          'footer_2' => 0,
          'footer_3' => 0,
          'footer_4' => 0,
          'footer_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'goodnex_sub' => array(
        'disable' => array(
          'sidebar_left' => 'sidebar_left',
          'sidebar_right' => 'sidebar_right',
          'header_top_left' => 0,
          'header_top_right' => 0,
          'header_left' => 0,
          'header_right' => 0,
          'header_menu' => 0,
          'header_search' => 0,
          'slider-home' => 0,
          'before_content_no_wrap' => 0,
          'before_content' => 0,
          'content' => 0,
          'after_content' => 0,
          'after_content_no_wrap' => 0,
          'footer_1' => 0,
          'footer_2' => 0,
          'footer_3' => 0,
          'footer_4' => 0,
          'footer_bottom' => 0,
          'footer_social' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Full Screen - No Right Sidebar');
  t('full-screen');
  $export['full_screen'] = $context;

  return $export;
}
