<?php
/**
 * @file
 * user_workflow.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_workflow_user_default_roles() {
  $roles = array();

  // Exported role: user.
  $roles['user'] = array(
    'name' => 'user',
    'weight' => 4,
  );

  return $roles;
}
