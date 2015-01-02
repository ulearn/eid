<?php
?>
<aside id="sidebar" class="four columns">
<ul class="ajax-nav">
<?php if ($header): ?>
<?php print $header; ?>
<?php endif; ?>
</ul><!--/ .ajax-nav-->
</aside><!--/ #sidebar-->     
<section id="main" class="nine columns">
<div class="ajax-content">
<ul>
<?php print render($title_prefix); ?>
<?php if ($title): ?>
<?php print $title; ?>
<?php endif; ?>
<?php print render($title_suffix); ?>
<?php if ($exposed): ?>
<div class="view-filters">
<?php print $exposed; ?>
</div>
<?php endif; ?>
<?php if ($attachment_before): ?>
<div class="attachment attachment-before">
<?php print $attachment_before; ?>
</div>
<?php endif; ?>
<?php if ($rows): ?>
<?php print $rows; ?>
<?php elseif ($empty): ?>
<div class="view-empty">
<?php print $empty; ?>
</div>
<?php endif; ?>
<?php if ($pager): ?>
<?php print $pager; ?>
<?php endif; ?>
<?php if ($attachment_after): ?>
<div class="attachment attachment-after">
<?php print $attachment_after; ?>
</div>
<?php endif; ?>
<?php if ($more): ?>
<?php print $more; ?>
<?php endif; ?>
<?php if ($feed_icon): ?>
<div class="feed-icon">
<?php print $feed_icon; ?>
</div>
<?php endif; ?>
<?php if ($footer): ?>
<?php print $footer; ?>
<?php endif; ?>
</ul>
</div>    
</section>