<?php
/**
 * @file
 * company_profile.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function company_profile_default_rules_configuration() {
  $items = array();
  $items['admin_workflow_block_company_account_on_registration'] = entity_import('rules_config', '{ "admin_workflow_block_company_account_on_registration" : {
      "LABEL" : "Block company account on registration",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "company", "registration" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "7" : "7" } } } }
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
