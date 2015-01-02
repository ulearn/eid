<?php

/**
 * @file media_wistia/includes/media_wistia.formatters.inc
 *
 * Formatters for Media: Wistia.
 */

/**
 * Implements hook_file_formatter_info().
 */
function media_wistia_file_formatter_info() {
  $formatters['media_wistia_video'] = array(
    'label' => t('Wistia Video'),
    'file types' => array('video'),
    'default settings' => array(),
    'view callback' => 'media_wistia_file_formatter_video_view',
    'settings callback' => 'media_wistia_file_formatter_video_settings'
  );

  foreach (media_wistia_variable_default() as $setting => $value) {
    $formatters['media_wistia_video']['default settings'][$setting] = media_wistia_variable_get($setting);
  }

  $formatters['media_wistia_image'] = array(
    'label' => t('Wistia Preview Image'),
    'file types' => array('video'),
    'default settings' => array(
      'image_style' => '',
    ),
    'view callback' => 'media_wistia_file_formatter_image_view',
    'settings callback' => 'media_wistia_file_formatter_image_settings'
  );

  return $formatters;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_wistia_file_formatter_video_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  // WYSIWYG does not yet support video inside a running editor instance.
  if ($scheme == 'wistia' && empty($file->override['wysiwyg'])) {
    $element = array(
      '#theme' => 'media_wistia_video',
      '#uri' => $file->uri,
      '#options' => array(),
    );

    // Fake a default for attributes so the ternary doesn't choke.
    $display['settings']['attributes'] = array();

    foreach (media_wistia_variable_default() as $setting => $value) {
      $element['#options'][$setting] = isset($file->override[$setting]) ? $file->override[$setting] : $display['settings'][$setting];
    }
    return $element;
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_wistia_file_formatter_video_settings($form, &$form_state, $settings) {
  $element = array();

  $element['video_type'] = array(
    '#title' => t('Video Type'),
    '#type' => 'radios',
    '#options' => array(
      'inline' => 'Inline',
      'popover' => 'Popup',
    ),
    '#default_value' => $settings['video_type'],
  );
  $element['width'] = array(
    '#title' => t('Width'),
    '#type' => 'textfield',
    '#default_value' => $settings['width'],
    '#element_validate' => array('_wistia_validate_video_width_and_height'),
  );
  $element['height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#default_value' => $settings['height'],
    '#element_validate' => array('_wistia_validate_video_width_and_height'),
  );
  $element['embed_type'] = array(
    '#title' => t('Embed Type'),
    '#type' => 'radios',
    '#options' => array(
      'iframe' => 'iFrame',
      'api' => 'API',
      'seo' => 'SEO',
    ),
    '#default_value' => $settings['embed_type'],
    '#states' => array(
      'visible' => array(
        'input[name="displays[media_wistia_video][settings][video_type]"]' => array('checked' => TRUE)
      )
    )
  );
  $element['ssl'] = array(
    '#title' => t('Use SSL'),
    '#type' => 'checkbox',
    '#default_value' => $settings['ssl'],
  );

  return $element;
}

/**
 * Validation for width and height.
 */
function _wistia_validate_video_width_and_height($element, &$form_state, $form) {

  // Check if the value is a number with an optional decimal or percentage sign, or "auto".
  if (!empty($element['#value']) && !preg_match('/^(auto|([0-9]*(\.[0-9]+)?%?))$/', $element['#value'])) {
    form_error($element, t("The value entered for @dimension is invalid. Please insert a unitless integer for pixels, a percent, or \"auto\". Note that percent and auto may not function correctly depending on the browser and doctype.", array('@dimension' => $element['#title'])));
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_wistia_file_formatter_image_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  if ($scheme == 'wistia') {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
    $image_style = $display['settings']['image_style'];
    $valid_image_styles = image_style_options(FALSE);

    if (empty($image_style) || !isset($valid_image_styles[$image_style])) {
      $element = array(
        '#theme' => 'image',
        '#path' => $wrapper->getOriginalThumbnailPath(),
        '#alt' => isset($file->override['attributes']['alt']) ? $file->override['attributes']['alt'] : $file->filename,
      );
    }
    else {
      $element = array(
        '#theme' => 'image_style',
        '#style_name' => $image_style,
        '#path' => $wrapper->getLocalThumbnailPath(),
        '#alt' => isset($file->override['attributes']['alt']) ? $file->override['attributes']['alt'] : $file->filename,
      );
    }

    return $element;
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_wistia_file_formatter_image_settings($form, &$form_state, $settings) {
  $element = array();
  $element['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#options' => image_style_options(FALSE),
    '#default_value' => $settings['image_style'],
    '#empty_option' => t('None (original image)'),
  );
  return $element;
}

/**
 * Implements hook_file_default_displays().
 */
function media_wistia_file_default_displays() {

  // Default settings for displaying as a video.
  $default_displays = array();

  $default_video_settings = array(
    'default' => array(
      'width' => 640,
      'height' => 390
    ),
    'teaser' => array(
      'width' => 560,
      'height' => 340
    ),
    // Legacy view modes included to support older versions of Media,
    // before #1051090 went through. They do no harm and can sit here
    // until there is a Media 2.x stable.
    // @TODO: Remove when Media 2.0 is released.
      'media_large' => array(
          'width' => 560,
          'height' => 340
      ),
      'media_small' => array(
          'width' => 560,
          'height' => 340
      ),
    'media_original' => array(
      'width' => 640,
      'height' => 390
    ),
  );
  foreach ($default_video_settings as $view_mode => $settings) {
    $display_name = 'video__' . $view_mode . '__media_wistia_video';
    $default_displays[$display_name] = (object) array(
      'api_version' => 1,
      'name' => $display_name,
      'status' => 1,
      'weight' => 1,
      'settings' => $settings,
    );
  }

  // Default settings for displaying a video preview image.
  // We enable preview images even for view modes that also play video
  // for use inside a running WYSIWYG editor. We weight them so video
  // formatters come first in the cascade to make sure the video formatter
  // is used whenever possible.
  $default_image_styles = array(
    'default' => 'large',
    'preview' => 'square_thumbnail',
    'teaser' => 'large',
    // Legacy view modes, see note above.
    'media_preview' => 'square_thumbnail',
    'media_large' => 'large',
    'media_small' => 'medium',
    'media_original' => '',
  );
  foreach ($default_image_styles as $view_mode => $image_style) {
    $display_name = 'video__' . $view_mode . '__media_wistia_image';
    $default_displays[$display_name] = (object) array(
      'api_version' => 1,
      'name' => $display_name,
      'status' => 1,
      'weight' => 2,
      'settings' => array('image_style' => $image_style),
    );
  }

  return $default_displays;
}
