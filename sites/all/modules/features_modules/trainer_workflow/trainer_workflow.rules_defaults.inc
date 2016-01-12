<?php
/**
 * @file
 * trainer_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function trainer_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_create_pd_and_product'] = entity_import('rules_config', '{ "rules_create_pd_and_product" : {
      "LABEL" : "RULE - Create Product display and product after QUIZ was UPDATED",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "course", "quiz" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--quiz" : { "bundle" : "quiz" } },
      "DO" : [
        { "entity_query" : {
            "USING" : { "type" : "node", "property" : "field_quiz", "value" : [ "node" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "drupal_message" : { "message" : "ddddddddddddddddddddddddddddddd - [entity-fetched:0:title]" } },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "entity_query" : {
                  "USING" : {
                    "type" : "commerce_product",
                    "property" : "field_course_reference",
                    "value" : [ "list-item" ]
                  },
                  "PROVIDE" : { "entity_fetched" : { "entity_fetched_product_referensig_course" : "Fetched entity" } }
                }
              },
              { "component_rules_create_pd_and_product_for_a_course" : {
                  "node" : [ "list-item" ],
                  "list_of_products" : [ "entity-fetched-product-referensig-course" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_create_pd_and_product_for_a_course'] = entity_import('rules_config', '{ "rules_create_pd_and_product_for_a_course" : {
      "LABEL" : "COMPONENT: create PD and Product for a Course",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "course" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node Course", "type" : "node" },
        "list_of_products" : { "label" : "List of Products that refer Node Course", "type" : "list" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "list-of-products" ], "op" : "\\u003C", "value" : "1" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_category" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "commerce_product",
              "param_sku" : "[node:title] - [node:nid]",
              "param_type" : "product",
              "param_title" : "[node:title]",
              "param_creator" : [ "node:author" ],
              "param_commerce_price" : { "value" : { "amount" : 1300, "currency_code" : "USD" } }
            },
            "PROVIDE" : { "entity_created" : { "entity_created_product" : "Created entity of type Product" } }
          }
        },
        { "entity_save" : { "data" : [ "entity-created-product" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "entity-created-product:field-course-reference" ],
            "value" : [ "node" ]
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "course_product_display",
              "param_title" : "[node:title]",
              "param_author" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_pd" : "Created entity" } }
          }
        },
        { "entity_save" : { "data" : [ "entity-created-pd" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "entity-created-pd:field-product" ],
            "value" : [ "entity-created-product" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-pd:field-pd-category" ],
            "value" : [ "node:field-category" ]
          }
        }
      ]
    }
  }');
  $items['rules_create_pd_and_product_old'] = entity_import('rules_config', '{ "rules_create_pd_and_product_old" : {
      "LABEL" : "RULE ------Create Product display and product after QUIZ was UPDATED",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "course", "quiz" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--quiz" : { "bundle" : "quiz" } },
      "DO" : [
        { "entity_query" : {
            "USING" : { "type" : "node", "property" : "field_quiz", "value" : [ "node" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "entity_query" : {
                  "USING" : {
                    "type" : "commerce_product",
                    "property" : "field_course_reference",
                    "value" : [ "list-item" ]
                  },
                  "PROVIDE" : { "entity_fetched" : { "entity_fetched_product_referensig_course" : "Fetched entity" } }
                }
              },
              { "component_rules_create_pd_and_product_for_a_course" : {
                  "node" : [ "list-item" ],
                  "list_of_products" : [ "entity-fetched-product-referensig-course" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_create_quiz_after_course_was_created'] = entity_import('rules_config', '{ "rules_create_quiz_after_course_was_created" : {
      "LABEL" : "Create a quiz after a Course was created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "course", "quiz" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--course" : { "bundle" : "course" } },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "quiz",
              "param_title" : "A quiz for [node:title]",
              "param_author" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } },
        { "data_set" : { "data" : [ "node:field-quiz" ], "value" : [ "entity-created" ] } },
        { "redirect" : { "url" : "node\\/[entity-created:nid]\\/edit" } }
      ]
    }
  }');
  return $items;
}
