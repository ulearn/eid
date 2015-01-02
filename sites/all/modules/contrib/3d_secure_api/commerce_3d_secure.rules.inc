<?php

/**
 * @file
 * Overrides the Commerce Payment Rules UI to add the 3-D Secure settings form.
 */

/**
 * Implements hook_rules_data_info_alter().
 */
function commerce_3d_secure_rules_data_info_alter(&$data_info) {
  $data_info['commerce_payment_settings']['ui class'] = 'RulesDataUIPaymentSettings3DS';
}

class RulesDataUIPaymentSettings3DS extends RulesDataUIPaymentSettings{
  public static function inputForm($name, $info, $settings, RulesPlugin $element) {
    $form = parent::inputForm($name, $info, $settings, $element);

    // Attach the MPI settings form
    $method_settings = !empty($settings[$name]['settings']) && is_array($settings[$name]['settings']) ? $settings[$name]['settings'] : array();
    $method_settings += array(
      'commerce_3d_secure_mpi' => '',
    );

    $form[$name]['settings'] += commerce_3d_secure_commerce_payment_method_settings_form($method_settings);

    return $form;
  }
}
