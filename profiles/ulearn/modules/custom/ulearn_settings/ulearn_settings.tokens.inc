<?php

/**
 * @file
 * Provides placeholder tokens for ULearn commerce.
 */

/**
 * Implements hook_token_info_alter().
 */
function ulearn_settings_token_info_alter(&$data) {
  $data['tokens']['site']['ulearn-admin-email'] = array(
    'name' => t('ULearn admin email'),
    'description' => t('Comma separeted list of email ids to which site wide emails should be sent.'),
  );
}

/**
 * Implements hook_tokens().
 */
function ulearn_settings_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'site') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'ulearn-admin-email':
          $replacements[$original] = variable_get('ulearn_global_admin_email', '');
          break;
      }
    }
  }
  return $replacements;
}
