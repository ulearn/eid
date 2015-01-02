<?php
/**
 * @file views-isotope-filter-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="isotope-options">
  <ul class="isotope-filters option-set clearfix" data-option-key="filter">
  	<li><a href="#filter" data-option-value="*" class="selected"><?php print t('All'); ?></a></li>
  <?php
    $count = 0;
    foreach ($rows as $id => $row):
  ?>
    <li><a class="filterbutton" data-option-value="<?php print $isotope_filter_classes[$count]; ?>" href="#filter"><?php print trim($row); ?></a></li>
  <?php
      $count++;
    endforeach;
  ?>
  </ul>
</div>
