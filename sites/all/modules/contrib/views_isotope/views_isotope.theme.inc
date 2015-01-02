<?php
// $Id:

/**
 * Preprocess function to build the isotope grid
 */
function template_preprocess_views_isotope(&$vars) {
  template_preprocess_views_view_list($vars);
  
  // Extract useful data from view object.
  $view = $vars['view'];
  $handler = $view->style_plugin;
  $fields = $view->field;
  $result = $view->result;
  $rows = &$vars['rows'];
  
  // Define a reference ID for this isotope grid.
  $vars['isotope_id'] = 'views-isotope-' . $view->name . '-' . $view->style_plugin->display->id;
  
  /* FILTERS */
  $vars['isotope_filter_classes'] = array();
  
  // Extract isotope filter fields.
  $filters = array();
  foreach ($fields as $field => $data) {
    if (strpos($data->options['element_class'], 'isotope-filter') !== FALSE)
      $filters[] = $field;
  }
  
  // Build class lists for filtering.
  foreach ($handler->rendered_fields as $index => $row) {
    foreach ($filters as $field) {
      if (isset($row[$field])) {
        $value = $row[$field];
        
        if (strstr($value, ',')) {
          // Check for commas and treat as an array for list of taxonomy terms.
          $classes = explode(',', $value);
          foreach ($classes as $class) {
            if (isset($vars['isotope_filter_classes'][$index]))
              $vars['isotope_filter_classes'][$index] .= ' ' . strtolower(drupal_clean_css_identifier(trim($class)));
            else
              $vars['isotope_filter_classes'][$index] = strtolower(drupal_clean_css_identifier(trim($class)));
          }
        } else {
          // Treat as single value.
          if (isset($vars['isotope_filter_classes'][$index]))
            $vars['isotope_filter_classes'][$index] .= ' '. strtolower(drupal_clean_css_identifier($value));
          else
            $vars['isotope_filter_classes'][$index] = strtolower(drupal_clean_css_identifier($value));
        }
      }
    }
  }
  
  /* SORTING */
	$sort_js = '(function($) { $(document).ready(function() { var $container = $(\'#isotope-container\'); $container.isotope(\'option\', { getSortData : { @sortdata } }); $container.isotope(\'updateSortData\', $(\'.isotope-element\')); }); })(jQuery);';
	$sort_data = '';
	
  // Extract classes for fields containing isotope sort data.
  $sorts = array();
  foreach ($fields as $field => $data) {
    if (strpos($data->options['element_class'], 'isotope-sort') !== FALSE)
      $sorts[] = $data->options['element_class'];
  }
  
  // Clean up sort classes.
  for ($i = 0; $i < count($sorts); $i++) {
    $sorts[$i] = str_replace('isotope-sort', '', $sorts[$i]);
    $sorts[$i] = trim($sorts[$i]);
  }
  
  // Build sort data.
  foreach ($sorts as $sort) {
    if (strlen($sort_data) > 0) $sort_data .= ', ';
    $sort_data .= '\'' . $sort . '\'' . ' : function($elem) { var data = $elem.find(\'.isotope-sort.' . $sort . '\').text(); if (!isNaN(data)) { return parseInt(data); } else { return data; } }';
  }
  
  // Add inline JavaScript for sorting.
  $sort_js = str_replace('@sortdata', $sort_data, $sort_js);
	drupal_add_js($sort_js, array(
		'type' => 'inline',
		'scope' => 'header',
		'weight' => 10,
	));
  
  // Add stylesheets.
  drupal_add_css(drupal_get_path('module', 'views_isotope') . '/views_isotope.css');

  // Add JavaScript files and settings.
  drupal_add_js(libraries_get_path('jquery.isotope') . '/jquery.isotope.min.js');
  drupal_add_js(drupal_get_path('module', 'views_isotope') . '/views_isotope.js');
}

/**
 * Preprocess function to build isotope filter blocks
 */
function template_preprocess_views_isotope_filter_block(&$vars) {
  template_preprocess_views_view_list($vars);
  
  $vars['isotope_filter_classes'] = array();
  
  // Clean row values for use as filter classes.
  foreach ($vars['rows'] as $row)
    $vars['isotope_filter_classes'][] = '.' . strtolower(drupal_clean_css_identifier(trim($row)));
}

/**
 * Preprocess function for isotope sort blocks
 */
function template_preprocess_views_isotope_sort_block(&$vars) {
  template_preprocess_views_view_list($vars);
  
  $vars['isotope_sort_classes'] = array();
  
  // Clean row values for use as sort classes.
  foreach ($vars['rows'] as $row)
    $vars['isotope_sort_classes'][] = strtolower(drupal_clean_css_identifier(trim($row)));
}