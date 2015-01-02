<?php
?>
<?php foreach ($items as $delta => $item): ?><?php print str_replace(' ', '-', render($item)); ?> <?php endforeach; ?>