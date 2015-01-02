<?php
/**
 * @file
 * ulearn_blog.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ulearn_blog_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_blog_school'
  $field_bases['field_blog_school'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blog_school',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'profile2_private' => FALSE,
      'referenceable_types' => array(
        'article' => 0,
        'blog' => 0,
        'course_display' => 0,
        'page' => 0,
        'product_display' => 0,
        'school' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'school_references',
        'view_name' => 'school_listing',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
