<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="fullwidthbanner">
	<ul class="no-bullet m0 p0">
<?php foreach ($rows as $id => $row): ?>
  <li data-transition="fade" data-slotamount="7" data-masterspeed="300">
    <?php print $row; ?>
  </li>
<?php endforeach; ?>
</ul>
</div>