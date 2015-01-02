<?php
?>
<?php foreach ($items as $delta => $item): ?>
<li><?php print $item_attributes[$delta]; ?><?php print render($item); ?></li>
<?php endforeach; ?>