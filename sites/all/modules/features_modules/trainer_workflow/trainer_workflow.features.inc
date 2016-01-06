<?php
/**
 * @file
 * trainer_workflow.features.inc
 */

/**
 * Implements hook_node_info().
 */
function trainer_workflow_node_info() {
  $items = array(
    'cour' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'course_product_display' => array(
      'name' => t('Course product display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
