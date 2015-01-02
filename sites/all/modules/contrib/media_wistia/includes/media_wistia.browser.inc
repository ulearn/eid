<?php
/**
 *  @file media_wistia/includes/media_wistia.browser.inc
 *
 *  Create a Wistia Browser class for the Media/Resource module.
 */

define('MEDIA_WISTIA_CACHE_KEY', 'media-wistia');

include_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'media_wistia') . '/includes/WistiaApi.php';

/**
 * AJAX Callback function to return a list of wistia projects
 */
function media_wistia_browser_project_list() {
  $api = new DrupalWistiaApi(variable_get('media_wistia_api_key'));

  $projects = $api->projectList();

  drupal_json_output(array('media' => $projects));
  exit();
}

/**
 *
 */
function media_wistia_browser_project() {
  $params = drupal_get_query_parameters();
  // How do we validate these?  I don't know.
  // I think PDO should protect them, but I'm not 100% certain.
  array_walk_recursive($params, '_media_wistia_recursive_check_plain');

  $videos = _media_wistia_get_video_list_by_project($params['id'], $params['start'], $params['limit']);

  drupal_json_output(array('media' => $videos));
  exit();
}

function _media_wistia_get_video_list_by_project($project_id = 0, $page = 1, $limit = 15) {
  static $videos;

  if (empty($videos) && $project_id !== 0) {

    $cache_key = MEDIA_WISTIA_CACHE_KEY . $project_id . $page . $limit;

    $cache_result = cache_get($cache_key);

    if ($cache_result['valid']) {

      $videos = $cache_result['data'];

    }
    else {

      $api = new DrupalWistiaApi(variable_get('media_wistia_api_key'));

      $videos = $api->mediaList($project_id, $page, $limit, FALSE);

      _media_wistia_create_temporary_files($videos);

      cache_set($cache_key, $videos, NULL, CACHE_TEMPORARY);

    }

  }

  return $videos;

}

function _media_wistia_get_video_from_cache($video_id) {

  $videos = _media_wistia_get_video_list_by_project();
  $video = NULL; // making sure video has been set

  if (!empty($videos)) {
    foreach ($videos as $key => $video) {
      if ($video->hashed_id == $video_id) {
        break;
      }
    }
  }

  return $video;

}

function _media_wistia_create_temporary_files(&$videos) {

  foreach ($videos as &$video) {

    if ($video) {

      $uri = 'wistia://v/' . $video->hashed_id;
      $file = file_uri_to_object($uri, TRUE);
      $file->filename = $video->name;
      $file->type = 'video';
      $file = file_save($file);

      $preview = media_get_thumbnail_preview($file);
      $file->preview = drupal_render($preview);

      $video->file = $file;

    }

  }

}

/**
 * Silly function to recursively run check_plain on an array.
 *
 * There is probably something in core I am not aware of that does this.
 *
 * @param $value
 * @param $key
 */
function _media_wistia_recursive_check_plain(&$value, $key) {
  $value = check_plain($value);
}