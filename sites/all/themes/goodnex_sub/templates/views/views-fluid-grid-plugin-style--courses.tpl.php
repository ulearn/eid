<?php
?>
<div class="views-fluid-grid">
<?php if (!empty($title)) : ?>
<h3><?php print $title; ?></h3>
<?php endif; ?>
<ul class="<?php print $list_class; ?>">
<?php foreach ($rows as $id => $item): ?>
<li class="views-fluid-grid-inline views-fluid-grid-item <?php print $classes_array[$id]; ?>"><?php print $item; ?></li>
<?php endforeach; ?>
<?php if (!empty($options['list_alignment']) && $options['list_alignment'] == 'justify') : ?>
<li class="views-fluid-grid-inline views-fluid-grid-justify-last"></li>
<?php endif; ?>
</ul>
</div>