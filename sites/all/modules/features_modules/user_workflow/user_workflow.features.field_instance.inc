<?php
/**
 * @file
 * user_workflow.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function user_workflow_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'profile2-main-field_full_name'.
  $field_instances['profile2-main-field_full_name'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_full_name',
    'label' => 'Full name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Full name');

  return $field_instances;
}
