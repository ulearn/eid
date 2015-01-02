<?php
?>
<?php
// Print out the main part of the form.
// Feel free to break this up and move the pieces within the array.
print drupal_render($form['submitted']);

// Always print out the entire $form. This renders the remaining pieces of the
// form that haven't yet been rendered above.
print drupal_render_children($form);