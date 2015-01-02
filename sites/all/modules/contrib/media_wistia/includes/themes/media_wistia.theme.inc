<?php

/**
 * @file media_wistia/includes/themes/media_wistia.theme.inc
 *
 * Theme and preprocess functions for Media: Wistia.
 */

/**
 * Preprocess function for theme('media_wistia_video').
 */
function media_wistia_preprocess_media_wistia_video(&$variables) {

  // Build the URI.
  $wrapper = file_stream_wrapper_get_instance_by_uri($variables['uri']);
  $parts = $wrapper->get_parameters();
  $variables['video_id'] = check_plain($parts['v']);

  // Add some options as their own template variables.
  foreach (array('width', 'height') as $theme_var) {
    $variables[$theme_var] = $variables['options'][$theme_var];
  }

  // Do something useful with the overridden attributes from the file
  // object. We ignore alt and style for now.
  if (isset($variables['options']['attributes']['class'])) {
    if (is_array($variables['options']['attributes']['class'])) {
      $variables['classes_array'] = array_merge($variables['classes_array'], $variables['options']['attributes']['class']);
    }
    else {
      // Provide nominal support for Media 1.x.
      $variables['classes_array'][] = $variables['options']['attributes']['class'];
    }
  }

  // Make the file object available.
  $file_object = file_uri_to_object($variables['uri']);

  // Add template variables for accessibility.
  $variables['title'] = check_plain($file_object->filename);
  // @TODO: Find an easy/ not too expensive way to get the Wistia description
  // to use for the alternative content.
  $variables['alternative_content'] = t('Video of @title', array('@title' => $variables['title']));

  $query = array(
    'version' => '1.0',
    'videoHeight' => $variables['options']['height'],
    'videoWidth' => $variables['options']['width'],
    'height' => $variables['options']['height'],
    'width' => $variables['options']['width'],
    'embedType' => ($variables['options']['video_type'] == 'popover') ? $variables['options']['video_type'] : $variables['options']['embed_type'],
    'ssl' => $variables['options']['ssl'] ? 'true' : 'false'
  );

  if ($variables['options']['video_type'] == 'popover') {

    $query['popoverWidth'] = $variables['options']['width'];
    $query['popoverHeight'] = $variables['options']['height'];

    $query['popover'] = 'v1';

  }

  $url = 'http://fast.wistia.net/embed/medias/' . $variables['video_id'] . '?' . http_build_query($query);

  $params = array('url' => $url);

  $embed = _media_wistia_request_embed($params);

  // Build the iframe URL with options query strings
  $variables['embed'] = $embed['html'];
}

/**
 * Request to embed code from the wistia get embed endpoint.
 * @param $query array the quiery string to send to the endpoint.
 * @return array|bool
 */
function _media_wistia_request_embed($query) {
  // Make HTTP request.
  $endpoint = variable_get('media_wistia_getembed_url', MEDIA_WISTIA_DEFAULT_GETEMBED_URL);
  $result = drupal_http_request(url($endpoint, array('query' => $query)));

  if ($data = json_decode($result->data)) {
    // Success.
    return (array)$data;
  }
  else {
    // Failure. Either the video or playlist doesn't exist on Wistia or there
    // was an error with the request.
    return FALSE;
  }
}