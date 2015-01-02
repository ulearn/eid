<?php
/**
 * @file
 * ulearn_accommodation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulearn_accommodation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'accommodation_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Accommodation data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accommodation details';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view ulearn_course_registration registration';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'fluid_grid';
  $handler->display->display_options['style_options']['items_width'] = '';
  $handler->display->display_options['style_options']['advanced_layout'] = array(
    'css3' => TRUE,
  );
  $handler->display->display_options['style_options']['box_shadow'] = '1';
  $handler->display->display_options['style_options']['border_radius'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No accommodation selected for this registration.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Registration: Commerce Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'registration';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['required'] = TRUE;
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['relationship'] = 'order_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Relationship: Commerce Line item: Referenced products */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['required'] = TRUE;
  /* Relationship: Commerce Product: Referencing Node */
  $handler->display->display_options['relationships']['field_accommodation_reference']['id'] = 'field_accommodation_reference';
  $handler->display->display_options['relationships']['field_accommodation_reference']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_accommodation_reference']['field'] = 'field_accommodation_reference';
  $handler->display->display_options['relationships']['field_accommodation_reference']['relationship'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['field_accommodation_reference']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_accommodation_reference';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_accommodation_type']['id'] = 'field_accommodation_type';
  $handler->display->display_options['fields']['field_accommodation_type']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['fields']['field_accommodation_type']['field'] = 'field_accommodation_type';
  $handler->display->display_options['fields']['field_accommodation_type']['relationship'] = 'field_accommodation_reference';
  /* Field: Commerce Line item: Start Date */
  $handler->display->display_options['fields']['field_accommodation_dates']['id'] = 'field_accommodation_dates';
  $handler->display->display_options['fields']['field_accommodation_dates']['table'] = 'field_data_field_accommodation_dates';
  $handler->display->display_options['fields']['field_accommodation_dates']['field'] = 'field_accommodation_dates';
  $handler->display->display_options['fields']['field_accommodation_dates']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['field_accommodation_dates']['settings'] = array(
    'format_type' => 'ulearn_date_format',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Contextual filter: Registration: Registration ID */
  $handler->display->display_options['arguments']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['arguments']['registration_id']['table'] = 'registration';
  $handler->display->display_options['arguments']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['arguments']['registration_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['registration_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['registration_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['registration_id']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['registration_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['registration_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['registration_id']['summary_options']['items_per_page'] = '25';

  /* Display: Accommodation details block */
  $handler = $view->new_display('block', 'Accommodation details block', 'block_accommodation_data');
  $handler->display->display_options['block_description'] = 'Accomm Details';
  $export['accommodation_data'] = $view;

  $view = new view();
  $view->name = 'accommodations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Accommodation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Accommodation';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix outset content-tabs';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = 'outset';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No accommodations added yet.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_accommodation_reference_product_id']['id'] = 'field_accommodation_reference_product_id';
  $handler->display->display_options['relationships']['field_accommodation_reference_product_id']['table'] = 'field_data_field_accommodation_reference';
  $handler->display->display_options['relationships']['field_accommodation_reference_product_id']['field'] = 'field_accommodation_reference_product_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_link_to__node_1']['id'] = 'reverse_field_link_to__node_1';
  $handler->display->display_options['relationships']['reverse_field_link_to__node_1']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_link_to__node_1']['field'] = 'reverse_field_link_to__node';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_accommodation_reference_product_id_1']['id'] = 'field_accommodation_reference_product_id_1';
  $handler->display->display_options['relationships']['field_accommodation_reference_product_id_1']['table'] = 'field_data_field_accommodation_reference';
  $handler->display->display_options['relationships']['field_accommodation_reference_product_id_1']['field'] = 'field_accommodation_reference_product_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_link_to__target_id']['id'] = 'field_link_to__target_id';
  $handler->display->display_options['relationships']['field_link_to__target_id']['table'] = 'field_data_field_link_to_';
  $handler->display->display_options['relationships']['field_link_to__target_id']['field'] = 'field_link_to__target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_accommodation_type']['id'] = 'field_accommodation_type';
  $handler->display->display_options['fields']['field_accommodation_type']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['fields']['field_accommodation_type']['field'] = 'field_accommodation_type';
  $handler->display->display_options['fields']['field_accommodation_type']['label'] = '';
  $handler->display->display_options['fields']['field_accommodation_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_accommodation_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_accommodation_type']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_accommodation_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accommodation_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_accommodation_type']['settings'] = array(
    'field_formatter_label' => '',
  );
  $handler->display->display_options['fields']['field_accommodation_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_accommodation_type']['multi_type'] = 'ul';
  /* Field: Content: Video */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['relationship'] = 'reverse_field_link_to__node_1';
  $handler->display->display_options['fields']['field_video']['label'] = '';
  $handler->display->display_options['fields']['field_video']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_video']['alter']['text'] = '<div class="view-accomm-video three columns">
[field_video]
</div>';
  $handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_video']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'file_view_mode' => 'teaser',
    'field_formatter_label' => '',
  );
  /* Field: Content: Picture */
  $handler->display->display_options['fields']['field_accommodation_picture']['id'] = 'field_accommodation_picture';
  $handler->display->display_options['fields']['field_accommodation_picture']['table'] = 'field_data_field_accommodation_picture';
  $handler->display->display_options['fields']['field_accommodation_picture']['field'] = 'field_accommodation_picture';
  $handler->display->display_options['fields']['field_accommodation_picture']['label'] = '';
  $handler->display->display_options['fields']['field_accommodation_picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_accommodation_picture']['alter']['text'] = '<div class="three columns">
<div class="preloader">
		<a class="bwWrapper single-image plus-icon" href="[field_accommodation_picture]" rel="folio" title="">
			<img src="[field_accommodation_picture]" alt="" >
		</a>							
	</div><!--/ .preloader-->
</div>';
  $handler->display->display_options['fields']['field_accommodation_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accommodation_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_accommodation_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_accommodation_picture']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_accommodation_picture']['settings'] = array(
    'url_type' => '1',
    'image_style' => 'large',
    'image_link' => '',
    'field_formatter_label' => '',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_accommodation_reference_product_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['text'] = '	<div class="three columns">
	<div class="addtocart-accomm">[add_to_cart_form]</div>
	</div>


';
  $handler->display->display_options['fields']['add_to_cart_form']['element_type'] = 'div';
  $handler->display->display_options['fields']['add_to_cart_form']['element_class'] = 'view-accomm-detail';
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'accommodation';
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_accommodation_reference_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = 'Price Per Week';
  $handler->display->display_options['fields']['commerce_price']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['commerce_price']['element_label_class'] = 'view-accomm-price-label';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['commerce_price']['element_wrapper_class'] = 'view-accomm-price one columns';
  $handler->display->display_options['fields']['commerce_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
    'field_formatter_label' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_class'] = 'six columns view-accomm-body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'field_formatter_label' => '',
  );
  /* Sort criterion: Field: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['relationship'] = 'field_accommodation_reference_product_id';
  /* Sort criterion: Commerce Product: Price (commerce_price:amount) */
  $handler->display->display_options['sorts']['commerce_price_amount']['id'] = 'commerce_price_amount';
  $handler->display->display_options['sorts']['commerce_price_amount']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['sorts']['commerce_price_amount']['field'] = 'commerce_price_amount';
  $handler->display->display_options['sorts']['commerce_price_amount']['relationship'] = 'field_accommodation_reference_product_id';
  $handler->display->display_options['sorts']['commerce_price_amount']['expose']['label'] = 'Price';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'accommodation_display' => 'accommodation_display',
  );
  /* Filter criterion: Content: Type (field_accommodation_type) */
  $handler->display->display_options['filters']['field_accommodation_type_tid']['id'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['field'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['value'] = array(
    6 => '6',
    7 => '7',
    4 => '4',
    5 => '5',
    8 => '8',
  );
  $handler->display->display_options['filters']['field_accommodation_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['vocabulary'] = 'accommodation_type';

  /* Display: Accommodations listing page */
  $handler = $view->new_display('page', 'Accommodations listing page', 'page_accommodation_listing');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'accommodation_display' => 'accommodation_display',
  );
  /* Filter criterion: Content: Type (field_accommodation_type) */
  $handler->display->display_options['filters']['field_accommodation_type_tid']['id'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['field'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['value'] = array(
    6 => '6',
    7 => '7',
    4 => '4',
    5 => '5',
    8 => '8',
  );
  $handler->display->display_options['filters']['field_accommodation_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['vocabulary'] = 'accommodation_type';
  /* Filter criterion: Content translation: Select translation */
  $handler->display->display_options['filters']['select_translation']['id'] = 'select_translation';
  $handler->display->display_options['filters']['select_translation']['table'] = 'node';
  $handler->display->display_options['filters']['select_translation']['field'] = 'select_translation';
  $handler->display->display_options['path'] = 'accommodation';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'accommodation';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Accommodation';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: All Accommodation */
  $handler = $view->new_display('block', 'All Accommodation', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'accommodation_display' => 'accommodation_display',
  );
  /* Filter criterion: Content: Type (field_accommodation_type) */
  $handler->display->display_options['filters']['field_accommodation_type_tid']['id'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['field'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['value'] = array(
    6 => '6',
    7 => '7',
    4 => '4',
    5 => '5',
    8 => '8',
  );
  $handler->display->display_options['filters']['field_accommodation_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['vocabulary'] = 'accommodation_type';
  /* Filter criterion: Content translation: Select translation */
  $handler->display->display_options['filters']['select_translation']['id'] = 'select_translation';
  $handler->display->display_options['filters']['select_translation']['table'] = 'node';
  $handler->display->display_options['filters']['select_translation']['field'] = 'select_translation';
  $handler->display->display_options['block_description'] = 'Accommodation Listings - All';

  /* Display: City Centre Apartments */
  $handler = $view->new_display('page', 'City Centre Apartments', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'City Centre Apartments';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'accommodation_display' => 'accommodation_display',
  );
  /* Filter criterion: Content: Type (field_accommodation_type) */
  $handler->display->display_options['filters']['field_accommodation_type_tid']['id'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['field'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['value'] = array(
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_accommodation_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['vocabulary'] = 'accommodation_type';
  /* Filter criterion: Content translation: Select translation */
  $handler->display->display_options['filters']['select_translation']['id'] = 'select_translation';
  $handler->display->display_options['filters']['select_translation']['table'] = 'node';
  $handler->display->display_options['filters']['select_translation']['field'] = 'select_translation';
  $handler->display->display_options['path'] = 'accommodation/apartments';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'City Centre Apartments';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Host Family */
  $handler = $view->new_display('page', 'Host Family', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Carefully selected Host Families for your language learning stay';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'accommodation_display' => 'accommodation_display',
  );
  /* Filter criterion: Content: Type (field_accommodation_type) */
  $handler->display->display_options['filters']['field_accommodation_type_tid']['id'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['field'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['value'] = array(
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['filters']['field_accommodation_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['vocabulary'] = 'accommodation_type';
  /* Filter criterion: Content translation: Select translation */
  $handler->display->display_options['filters']['select_translation']['id'] = 'select_translation';
  $handler->display->display_options['filters']['select_translation']['table'] = 'node';
  $handler->display->display_options['filters']['select_translation']['field'] = 'select_translation';
  $handler->display->display_options['path'] = 'accommodation/host-family';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Host Families';
  $handler->display->display_options['menu']['description'] = 'Carefully selected and well positioned host famillies in Dublin.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Residence / Hostel */
  $handler = $view->new_display('page', 'Residence / Hostel', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Residence / Hostel';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'accommodation_display' => 'accommodation_display',
  );
  /* Filter criterion: Content: Type (field_accommodation_type) */
  $handler->display->display_options['filters']['field_accommodation_type_tid']['id'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['table'] = 'field_data_field_accommodation_type';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['field'] = 'field_accommodation_type_tid';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['value'] = array(
    8 => '8',
  );
  $handler->display->display_options['filters']['field_accommodation_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_accommodation_type_tid']['vocabulary'] = 'accommodation_type';
  /* Filter criterion: Content translation: Select translation */
  $handler->display->display_options['filters']['select_translation']['id'] = 'select_translation';
  $handler->display->display_options['filters']['select_translation']['table'] = 'node';
  $handler->display->display_options['filters']['select_translation']['field'] = 'select_translation';
  $handler->display->display_options['path'] = 'accommodation/hostel-residence';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Hostel Residence';
  $handler->display->display_options['menu']['description'] = 'Located 5 minutes from ULearn - meet new friends in Dublin\'s best hostel!';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['accommodations'] = $view;

  return $export;
}
