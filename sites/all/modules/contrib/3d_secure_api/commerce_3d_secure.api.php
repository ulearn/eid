<?php

/**
 * @file
 * Hooks provided by the Commerce 3-D Secure module.
 */

/**
 * Define 3-D Secure MPI providers available to the Commerce Payment framework.
 * 
 * Each MPI provider is an associative array with the following keys:
 *  - title: the translatable full title of the MPI provider, used in
 *    administrative interfaces.
 * 
 * @return
 *   An array of MPI providers, using the format defined above.
 */
function hook_commerce_3d_secure_mpi_info() {
  $mpi['example_mpi'] = array(
    'title' => t('Example MPI'),
  );

  return $mpi;
}


/**
 * Returns a form with settings related to the MPI provider.
 *
 * This form will be merged with the Payment Method form.
 * 
 * @param $settings
 *  Payment Method settings.
 * 
 * @return
 *   A valid Drupal form.
 */
function hook_commerce_3d_secure_mpi_settings($settings = array()) {
  // No example
}

/**
 * Forwards payment step data to the lookup function.
 *
 * All arguments are the same as those sent to the standard Payment
 *  _submit_form_submit function.
 * 
 * @param $payment_method
 * @param $pane_values 
 * @param $order 
 * @param $charge
 * 
 * @return
 *  An associative array containing:
 *   - success: Boolean indicating whether an error was received.
 *   - authenticate: Boolean indicating whether Authentication should be done.
 *   - message: A status message regarding the outcome.
 *   - enrollment_status: Card enrollment status.
 *   - ECI: Risk identifier.
 *   - ACSURL: (Required if authenticate is TRUE) The URL of the Authentication server.
 *   - PAReq: (Required if authenticate is TRUE) Payload data to be sent to Authentication server.
 *   - MD: (Optional if authenticate is TRUE) Merchant data sent to Authentication server.
 *   - txn_id: MPI generated transaction identifier.
 */
function hook_commerce_3d_secure_mpi_lookup($payment_method, $pane_values, $order, $charge) {
  // No example
}

/**
 * Processes the ACS response message.
 * 
 * @param $acs_response
 *  POST data returned from the ACS authentication server.
 * @param $payment_method
 * @param $order
 * 
 * @return
 *  An associative array containing:
 *   - authorize: Boolean indicating whether authorization should be done.
 *   - authenticated: Boolean indicating whether to do an authenticated or unauthenticated authorization.
 *   - message: A status message regarding the outcome.
 *   - ECI: Risk identifier.
 *   - authentication_status: Authentication status.
 *   - authentication_value: Authentication (Payload) value;
 *   - authentication_txn_id: Authentication transaction identifier.
 */
function hook_commerce_3d_secure_mpi_authenticate($acs_response, $payment_method, $order) {
  // No example
}
