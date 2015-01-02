<?php
/**
 * @file
 * ulearn_course.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ulearn_course_default_rules_configuration() {
  $items = array();
  $items['rules_seasonal_amount_calculation'] = entity_import('rules_config', '{ "rules_seasonal_amount_calculation" : {
      "LABEL" : "Seasonal amount calculation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "ulearn_commerce", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "DO" : [
        { "ulearn_commerce_line_item_unit_price_add" : {
            "commerce_line_item" : [ "commerce_line_item" ],
            "component_name" : "base_price",
            "round_mode" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_set_default_value_for_course_id'] = entity_import('rules_config', '{ "rules_set_default_value_for_course_id" : {
      "LABEL" : "Set default value for course ID",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ULearn", "ULearn course" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--course_display" : { "bundle" : "course_display" } },
      "IF" : [ { "data_is_empty" : { "data" : [ "node:field-course-unique-id" ] } } ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-course-unique-id" ], "value" : [ "node:nid" ] } }
      ]
    }
  }');
  return $items;
}
