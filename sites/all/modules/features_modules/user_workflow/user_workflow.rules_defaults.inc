<?php
/**
 * @file
 * user_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_after_finishing_a_quiz'] = entity_import('rules_config', '{ "rules_after_finishing_a_quiz" : {
      "LABEL" : "After finishing a Quiz",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "certificate", "quiz" ],
      "REQUIRES" : [ "rules", "certificate", "entity" ],
      "ON" : { "quiz_result_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "quiz-result:score" ], "op" : "\\u003E", "value" : "75" } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "11111111111111111111111111111111 - [quiz-result:is-evaluated] - [quiz-result:score]" } },
        { "certificate_rules_award_certificate" : [] }
      ]
    }
  }');
  $items['rules_go_to_checkout_page'] = entity_import('rules_config', '{ "rules_go_to_checkout_page" : {
      "LABEL" : "Go to checkout page",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkout" ],
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "DO" : [ { "redirect" : { "url" : "cart" } } ]
    }
  }');
  $items['rules_grant_access_to_course_after_purchase'] = entity_import('rules_config', '{ "rules_grant_access_to_course_after_purchase" : {
      "LABEL" : "Grant access to Course after purchase",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "course", "purchase" ],
      "REQUIRES" : [ "rules", "rules_scheduler", "commerce_order", "commerce_payment" ],
      "ON" : { "commerce_payment_order_paid_in_full" : [] },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "line_item" : "Line item" },
            "DO" : [
              { "component_rules_grant_access_to_course_if_product_has_reference_to_it" : { "line_item" : [ "line_item" ] } },
              { "schedule" : {
                  "component" : "rules_prohabit_access_to_course_after_xx_minutes",
                  "date" : { "select" : "commerce-order:created", "date_offset" : { "value" : 180 } },
                  "identifier" : "[line-item:order-id]  - [line-item:commerce-product] - [commerce-order:owner]",
                  "param_line_item" : [ "line-item" ]
                }
              }
            ]
          }
        },
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "completed" } }
      ]
    }
  }');
  $items['rules_grant_access_to_course_if_product_has_reference_to_it'] = entity_import('rules_config', '{ "rules_grant_access_to_course_if_product_has_reference_to_it" : {
      "LABEL" : "Grant access to Course if product has reference to it",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "access", "course" ],
      "REQUIRES" : [ "rules", "content_access_rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "line-item" ], "field" : "commerce_product" } },
        { "entity_has_field" : {
            "entity" : [ "line-item:commerce-product" ],
            "field" : "field_course_reference"
          }
        }
      ],
      "DO" : [
        { "content_access_action_user_grant" : {
            "node" : [ "line-item:commerce-product:field-course-reference" ],
            "content_access_user_view" : [ "line-item:order:owner" ],
            "content_access_user_update" : [ "" ],
            "content_access_user_delete" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_prohabit_access_to_course_after_xx_minutes'] = entity_import('rules_config', '{ "rules_prohabit_access_to_course_after_xx_minutes" : {
      "LABEL" : "Prohabit access to Course after XX minutes",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "access", "course" ],
      "REQUIRES" : [ "rules", "content_access_rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "line-item" ], "field" : "commerce_product" } },
        { "entity_has_field" : {
            "entity" : [ "line-item:commerce-product" ],
            "field" : "field_course_reference"
          }
        }
      ],
      "DO" : [
        { "content_access_action_user_grant" : {
            "node" : [ "line-item:commerce-product:field-course-reference" ],
            "content_access_user_view" : [ "line-item:order:owner" ],
            "content_access_user_update" : [ "" ],
            "content_access_user_delete" : [ "" ]
          }
        },
        { "content_access_action_user_revoke" : {
            "node" : [ "line-item:commerce-product:field-course-reference" ],
            "content_access_user_view" : [ "line-item:order:owner" ],
            "content_access_user_update" : [ "" ],
            "content_access_user_delete" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
