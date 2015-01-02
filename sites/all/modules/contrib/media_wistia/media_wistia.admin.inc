<?php
/**
 * @file
 * Media: Wistia provides a stream wrapper and formatters for videos provided
 * by Wistia.
 */

function media_wistia_global_settings() {

  $form = array();

  $form['media_wistia_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Wistia Api Key'),
    '#default_value' => variable_get('media_wistia_api_key'),
  );

  $form['media_wistia_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Wistia Api Url'),
    '#default_value' => variable_get('media_wistia_api_url', MEDIA_WISTIA_DEFAULT_API_URL),
  );

  $form['media_wistia_oembed_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Wistia oEmbed Url'),
    '#default_value' => variable_get('media_wistia_oembed_url', MEDIA_WISTIA_DEFAULT_OEMBED_URL),
  );

  $form['media_wistia_getembed_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Wistia Get Embed Url'),
    '#default_value' => variable_get('media_wistia_getembed_url', MEDIA_WISTIA_DEFAULT_GETEMBED_URL),
  );

  return system_settings_form($form);

}