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

/**
 * Implements hook_default_profile2_type().
 */
function trainer_workflow_default_profile2_type() {
  $items = array();
  $items['trainer'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "trainer",
    "label" : "Trainer profile",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
