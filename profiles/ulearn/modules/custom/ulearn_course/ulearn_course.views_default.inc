<?php
/**
 * @file
 * ulearn_course.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulearn_course_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_listing_admin';
  $view->description = 'View of courses created by logged in user. Mainly used for administrative purpose.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administrative course listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    174086182 => '174086182',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'nothing' => 'edit_node',
    'nothing_1' => 'edit_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No courses available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Registrations';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'course/[nid]/registrations';
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = 'View course registrations';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Export';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'course/[nid]/registrations/export';
  $handler->display->display_options['fields']['nothing_1']['alter']['alt'] = 'Export course registrations into XLS.';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'current_user_or_role';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate_options']['roles'] = array(
    30037204 => '30037204',
    174086182 => '174086182',
  );
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'access denied';
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
    'course_display' => 'course_display',
    'special_course' => 'special_course',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Course Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    174086182 => 0,
    88601972 => 0,
    66784200 => 0,
  );

  /* Display: Administrative course listing block */
  $handler = $view->new_display('block', 'Administrative course listing block', 'block_admin_course_listing');

  /* Display: All courses listing */
  $handler = $view->new_display('page', 'All courses listing', 'page_course_registrations_all');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'admin/courses-all';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Courses';
  $handler->display->display_options['menu']['description'] = 'Courses';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['course_listing_admin'] = $view;

  $view = new view();
  $view->name = 'course_registrations_partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Course registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course registrations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'views_access_callback';
  $handler->display->display_options['access']['views_access_callback'] = 'ulearn_course_registration_view_access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'registration_id' => 'registration_id',
    'field_registrant_first_name' => 'field_registrant_first_name',
    'field_registrant_last_name' => 'field_registrant_first_name',
    'mail' => 'mail',
    'created' => 'created',
    'state' => 'state',
    'balance' => 'balance',
    'commerce_order_total' => 'commerce_order_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'registration_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_registrant_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_registrant_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'balance' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No registrations available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Registration: Commerce Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'registration';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['relationship'] = 'order_id';
  /* Relationship: Commerce Line item: Referenced products */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Relationship: Commerce Product: Referencing Node */
  $handler->display->display_options['relationships']['field_course_product_reference']['id'] = 'field_course_product_reference';
  $handler->display->display_options['relationships']['field_course_product_reference']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_course_product_reference']['field'] = 'field_course_product_reference';
  $handler->display->display_options['relationships']['field_course_product_reference']['relationship'] = 'commerce_product_product_id';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Sr. no.';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Registration: First name */
  $handler->display->display_options['fields']['field_registrant_first_name']['id'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['table'] = 'field_data_field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['field'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_registrant_first_name']['element_label_colon'] = FALSE;
  /* Field: Registration: Last name */
  $handler->display->display_options['fields']['field_registrant_last_name']['id'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['table'] = 'field_data_field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['field'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_registrant_last_name']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['render_as_link'] = 0;
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date registered';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ulearn_date_format';
  /* Field: Registration: State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Course fee';
  $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Line Item: ULearn share amount */
  $handler->display->display_options['fields']['ulearn_course_share_amount']['id'] = 'ulearn_course_share_amount';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['field'] = 'ulearn_course_share_amount';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['label'] = 'ULearn %';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ulearn_course_share_amount']['ulearn_share_amount_display'] = 'currency_format_with_percentage';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'registration/[registration_id]';
  $handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Phone number */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  /* Sort criterion: Registration: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'registration';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_course_product_reference';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Course registration page */
  $handler = $view->new_display('page', 'Course registration page', 'page_course_registrations');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'registration_id' => 'registration_id',
    'counter' => 'counter',
    'field_registrant_first_name' => 'field_registrant_first_name',
    'field_registrant_last_name' => 'field_registrant_first_name',
    'mail' => 'mail',
    'field_user_phone' => 'field_user_phone',
    'created' => 'created',
    'state' => 'state',
    'commerce_unit_price' => 'commerce_unit_price',
    'ulearn_course_share_amount' => 'ulearn_course_share_amount',
    'nothing' => 'nothing',
    'view_order' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'registration_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_registrant_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_registrant_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_unit_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ulearn_course_share_amount' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_order' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Sr. no.';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Registration: First name */
  $handler->display->display_options['fields']['field_registrant_first_name']['id'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['table'] = 'field_data_field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['field'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_registrant_first_name']['element_label_colon'] = FALSE;
  /* Field: Registration: Last name */
  $handler->display->display_options['fields']['field_registrant_last_name']['id'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['table'] = 'field_data_field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['field'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_registrant_last_name']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['render_as_link'] = 0;
  /* Field: Field: Phone number */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['element_label_colon'] = FALSE;
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date registered';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ulearn_date_format';
  /* Field: Registration: State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Course fee';
  $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Line Item: ULearn share amount */
  $handler->display->display_options['fields']['ulearn_course_share_amount']['id'] = 'ulearn_course_share_amount';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['field'] = 'ulearn_course_share_amount';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['label'] = 'ULearn %';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ulearn_course_share_amount']['ulearn_share_amount_display'] = 'currency_format_with_percentage';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View registration';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'registration/[registration_id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Link */
  $handler->display->display_options['fields']['view_order']['id'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['view_order']['field'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['view_order']['label'] = '';
  $handler->display->display_options['fields']['view_order']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_order']['text'] = 'View order';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_course_product_reference';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Registrations for %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'course/%/registrations';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_course_registrations');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%1-title-%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Registration: Commerce Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'registration';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['relationship'] = 'order_id';
  /* Relationship: Commerce Line item: Referenced products */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Relationship: Commerce Product: Referencing Node */
  $handler->display->display_options['relationships']['field_course_product_reference']['id'] = 'field_course_product_reference';
  $handler->display->display_options['relationships']['field_course_product_reference']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_course_product_reference']['field'] = 'field_course_product_reference';
  $handler->display->display_options['relationships']['field_course_product_reference']['relationship'] = 'commerce_product_product_id';
  /* Relationship: Commerce Order: Representative payment transaction */
  $handler->display->display_options['relationships']['payment_transaction_representative']['id'] = 'payment_transaction_representative';
  $handler->display->display_options['relationships']['payment_transaction_representative']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['payment_transaction_representative']['field'] = 'payment_transaction_representative';
  $handler->display->display_options['relationships']['payment_transaction_representative']['relationship'] = 'order_id';
  $handler->display->display_options['relationships']['payment_transaction_representative']['subquery_sort'] = 'commerce_payment_transaction.transaction_id';
  $handler->display->display_options['relationships']['payment_transaction_representative']['subquery_view'] = '';
  $handler->display->display_options['relationships']['payment_transaction_representative']['subquery_namespace'] = '';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Sr. no.';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Registration: First name */
  $handler->display->display_options['fields']['field_registrant_first_name']['id'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['table'] = 'field_data_field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['field'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_registrant_first_name']['element_label_colon'] = FALSE;
  /* Field: Registration: Last name */
  $handler->display->display_options['fields']['field_registrant_last_name']['id'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['table'] = 'field_data_field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['field'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_registrant_last_name']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['render_as_link'] = 0;
  /* Field: Field: Phone number */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['element_label_colon'] = FALSE;
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date registered';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ulearn_date_format';
  /* Field: Registration: State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Course fee';
  $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Line Item: ULearn share amount */
  $handler->display->display_options['fields']['ulearn_course_share_amount']['id'] = 'ulearn_course_share_amount';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['field'] = 'ulearn_course_share_amount';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['label'] = 'ULearn %';
  $handler->display->display_options['fields']['ulearn_course_share_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ulearn_course_share_amount']['ulearn_share_amount_display'] = 'currency_format_with_percentage';
  /* Field: Commerce Payment Transaction: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'payment_transaction_representative';
  $handler->display->display_options['fields']['status']['label'] = 'Payment status';
  $handler->display->display_options['fields']['status']['display_style'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_course_product_reference';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Registrations for %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'course/%/registrations/export';
  $handler->display->display_options['displays'] = array(
    'page_course_registrations' => 'page_course_registrations',
    'default' => 0,
  );
  $export['course_registrations_partners'] = $view;

  $view = new view();
  $view->name = 'course_schedules';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Course schedules';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course schedules';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['firstDay'] = '1';
  $handler->display->display_options['style_options']['weekMode'] = 'liquid';
  $handler->display->display_options['style_options']['sameWindow'] = TRUE;
  $handler->display->display_options['style_options']['editable'] = TRUE;
  $handler->display->display_options['style_options']['fields']['title_field'] = 'rendered_entity';
  $handler->display->display_options['style_options']['fields']['title'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No course registrations.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  /* Field: Registration: Enrollment date */
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['id'] = 'field_registrant_enrollment_date';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['table'] = 'field_data_field_registrant_enrollment_date';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['field'] = 'field_registrant_enrollment_date';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['settings'] = array(
    'format_type' => 'ulearn_date_format',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Registration: Rendered Registration */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_registration';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Contextual filter: Registration: Author_uid */
  $handler->display->display_options['arguments']['author_uid']['id'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['table'] = 'registration';
  $handler->display->display_options['arguments']['author_uid']['field'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['author_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['author_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['author_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['author_uid']['summary_options']['items_per_page'] = '25';

  /* Display: Course calender age */
  $handler = $view->new_display('page', 'Course calender age', 'page');
  $handler->display->display_options['path'] = 'course-schedules';
  $export['course_schedules'] = $view;

  $view = new view();
  $view->name = 'courses';
  $view->description = 'All Displays for ULearn\'s Courses';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ULearn English School Dublin Course';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_course_type_tid_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'mycoursetable';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_order' => 'field_order',
    'title' => 'title',
    'field_course_type' => 'field_course_type',
    'add_to_cart_form' => 'add_to_cart_form',
    'commerce_price' => 'commerce_price',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_order' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'add_to_cart_form' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="coursehead"><h3 style="color:#6f6f6f">Course Calculator</h3><div class="calc"><img src="/sites/default/files/images/course/calculator.png" alt="" style="width: 64px; height: 64px; visibility: visible;"></div></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No course available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_course_product_reference_product_id']['id'] = 'field_course_product_reference_product_id';
  $handler->display->display_options['relationships']['field_course_product_reference_product_id']['table'] = 'field_data_field_course_product_reference';
  $handler->display->display_options['relationships']['field_course_product_reference_product_id']['field'] = 'field_course_product_reference_product_id';
  $handler->display->display_options['relationships']['field_course_product_reference_product_id']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_rel'] = '';
  /* Field: Field: Order */
  $handler->display->display_options['fields']['field_order']['id'] = 'field_order';
  $handler->display->display_options['fields']['field_order']['table'] = 'field_data_field_order';
  $handler->display->display_options['fields']['field_order']['field'] = 'field_order';
  $handler->display->display_options['fields']['field_order']['label'] = '';
  $handler->display->display_options['fields']['field_order']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_order']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_order']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
    'field_formatter_label' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Course';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_class'] = 'view-course-title';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'view-course-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Course Type */
  $handler->display->display_options['fields']['field_course_type']['id'] = 'field_course_type';
  $handler->display->display_options['fields']['field_course_type']['table'] = 'field_data_field_course_type';
  $handler->display->display_options['fields']['field_course_type']['field'] = 'field_course_type';
  $handler->display->display_options['fields']['field_course_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_type']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_course_type']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_course_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_type']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_course_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_course_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_course_type']['settings'] = array(
    'field_formatter_label' => '',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_course_product_reference_product_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = 'Start date / Weeks';
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'general_courses';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Registration fee';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '€!1';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'course-registration-fee';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_course_product_reference_product_id';
  $handler->display->display_options['fields']['commerce_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_price']['alter']['text'] = '<div class="node-[nid]-product-commerce-price-wrapper">[commerce_price]</div>';
  $handler->display->display_options['fields']['commerce_price']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['type'] = 'commerce_price_formatted_components';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'field_formatter_label' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="eleven columns">
[add_to_cart_form]
<div class="node-[nid]-product-commerce-price-wrapper">[commerce_price]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Field: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['relationship'] = 'field_course_product_reference_product_id';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'variable';
  $handler->display->display_options['arguments']['null']['default_argument_options']['variable'] = 'ulearn_course_default_registration_fee';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    51 => '51',
    53 => '53',
    54 => '54',
    52 => '52',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';

  /* Display: Search course */
  $handler = $view->new_display('page', 'Search course', 'page_search_course');
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
    'course_display' => 'course_display',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    174086182 => 0,
    66784200 => 0,
    236804498 => 0,
  );
  /* Filter criterion: Content: Course Type (field_course_type) */
  $handler->display->display_options['filters']['field_course_type_tid_1']['id'] = 'field_course_type_tid_1';
  $handler->display->display_options['filters']['field_course_type_tid_1']['table'] = 'field_data_field_course_type';
  $handler->display->display_options['filters']['field_course_type_tid_1']['field'] = 'field_course_type_tid';
  $handler->display->display_options['filters']['field_course_type_tid_1']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    51 => '51',
    53 => '53',
    54 => '54',
    52 => '52',
  );
  $handler->display->display_options['filters']['field_course_type_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_course_type_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['operator_id'] = 'field_course_type_tid_1_op';
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['operator'] = 'field_course_type_tid_1_op';
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['identifier'] = 'field_course_type_tid_1';
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    174086182 => 0,
    66784200 => 0,
    236804498 => 0,
  );
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['label'] = 'Course Type (field_course_type)';
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['identifier'] = 'field_course_type_tid_1';
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_course_type_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_type_tid_1']['vocabulary'] = 'course_type';
  /* Filter criterion: Content translation: Select translation */
  $handler->display->display_options['filters']['select_translation']['id'] = 'select_translation';
  $handler->display->display_options['filters']['select_translation']['table'] = 'node';
  $handler->display->display_options['filters']['select_translation']['field'] = 'select_translation';
  $handler->display->display_options['path'] = 'courses';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Courses';
  $handler->display->display_options['menu']['description'] = 'Overview of ULearn Courses';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: All Course Prices */
  $handler = $view->new_display('block', 'All Course Prices', 'block_1');
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
    'course_display' => 'course_display',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'All Course Prices';

  /* Display: General English (Block) */
  $handler = $view->new_display('block', 'General English (Block)', 'block_2');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    1 => '1',
    51 => '51',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';
  $handler->display->display_options['block_description'] = 'Course - General English';

  /* Display: Exams (Block) */
  $handler = $view->new_display('block', 'Exams (Block)', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';
  $handler->display->display_options['block_description'] = 'Course - Exams';

  /* Display: Visa / Non-EU (Block) */
  $handler = $view->new_display('block', 'Visa / Non-EU (Block)', 'block_4');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';
  $handler->display->display_options['block_description'] = 'Course - Visa / Non-EU';

  /* Display: General English (Tab) */
  $handler = $view->new_display('page', 'General English (Tab)', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'General English';
  $handler->display->display_options['display_description'] = 'General Page (Displayed as a Tab)';
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';
  $handler->display->display_options['path'] = 'courses/general-english';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'General English';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Work Study Non-EU (Tab) */
  $handler = $view->new_display('page', 'Work Study Non-EU (Tab)', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Work Study Non-EU';
  $handler->display->display_options['display_description'] = 'Work Study Visa courses at ULearn English School';
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';
  $handler->display->display_options['path'] = 'courses/exams';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Work-Study';
  $handler->display->display_options['menu']['description'] = 'Non-EU students';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Exams (Tab) */
  $handler = $view->new_display('page', 'Exams (Tab)', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Exams';
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';
  $handler->display->display_options['path'] = 'courses/exams';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Exams';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Other Courses (Tab) */
  $handler = $view->new_display('page', 'Other Courses (Tab)', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'More ULearn Courses';
  $handler->display->display_options['path'] = 'courses/other-courses';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Other Courses';
  $handler->display->display_options['menu']['description'] = 'Individual,Business, Juniors and Online Lessons';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'menu-menu-tabs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Other Courses (Block) */
  $handler = $view->new_display('block', 'Other Courses (Block)', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Other Courses';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Order (field_order) */
  $handler->display->display_options['sorts']['field_order_value']['id'] = 'field_order_value';
  $handler->display->display_options['sorts']['field_order_value']['table'] = 'field_data_field_order';
  $handler->display->display_options['sorts']['field_order_value']['field'] = 'field_order_value';
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
    'course_display' => 'course_display',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    53 => '53',
    54 => '54',
    52 => '52',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'course_type';
  $handler->display->display_options['block_description'] = 'Other Courses (Block)';

  /* Display: Search Course (Block) */
  $handler = $view->new_display('block', 'Search Course (Block)', 'block_6');
  $handler->display->display_options['block_description'] = 'Search Course Block';

  /* Display: Booking (Page) */
  $handler = $view->new_display('page', 'Booking (Page)', 'booking');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'ULearn English School Dublin Booking';
  $handler->display->display_options['exposed_block'] = TRUE;
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
    'course_display' => 'course_display',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    174086182 => 0,
    66784200 => 0,
    236804498 => 0,
  );
  /* Filter criterion: Content: Course Type (field_course_type) */
  $handler->display->display_options['filters']['field_course_type_tid_1']['id'] = 'field_course_type_tid_1';
  $handler->display->display_options['filters']['field_course_type_tid_1']['table'] = 'field_data_field_course_type';
  $handler->display->display_options['filters']['field_course_type_tid_1']['field'] = 'field_course_type_tid';
  $handler->display->display_options['filters']['field_course_type_tid_1']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    51 => '51',
    53 => '53',
    54 => '54',
    52 => '52',
  );
  $handler->display->display_options['filters']['field_course_type_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_course_type_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['operator_id'] = 'field_course_type_tid_1_op';
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['label'] = 'Course Type';
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['operator'] = 'field_course_type_tid_1_op';
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['identifier'] = 'field_course_type_tid_1';
  $handler->display->display_options['filters']['field_course_type_tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    174086182 => 0,
    66784200 => 0,
    236804498 => 0,
  );
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['label'] = 'Course Type (field_course_type)';
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['identifier'] = 'field_course_type_tid_1';
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_course_type_tid_1']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_course_type_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_type_tid_1']['vocabulary'] = 'course_type';
  $handler->display->display_options['path'] = 'booking';
  $handler->display->display_options['menu']['title'] = 'Booking';
  $handler->display->display_options['menu']['description'] = 'Click Here to Book!';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['courses'] = $view;

  $view = new view();
  $view->name = 'registration_display';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Registration display';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Registration details';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Invalid registration data.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Registration: Commerce Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'registration';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['relationship'] = 'order_id';
  /* Relationship: Commerce Line item: Referenced products */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Relationship: Commerce Product: Referencing Node */
  $handler->display->display_options['relationships']['field_course_product_reference']['id'] = 'field_course_product_reference';
  $handler->display->display_options['relationships']['field_course_product_reference']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_course_product_reference']['field'] = 'field_course_product_reference';
  $handler->display->display_options['relationships']['field_course_product_reference']['relationship'] = 'commerce_product_product_id';
  /* Relationship: Commerce Order: Payment Transaction */
  $handler->display->display_options['relationships']['payment_transaction']['id'] = 'payment_transaction';
  $handler->display->display_options['relationships']['payment_transaction']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['payment_transaction']['field'] = 'payment_transaction';
  $handler->display->display_options['relationships']['payment_transaction']['relationship'] = 'order_id';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Course details';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'title',
    1 => 'field_course_type',
    2 => 'commerce_unit_price',
    3 => 'field_course_school',
    4 => 'body',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['collapsible'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_course_product_reference';
  $handler->display->display_options['fields']['title']['label'] = 'Course name';
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'strong';
  /* Field: Content: Course Type */
  $handler->display->display_options['fields']['field_course_type']['id'] = 'field_course_type';
  $handler->display->display_options['fields']['field_course_type']['table'] = 'field_data_field_course_type';
  $handler->display->display_options['fields']['field_course_type']['field'] = 'field_course_type';
  $handler->display->display_options['fields']['field_course_type']['relationship'] = 'field_course_product_reference';
  $handler->display->display_options['fields']['field_course_type']['label'] = 'Course type';
  $handler->display->display_options['fields']['field_course_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_course_type']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_course_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Course fee';
  $handler->display->display_options['fields']['commerce_unit_price']['element_type'] = 'span';
  $handler->display->display_options['fields']['commerce_unit_price']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_course_product_reference';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Registration details';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_registrant_first_name',
    1 => 'field_registrant_last_name',
    2 => 'nothing',
    3 => 'anon_mail',
    4 => 'field_user_phone',
    5 => 'field_registrant_enrollment_date',
    6 => 'field_registrant_address',
    7 => 'created',
    8 => 'state',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
  /* Field: Registration: First name */
  $handler->display->display_options['fields']['field_registrant_first_name']['id'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['table'] = 'field_data_field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['field'] = 'field_registrant_first_name';
  $handler->display->display_options['fields']['field_registrant_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_registrant_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registrant_first_name']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_registrant_first_name']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_registrant_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registrant_first_name']['element_wrapper_type'] = 'span';
  /* Field: Registration: Last name */
  $handler->display->display_options['fields']['field_registrant_last_name']['id'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['table'] = 'field_data_field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['field'] = 'field_registrant_last_name';
  $handler->display->display_options['fields']['field_registrant_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_registrant_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registrant_last_name']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_registrant_last_name']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_registrant_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registrant_last_name']['element_wrapper_type'] = 'span';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_registrant_first_name] [field_registrant_last_name]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'span';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'strong';
  /* Field: Registration: Anonymous e-mail */
  $handler->display->display_options['fields']['anon_mail']['id'] = 'anon_mail';
  $handler->display->display_options['fields']['anon_mail']['table'] = 'registration';
  $handler->display->display_options['fields']['anon_mail']['field'] = 'anon_mail';
  $handler->display->display_options['fields']['anon_mail']['label'] = 'E-mail';
  $handler->display->display_options['fields']['anon_mail']['element_type'] = 'span';
  $handler->display->display_options['fields']['anon_mail']['element_label_type'] = 'strong';
  /* Field: Field: Phone number */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_phone']['element_label_type'] = 'strong';
  /* Field: Registration: Enrollment date */
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['id'] = 'field_registrant_enrollment_date';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['table'] = 'field_data_field_registrant_enrollment_date';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['field'] = 'field_registrant_enrollment_date';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['type'] = 'custom_formatters_date_with_number_of_weeks';
  $handler->display->display_options['fields']['field_registrant_enrollment_date']['settings'] = array(
    'format_type' => 'ulearn_date_format',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Registration: Address */
  $handler->display->display_options['fields']['field_registrant_address']['id'] = 'field_registrant_address';
  $handler->display->display_options['fields']['field_registrant_address']['table'] = 'field_data_field_registrant_address';
  $handler->display->display_options['fields']['field_registrant_address']['field'] = 'field_registrant_address';
  $handler->display->display_options['fields']['field_registrant_address']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_registrant_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_registrant_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date registered';
  $handler->display->display_options['fields']['created']['element_type'] = 'span';
  $handler->display->display_options['fields']['created']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['created']['date_format'] = 'ulearn_date_format';
  /* Field: Registration: State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['element_type'] = 'span';
  $handler->display->display_options['fields']['state']['element_label_type'] = 'strong';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['label'] = 'Payment details';
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
    0 => 'commerce_unit_price_1',
    1 => 'status',
    2 => 'ulearn_commerce_payment_instructions',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['collapsible'] = 1;
  /* Field: Commerce Line item: Unit price */
  $handler->display->display_options['fields']['commerce_unit_price_1']['id'] = 'commerce_unit_price_1';
  $handler->display->display_options['fields']['commerce_unit_price_1']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price_1']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price_1']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_unit_price_1']['label'] = 'Amount paid';
  $handler->display->display_options['fields']['commerce_unit_price_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['commerce_unit_price_1']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['commerce_unit_price_1']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price_1']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Payment Transaction: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'payment_transaction';
  $handler->display->display_options['fields']['status']['label'] = 'Payment status';
  $handler->display->display_options['fields']['status']['element_type'] = 'span';
  $handler->display->display_options['fields']['status']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['status']['display_style'] = 'title';
  /* Field: Commerce Order: Payment instructions */
  $handler->display->display_options['fields']['ulearn_commerce_payment_instructions']['id'] = 'ulearn_commerce_payment_instructions';
  $handler->display->display_options['fields']['ulearn_commerce_payment_instructions']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['ulearn_commerce_payment_instructions']['field'] = 'ulearn_commerce_payment_instructions';
  $handler->display->display_options['fields']['ulearn_commerce_payment_instructions']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['ulearn_commerce_payment_instructions']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ulearn_commerce_payment_instructions']['hide_empty'] = TRUE;
  /* Sort criterion: Commerce Payment Transaction: Transaction ID */
  $handler->display->display_options['sorts']['transaction_id']['id'] = 'transaction_id';
  $handler->display->display_options['sorts']['transaction_id']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['sorts']['transaction_id']['field'] = 'transaction_id';
  $handler->display->display_options['sorts']['transaction_id']['relationship'] = 'payment_transaction';
  $handler->display->display_options['sorts']['transaction_id']['order'] = 'DESC';
  /* Contextual filter: Registration: Registration ID */
  $handler->display->display_options['arguments']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['arguments']['registration_id']['table'] = 'registration';
  $handler->display->display_options['arguments']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['arguments']['registration_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['registration_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['registration_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['registration_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['registration_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['registration_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'commerce_product_product_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
    'special_course' => 'special_course',
  );
  $export['registration_display'] = $view;

  $view = new view();
  $view->name = 'school_course_schedules';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'School course schedules';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'School course schedules';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['firstDay'] = '1';
  $handler->display->display_options['style_options']['weekMode'] = 'liquid';
  $handler->display->display_options['style_options']['sameWindow'] = TRUE;
  $handler->display->display_options['style_options']['editable'] = TRUE;
  $handler->display->display_options['style_options']['fields']['title'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No scheduled courses for this school.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Course date */
  $handler->display->display_options['fields']['field_course_date']['id'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['table'] = 'field_data_field_course_date';
  $handler->display->display_options['fields']['field_course_date']['field'] = 'field_course_date';
  $handler->display->display_options['fields']['field_course_date']['label'] = '';
  $handler->display->display_options['fields']['field_course_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_date']['settings'] = array(
    'format_type' => 'ulearn_date_format',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_course_school_nid']['id'] = 'field_course_school_nid';
  $handler->display->display_options['arguments']['field_course_school_nid']['table'] = 'field_data_field_course_school';
  $handler->display->display_options['arguments']['field_course_school_nid']['field'] = 'field_course_school_nid';
  $handler->display->display_options['arguments']['field_course_school_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_course_school_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_course_school_nid']['title'] = 'Course schedule for %1';
  $handler->display->display_options['arguments']['field_course_school_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_course_school_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_school_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_school_nid']['summary_options']['items_per_page'] = '25';
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
    'course_display' => 'course_display',
  );

  /* Display: School course schedule */
  $handler = $view->new_display('page', 'School course schedule', 'page');
  $handler->display->display_options['path'] = 'school/%/course-schedules';
  $export['school_course_schedules'] = $view;

  $view = new view();
  $view->name = 'student_course_registrations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Course registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course registrations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    30037204 => '30037204',
    66784200 => '66784200',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No registration available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  /* Field: Registration: Rendered Registration */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_registration';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Registration';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date registered';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ulearn_date_format';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'registration/[registration_id]';
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = 'View course registration';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: Registration: Author_uid */
  $handler->display->display_options['arguments']['author_uid']['id'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['table'] = 'registration';
  $handler->display->display_options['arguments']['author_uid']['field'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['author_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['author_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['author_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['author_uid']['summary_options']['items_per_page'] = '25';

  /* Display: Student registration page */
  $handler = $view->new_display('page', 'Student registration page', 'page_student_registration');
  $handler->display->display_options['path'] = 'course-registrations';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Registrations';
  $handler->display->display_options['menu']['description'] = 'View course registrations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['student_course_registrations'] = $view;

  return $export;
}
