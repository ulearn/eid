<?php
/**
 * @file
 * ulearn_slideshow.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function ulearn_slideshow_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'banner_slideshow_queue';
  $queue->label = 'Banner slideshow queue';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'banner_slideshow' => 'banner_slideshow',
    ),
    'min_size' => '0',
    'max_size' => '0',
  );
  $export['banner_slideshow_queue'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'small_banner_queue';
  $queue->label = 'Small banner queue';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'banner_slideshow' => 'banner_slideshow',
    ),
    'min_size' => '0',
    'max_size' => '0',
  );
  $export['small_banner_queue'] = $queue;

  return $export;
}
