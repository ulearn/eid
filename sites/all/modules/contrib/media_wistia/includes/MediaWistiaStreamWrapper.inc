<?php

/**
 *  @file media_wistia/includes/MediaWistiaStreamWrapper.inc
 *
 *  Create a Wistia Stream Wrapper class for the Media/Resource module.
 */

include_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'media_wistia') . '/includes/DrupalWistiaApi.php';

/**
 *  Create an instance like this:
 *  $wistia = new MediaWistiaStreamWrapper('wistia://v/[video-code]');
 */
class MediaWistiaStreamWrapper extends MediaReadOnlyStreamWrapper {

  protected $api;
  protected $base_url = 'http://home.wistia.com/medias/';

  public function __construct() {
    $this->api = new DrupalWistiaApi(variable_get('media_wistia_api_key'));
  }

  /**
   * Overrides interpolateUrl() defined in MediaReadOnlyStreamWrapper.
   * Checks to see if the video is in our cache, if not we request from the api.
   */
  function interpolateUrl() {
    $parameters = $this->get_parameters();
    if (!empty($parameters['v'])) {
      return $this->base_url . $parameters['v'];
    }
  }

  /**
   * Returns the wistia mimetype.
   * @param $uri
   * @param null $mapping
   * @return string
   */
  static function getMimeType($uri, $mapping = NULL) {
    return 'video/wistia';
  }

/**
   * Gets the original thumbnail for the wistia video
   * @return mixed
   */
  function getOriginalThumbnailPath($http_path = '') {
    $parts = $this->get_parameters();
    if(!empty($parts['url'])) {
      $media = _media_wistia_request_data($parts['url']);
      // Strip image crop parameter to get full-sized original.
      $url = str_replace('image_crop_resized=100x60', 'image_crop_resized=640x360', $media['thumbnail_url']);
      return $url;
    } else {
      $media = $this->api->mediaShow($parts['v']);
      $url = str_replace('image_crop_resized=100x60', 'image_crop_resized=640x360', $media->thumbnail->url);
    }
    return $url;
  }

  /**
   * Returns the url to the thumbnail for the wistia video
   * @return string
   */
  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    $local_path = file_default_scheme() . '://media-wistia/' . check_plain($parts['v']) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

      $response = drupal_http_request($this->getOriginalThumbnailPath());

      if (!isset($response->error)) {
        file_unmanaged_save_data($response->data, $local_path, TRUE);
      }
      else {
        @copy($this->getOriginalThumbnailPath(), $local_path);
      }
    }
    return $local_path;
  }

//  function setUri($uri) {
//    $this->uri = $uri;
//    $parameters = $this->_parse_url($uri);
//    if($parameters['v'] == 'http') {
//      $parameters['url'] =  $this->mediaWistiaParseHttpUrl($this->getUri());
//      $parameters['v'] = $this->parse($parameters['url']);
//    }
//
//    $this->parameters = $parameters;
//  }

  function mediaWistiaParseHttpUrl($url) {
    $parts = explode("//v/", $url);

    return $parts[1];
  }

  function parse($embedCode) {
    $patterns = array(
      '/https?:\/\/(.+)?(wistia\.com|wi\.st)\/(medias|embed)\/(.*)/',
    );
    foreach ($patterns as $pattern) {
      preg_match($pattern, $embedCode, $matches);
      if (isset($matches[4])) {
        return $matches[4];
      }
    }
  }
}
