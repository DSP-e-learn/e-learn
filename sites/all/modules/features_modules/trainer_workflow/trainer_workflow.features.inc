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
 * Implements hook_default_payment_method().
 */
function trainer_workflow_default_payment_method() {
  $items = array();
  $items['no_payment_required'] = entity_import('payment_method', '{
    "controller_data" : {
      "message" : "",
      "status" : "payment_status_success",
      "text_format" : "plain_text"
    },
    "enabled" : true,
    "name" : "no_payment_required",
    "title_specific" : "No payment required",
    "title_generic" : "No payment required",
    "uid" : 0,
    "rdf_mapping" : [],
    "controller_class_name" : "PaymentMethodBasicController"
  }');
  return $items;
}
