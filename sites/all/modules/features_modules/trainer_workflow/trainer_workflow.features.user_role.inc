<?php
/**
 * @file
 * trainer_workflow.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function trainer_workflow_user_default_roles() {
  $roles = array();

  // Exported role: trainer.
  $roles['trainer'] = array(
    'name' => 'trainer',
    'weight' => 3,
  );

  return $roles;
}
