<?php
/**
 * @file
 * admin_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function admin_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_block_trainer_account_on_registration'] = entity_import('rules_config', '{ "rules_block_trainer_account_on_registration" : {
      "LABEL" : "Block trainer account on registration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "registration", "trainer" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [
        { "user_block" : { "account" : [ "account" ] } },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "6" : "6" } },
            "subject" : "Account details for [account:name] at [site:name] (pending admin approval)",
            "message" : " [account:name] has applied for an account.\\r\\n\\r\\n[account:edit-url]\\r\\n",
            "from" : "[site:mail]"
          }
        }
      ]
    }
  }');
  return $items;
}
