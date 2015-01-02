<?php

/**
 * Field handler to return a share amount.
 */
class ulearn_course_line_item_share_amount extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['line_item_id'] = 'line_item_id';
  }
  function option_definition() {
    $options = parent::option_definition();

    // Define an option to control the display.
    $options['ulearn_share_amount_display'] = array('default' => 'currency_format');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['ulearn_share_amount_display'] = array(
      '#type' => 'select',
      '#title' => t('Display format'),
      '#description' => t('Select the display format for share amount.'),
      '#options' => array(
        'currency_format' => t('Default commerce currency format'),
        'currency_format_with_percentage' => t('Commerce currency format with percentage amount'),
      ),
      '#default_value' => $this->options['ulearn_share_amount_display'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Load the line item.
    $line_item_id = $this->get_value($values, 'line_item_id');
    $line_item = commerce_line_item_load($line_item_id);
    // Get our data from line item.
    if (!empty($line_item->data['ulearn_course_share'])) {
      $output = '';
      $amount_data = $line_item->data['ulearn_course_share'];
      $share_amount = $amount_data['amount'];
      $currency_code = $amount_data['currency_code'];
      $output .= commerce_currency_format($share_amount, $currency_code);
      if ($this->options['ulearn_share_amount_display'] == 'currency_format_with_percentage' && !empty($amount_data['percentage_amount'])) {
        $output .= ' <span class="ulearn-share-percentage">(' . $amount_data['percentage_amount'] . '%)</span>';
      }
    }
    return $output;
  }
}
