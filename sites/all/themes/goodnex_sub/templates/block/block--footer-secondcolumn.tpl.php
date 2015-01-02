<?php
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
<h3 class="widget-title"><?php print $block->subject ?></h3>
<?php endif;?>

<?php print $content ?>
<?php print render($title_suffix); ?>
</div>