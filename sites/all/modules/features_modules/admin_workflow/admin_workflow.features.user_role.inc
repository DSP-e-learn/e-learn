<?php
/**
 * @file
 * admin_workflow.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function admin_workflow_user_default_roles() {
  $roles = array();

  // Exported role: site_admin.
  $roles['site_admin'] = array(
    'name' => 'site_admin',
    'weight' => 5,
  );

  return $roles;
}
