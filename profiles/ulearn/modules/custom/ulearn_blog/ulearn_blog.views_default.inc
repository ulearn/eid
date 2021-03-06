<?php
/**
 * @file
 * ulearn_blog.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulearn_blog_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blogs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blogs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blogs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'blog' => 'blog',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_blog_school_nid']['id'] = 'field_blog_school_nid';
  $handler->display->display_options['filters']['field_blog_school_nid']['table'] = 'field_data_field_blog_school';
  $handler->display->display_options['filters']['field_blog_school_nid']['field'] = 'field_blog_school_nid';
  $handler->display->display_options['filters']['field_blog_school_nid']['operator'] = 'empty';

  /* Display: Blog Listing */
  $handler = $view->new_display('page', 'Blog Listing', 'page');
  $handler->display->display_options['display_description'] = 'Blog Listing';
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
    'blog' => 'blog',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_blog_school_nid']['id'] = 'field_blog_school_nid';
  $handler->display->display_options['filters']['field_blog_school_nid']['table'] = 'field_data_field_blog_school';
  $handler->display->display_options['filters']['field_blog_school_nid']['field'] = 'field_blog_school_nid';
  $handler->display->display_options['filters']['field_blog_school_nid']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'blogs';

  /* Display: Blogs */
  $handler = $view->new_display('block', 'Blogs', 'block_blog_listing');
  $handler->display->display_options['display_description'] = 'School Related Blogs';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_blog_school_nid']['id'] = 'field_blog_school_nid';
  $handler->display->display_options['arguments']['field_blog_school_nid']['table'] = 'field_data_field_blog_school';
  $handler->display->display_options['arguments']['field_blog_school_nid']['field'] = 'field_blog_school_nid';
  $handler->display->display_options['arguments']['field_blog_school_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_blog_school_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_blog_school_nid']['title'] = 'Blogs from %1';
  $handler->display->display_options['arguments']['field_blog_school_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_blog_school_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_school_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_school_nid']['summary_options']['items_per_page'] = '25';
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
    'blog' => 'blog',
  );
  $export['blogs'] = $view;

  return $export;
}
