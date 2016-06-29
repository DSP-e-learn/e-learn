<?php

/**
 * @file
 * Template for invoice when included in other pages.
 */

?>
<?php
print drupal_render_children($form) ;
echo elearn_trainer_invoice_html($form['invid']['#value'], true)  ;

?>
  
