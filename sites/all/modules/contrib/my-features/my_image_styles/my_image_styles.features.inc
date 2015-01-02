<?php
/**
 * @file
 * my_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function my_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: md_slider_2_thumb.
  $styles['md_slider_2_thumb'] = array(
    'name' => 'md_slider_2_thumb',
    'label' => 'md_slider_2_thumb',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
          'scaleup' => FALSE,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: slideshow_bg.
  $styles['slideshow_bg'] = array(
    'name' => 'slideshow_bg',
    'label' => 'slideshow_bg',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1920,
          'height' => 705,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
