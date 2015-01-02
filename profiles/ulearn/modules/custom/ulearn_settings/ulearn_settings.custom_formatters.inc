<?php
/**
 * @file
 * ulearn_settings.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function ulearn_settings_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'date_with_number_of_weeks';
  $formatter->label = 'Date with number of weeks';
  $formatter->description = 'Displays date range and number of weeks in it.';
  $formatter->mode = 'php';
  $formatter->field_types = 'date, datestamp, datetime';
  $formatter->code = '$output = \'\';
$items = !empty($variables[\'#items\']) ? $variables[\'#items\'] : array();
$skip_friday = TRUE;
if ($variables[\'#obj_type\'] == \'registration\') {
  $object = $variables[\'#object\'];
  $product = commerce_product_load($object->entity_id);
  if (in_array($product->type, array(\'course\'))) {
    $skip_friday = FALSE;
  }
}
foreach ($items as $delta => $item) {
  $output .= \'<span class="date-item date-item-\' . $delta . \'">\';
  $start_date = strtotime($item[\'value\']);
  $output .= format_date($start_date, \'ulearn_date_format\');
  if (!empty($item[\'value2\'])) {
    $end_date = strtotime($item[\'value2\']);
    $output .= \' \' . t(\'to\') . \' \' . format_date($end_date, \'ulearn_date_format\');
    $difference = abs($end_date - $start_date);
    $days = floor($difference/(60*60*24));
    $weeks = floor($days/7);
    $remaining_days = $days - ($weeks * 7);
    $courses_config = variable_get(\'ulearn_courses\', array());
    $friday = $courses_config[\'ulearn_course_week_end_friday\'];
    if ($friday && !$skip_friday) {
      $weeks++;
      $remaining_days = 0;
    }
    if ($weeks != 0 || $remaining_days != 0) {
      $output .= \' (\';
    }
    if ($weeks != 0) {
      $output .= format_plural($weeks, \'1 week\', \'@count weeks\');
      if ($remaining_days != 0) {
        $output .= \' \';
      }
    }
    if ($remaining_days != 0) {
      $output .= format_plural($remaining_days, \'1 day\', \'@count days\');
    }
    if ($weeks != 0 || $remaining_days != 0) {
      $output .= \')\';
    }
  }
  $output .= \'</span>\';
}
return $output;';
  $formatter->fapi = '';
  $export['date_with_number_of_weeks'] = $formatter;

  return $export;
}
