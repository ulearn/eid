<?php
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
<h3 class="widget-title"><?php print "Flickr Gallary" ?></h3>
<?php endif;?>
<div class="p0 clearfix flickr">
<?php print $content ?>
</div>	
<?php print render($title_suffix); ?>
</div>