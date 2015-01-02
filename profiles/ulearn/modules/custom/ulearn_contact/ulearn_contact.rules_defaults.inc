<?php
/**
 * @file
 * ulearn_contact.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ulearn_contact_default_rules_configuration() {
  $items = array();
  $items['rules_custom_entityform_notification_rule'] = entity_import('rules_config', '{ "rules_custom_entityform_notification_rule" : {
      "LABEL" : "Custom EntityForm Notification Rule",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "variable_email" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "entity" ], "type" : "entityform" } }
      ],
      "DO" : [
        { "variable_email_mail" : {
            "to" : "[site:ulearn-admin-email]",
            "variable" : "ulearn_contact_admin_mail_[mail_part]",
            "language" : "default",
            "from" : "[site:mail]"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  return $items;
}
