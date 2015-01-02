<?php
/**
 * @file
 * ulearn_special_courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulearn_special_courses_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'special_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Special courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Special courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix outset content-tabs';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No special courses available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_special_course_reference_product_id']['id'] = 'field_special_course_reference_product_id';
  $handler->display->display_options['relationships']['field_special_course_reference_product_id']['table'] = 'field_data_field_special_course_reference';
  $handler->display->display_options['relationships']['field_special_course_reference_product_id']['field'] = 'field_special_course_reference_product_id';
  /* Field: Content: Picture */
  $handler->display->display_options['fields']['field_course_display_picture']['id'] = 'field_course_display_picture';
  $handler->display->display_options['fields']['field_course_display_picture']['table'] = 'field_data_field_course_display_picture';
  $handler->display->display_options['fields']['field_course_display_picture']['field'] = 'field_course_display_picture';
  $handler->display->display_options['fields']['field_course_display_picture']['label'] = '';
  $handler->display->display_options['fields']['field_course_display_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_display_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_course_display_picture']['settings'] = array(
    'image_style' => 'adaptive_thumbnail',
    'image_link' => 'content',
    'field_formatter_label' => '',
  );
  $handler->display->display_options['fields']['field_course_display_picture']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_course_display_picture']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_special_course_reference_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['element_type'] = 'div';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['type'] = 'commerce_price_formatted_components';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'field_formatter_label' => '',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_special_course_reference_product_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'special_courses';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_course' => 'special_course',
  );

  /* Display: Special courses page */
  $handler = $view->new_display('page', 'Special courses page', 'page_special_courses');
  $handler->display->display_options['path'] = 'special-courses';
  $export['special_courses'] = $view;

  return $export;
}
