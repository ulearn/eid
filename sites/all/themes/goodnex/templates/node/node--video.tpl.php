<?php
/**
* @file
* Goodnex's theme implementation to display a single video node.
*/
global $base_url; 
$next = goodnex_pagination($node, 'n');
$prev = goodnex_pagination($node, 'p');
if ($next != NULL) { 
$next_url = url('node/' . $next, array('absolute' => TRUE));
}
if ($prev != NULL) { 
$prev_url = url('node/' . $prev, array('absolute' => TRUE));
}
$image_slide = "";
if ($items = field_get_items('node', $node, 'field_video_slider')) {
if (count($items) == 1) {
$image_slide = 'false';
}
elseif (count($items) > 1) {
$image_slide = 'true';
}
}
$img_count = 0;
$counter = count($items);
?>
<?php if($page && module_exists('prev_next')): ?>
<div class="video-controls <?php global $user; if ( user_is_logged_in() ) { echo "video-controls-user"; } ?>">
<?php if ($prev != NULL): ?>
<a class="controls-prev" href="<?php echo $prev_url; ?>">Prev</a>
<?php endif; ?>
<a class="controls-all" href="<?php echo $base_url; ?>/video">all</a>
<?php if ($next != NULL): ?>
<a class="controls-next" href="<?php echo $next_url; ?>">Next</a>
<?php endif; ?>  
</div><!--/ .video-controls-->	
<?php endif; ?>
<?php if ( ($image_slide == 'true') ): ?>
<div class="image-gallery-slider">
<ul>
<?php while ($img_count < $counter) { ?>
<li>
<div class="preloader">
<a class="bwWrapper single-image plus-icon" href="<?php echo file_create_url($node->field_video_slider['und'][$img_count]['uri']); ?>" rel="gallery">
<img src="<?php echo file_create_url($node->field_video_slider['und'][$img_count]['uri']); ?>" alt="" >
</a>							
</div>
</li>
<?php $img_count++; } ?>		
</ul>
</div>    
<?php endif; ?>
<?php if ($image_slide == 'false'): ?>
<div class="preloader">
<a class="bwWrapper single-image link-icon" href="<?php print $node_url; ?>">
<img src="<?php echo file_create_url($node->field_video_slider['und'][0]['uri']); ?>" alt="" >
</a>						
</div>
<?php endif; ?>
<?php
// Hide comments, tags, and links now so that we can render them later.
hide($content['field_video_slider']);
hide($content['field_image']);
hide($content['links']);
hide($content['field_video_category']);
print render($content);
?>
<div class="clear"></div>