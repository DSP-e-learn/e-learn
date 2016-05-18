<?php
/**
 * @file
 * company_profile.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function company_profile_default_profile2_type() {
  $items = array();
  $items['company'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "company",
    "label" : "Company",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
