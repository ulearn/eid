<?php

/**
 * @file media_wistia/includes/themes/media-Wistia-video.tpl.php
 *
 * Template file for theme('media_wistia_video').
 *
 * Variables available:
 *  $uri - The media uri for the Wistia video (e.g., Wistia://v/xsy7x8c9).
 *  $video_id - The unique identifier of the Wistia video (e.g., xsy7x8c9).
 *  $id - The file entity ID (fid).
 *  $url - The full url including query options for the Wistia iframe.
 *  $options - An array containing the Media Wistia formatter options.
 *  $api_id_attribute - An id attribute if the Javascript API is enabled;
 *  otherwise NULL.
 *  $width - The width value set in Media: Wistia file display options.
 *  $height - The height value set in Media: Wistia file display options.
 *  $title - The Media: Wistia file's title.
 *  $alternative_content - Text to display for browsers that don't support
 *  iframes.
 *
 */

?>
<div class="<?php print $classes; ?> media-wistia-<?php print $id; ?>">
    <?php print $embed; ?>
</div>
