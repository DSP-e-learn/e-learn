<?php
/**
 * @file
 * user_workflow.features.inc
 */

/**
 * Implements hook_default_payment_method().
 */
function user_workflow_default_payment_method() {
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

/**
 * Implements hook_default_profile2_type().
 */
function user_workflow_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "User profile",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
