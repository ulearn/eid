<?php

/**
 * @file
 * Plugin
 *
 * @author Mathew Winstone <mwinstone@coldfrontlabs.ca>
 */

/**
 * Implement a style plugin for the Views module
 */
class bvt_views_plugin_style_tables extends views_plugin_style_table {

  function option_definition() {
    $options = parent::option_definition();

    $options += array(
      'header_fields' => array('default' => t('None')),
      'footer_fields' => array('default' => t('None')),
      'responsify'    => array('default' => FALSE),
    );

    return $options;
  }

  /**
   * Show a form to edit the style options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $columns = $this->sanitize_columns($this->options['columns']);

    // Create an array of allowed columns from the data we know:
    $field_names = $this->display->handler->get_field_labels();

    if (isset($this->options['default'])) {
      $default = $this->options['default'];
      if (!isset($columns[$default])) {
        $default = -1;
      }
    }
    else {
      $default = -1;
    }

    foreach ($columns as $field => $column) {
      $safe = str_replace(array('][', '_', ' '), '-', $field);
      // the $id of the column for dependency checking.
      $id = 'edit-style-options-columns-' . $safe;

      $form['info'][$field]['header_column'] = array(
        '#type' => 'checkbox',
        '#default_value' => isset($this->options['info'][$field]['header_column']) ? $this->options['info'][$field]['header_column'] : FALSE,
        '#dependency' => array($id => array($field)),
      );
      $form['info'][$field]['responsify_priority'] = array(
        '#type' => 'select',
        '#options' => array(
          0 => 'None',
          1 => 'Optional',
          2 => 'Essential',
          3 => 'Persist',
        ),
        '#default_value' => isset($this->options['info'][$field]['responsify_priority']) ? $this->options['info'][$field]['responsify_priority'] : 0,
        '#dependency' => array($id => array($field)),
      );
    }

    // Update the description message to include information about the header column
    $form['description_markup']['#markup'] = '<div class="description form-item">' . t('Place fields into columns; you may combine multiple fields into the same column. If you do, the separator in the column specified will be used to separate the fields. Check the sortable box to make that column click sortable, and check the default sort radio to determine which column will be sorted by default, if any. You may control column order and field labels in the fields section. The "Header Column" allows you to mark a set of fields to render as row headers instead of row data.') . '</div>';

    $form['responsify'] = array(
      '#type' => 'checkbox',
      '#title' => t('Responsive'),
      '#default_value' => isset($this->options['responsify']) ? $this->options['responsify'] : FALSE,
      '#description' => 'Make this table responsive (relies on a module like Responsive Tables make use of this option)',
    );

    $form['#theme'] = 'bvt_style_plugin_ui_table';
  }
}
