<?php
/**
 * @file views-isotope-sort-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="isotope-options">
  <ul class="isotope-sort option-set clearfix" data-option-key="sortBy">
  <?php
    $count = 0;
    foreach ($rows as $id => $row):
  ?> 
    <li><a class="sortbutton" data-option-value="<?php print $isotope_sort_classes[$count]; ?>" href="#sortBy=<?php print $isotope_sort_classes[$count]; ?>"><?php print trim($row); ?></a></li>
  <?php
      $count++;
    endforeach;
  ?>
  </ul>
	<ul id="isotope-sort-direction" class="option-set clearfix" data-option-key="sortAscending">
    <li><a class="sortbutton" href="#sortAscending=true" data-option-value="true" class="selected"><?php print t('Ascending'); ?></a></li>
    <li><a class="sortbutton" href="#sortAscending=false" data-option-value="false"><?php print t('Descending');?></a></li>
  </ul>
</div>
