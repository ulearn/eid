<?php
/**
 * @file
 * ulearn_commerce.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ulearn_commerce_default_rules_configuration() {
  $items = array();
  $items['commerce_checkout_ulearn_send_order_notification_email'] = entity_import('rules_config', '{ "commerce_checkout_ulearn_send_order_notification_email" : {
      "LABEL" : "Send an order notification e-mail",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "ULearn" ],
      "REQUIRES" : [ "variable_email", "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "variable_email_mail" : {
            "to" : [ "commerce-order:mail" ],
            "variable" : "ulearn_commerce_order_created_mail_[mail_part]",
            "language" : "default"
          }
        },
        { "variable_email_mail" : {
            "to" : "[site:ulearn-admin-email]",
            "variable" : "ulearn_commerce_order_admin_mail_[mail_part]",
            "language" : "default"
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_ulearn_settings_commerce_checkout_new_account'] = entity_import('rules_config', '{ "commerce_checkout_ulearn_settings_commerce_checkout_new_account" : {
      "LABEL" : "Create a new account for an anonymous order",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "2",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "ULearn" ],
      "REQUIRES" : [
        "rules",
        "commerce",
        "commerce_checkout",
        "commerce_registration",
        "ulearn_commerce"
      ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:uid" ], "value" : "0" } },
        { "NOT entity_exists" : {
            "type" : "user",
            "property" : "mail",
            "value" : [ "commerce-order:mail" ]
          }
        },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_name" : [ "commerce-order:mail-username" ],
              "param_mail" : [ "commerce-order:mail" ]
            },
            "PROVIDE" : { "entity_created" : { "account_created" : "Created account" } }
          }
        },
        { "data_set" : { "data" : [ "account-created:status" ], "value" : 1 } },
        { "data_set" : {
            "data" : [ "account-created:roles" ],
            "value" : { "value" : { "66784200" : "66784200" } }
          }
        },
        { "entity_save" : { "data" : [ "account-created" ], "immediate" : 1 } },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "commerce-order:mail" ],
              "limit" : 1
            },
            "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched account" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "account-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "send_account_email" : { "account" : [ "list-item" ], "email_type" : "register_admin_created" } },
              { "data_set" : { "data" : [ "commerce-order:uid" ], "value" : [ "list-item:uid" ] } },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-billing:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              }
            ]
          }
        },
        { "commerce_registration_add_author_uid" : { "commerce_order" : [ "commerce_order" ] } },
        { "ulearn_commerce_log_user_in" : { "account" : [ "account-created" ] } }
      ]
    }
  }');
  $items['commerce_payment_ularn_paypal_wpp_test'] = entity_import('rules_config', '{ "commerce_payment_ularn_paypal_wpp_test" : {
      "LABEL" : "PayPal WPP [Test]",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-1",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Payment" ],
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : { "commerce_payment_methods" : [] },
      "DO" : [
        { "commerce_payment_enable_paypal_wpp" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : { "value" : {
                "method_id" : "paypal_wpp",
                "settings" : {
                  "api_username" : "",
                  "api_password" : "",
                  "api_signature" : "",
                  "server" : "sandbox",
                  "card_types" : {
                    "visa" : "visa",
                    "mastercard" : "mastercard",
                    "amex" : "amex",
                    "discover" : "discover",
                    "maestro" : 0,
                    "solo" : 0
                  },
                  "code" : 1,
                  "currency_code" : "USD",
                  "allow_supported_currencies" : 0,
                  "txn_type" : "auth_capture",
                  "log" : { "request" : "request", "response" : "response" }
                }
              }
            }
          }
        }
      ]
    }
  }');
  $items['commerce_payment_ulearn_bank_transfer'] = entity_import('rules_config', '{ "commerce_payment_ulearn_bank_transfer" : {
      "LABEL" : "Pay Cash \\/ Credit Card In Reception",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Payment" ],
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : { "commerce_payment_methods" : [] },
      "DO" : [
        { "commerce_payment_enable_bank_transfer" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : { "value" : {
                "method_id" : "bank_transfer",
                "settings" : {
                  "details" : {
                    "account_owner" : "ULearn Limited",
                    "account_number" : "90814728",
                    "account_iban" : "IE50 BOFI 9001 7290 8147 28",
                    "bank_code_appellation" : "90-01-72",
                    "bank_code" : "BANKCODE",
                    "account_swift" : "BOFIIE2D",
                    "account_bank" : "Bank of Irleand",
                    "account_branch" : "Bank of Ireland, Ranelagh, Dublin 6, Ireland"
                  },
                  "subject_oid" : 0,
                  "policy" : "These are payment instruction for Bank Transfers."
                }
              }
            }
          }
        }
      ]
    }
  }');
  $items['commerce_payment_ulearn_pay_to_study_test'] = entity_import('rules_config', '{ "commerce_payment_ulearn_pay_to_study_test" : {
      "LABEL" : "Pay to Study [Test]",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Payment" ],
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : { "commerce_payment_methods" : [] },
      "DO" : [
        { "commerce_payment_enable_commerce_paytostudy" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : { "value" : {
                "method_id" : "commerce_paytostudy",
                "settings" : {
                  "username_loginto" : "test-xml-user",
                  "password_loginto" : "TAhjgasd623asHS",
                  "convertOnly" : 0,
                  "paytostudy_post_request_url" : "https:\\/\\/test-xml-service.studentfees.com\\/paymentservice.dll",
                  "bank_account_id" : "3438",
                  "paytostudy_instructions" : "",
                  "paytostudy_logo_url" : "profiles\\/ulearn\\/themes\\/at_ulearn\\/images\\/paytostudyLogo.png",
                  "paytostudy_phone_field_name" : "field_user_phone",
                  "debug_mode" : 1
                }
              }
            }
          }
        }
      ]
    }
  }');
  $items['rules_apply_registration_fee'] = entity_import('rules_config', '{ "rules_apply_registration_fee" : {
      "LABEL" : "Apply registration fee",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_fees" ],
      "ON" : { "commerce_fees_order" : [] },
      "DO" : [
        { "component_rules_apply_registration_fee_per_product" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  $items['rules_apply_registration_fee_per_product'] = entity_import('rules_config', '{ "rules_apply_registration_fee_per_product" : {
      "LABEL" : "Apply registration fee per product",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order", "commerce_fees" ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce order", "type" : "commerce_order" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "commerce_order_contains_product_type" : {
                  "commerce_order" : [ "commerce_order" ],
                  "product_type" : { "value" : { "course" : "course", "special_course" : "special_course" } },
                  "operator" : "\\u003E=",
                  "value" : "1"
                }
              }
            ],
            "DO" : [
              { "commerce_fees_apply" : {
                  "entity" : [ "commerce-order" ],
                  "fee" : "registration_fee",
                  "amount" : "5000",
                  "currency_code" : "EUR"
                }
              }
            ],
            "LABEL" : "General course fee"
          }
        },
        { "RULE" : {
            "IF" : [
              { "commerce_order_contains_product_type" : {
                  "commerce_order" : [ "commerce_order" ],
                  "product_type" : { "value" : { "accommodation" : "accommodation" } },
                  "operator" : "\\u003E=",
                  "value" : "1"
                }
              }
            ],
            "DO" : [
              { "commerce_fees_apply" : {
                  "entity" : [ "commerce-order" ],
                  "fee" : "registration_fee",
                  "amount" : "6500",
                  "currency_code" : "EUR"
                }
              }
            ],
            "LABEL" : "Accommodation fee"
          }
        }
      ]
    }
  }');
  $items['rules_assign_billing_profile_name_values'] = entity_import('rules_config', '{ "rules_assign_billing_profile_name_values" : {
      "LABEL" : "Assign values for name of billing profile",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "Commerce customer profile", "ULearn" ],
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_customer_profile_presave" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-customer-profile" ],
            "type" : "commerce_customer_profile",
            "bundle" : { "value" : { "billing" : "billing" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-customer-profile" ],
            "field" : "field_user_first_name"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-customer-profile" ],
            "field" : "field_user_last_name"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "commerce-customer-profile" ],
            "field" : "commerce_customer_address"
          }
        },
        { "entity_is_new" : { "entity" : [ "commerce-customer-profile" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "commerce-customer-profile:commerce-customer-address:name-line" ],
            "value" : "[commerce-customer-profile:field-user-first-name] [commerce-customer-profile:field-user-last-name]"
          }
        }
      ]
    }
  }');
  $items['rules_redirect_cart_after_adding_product'] = entity_import('rules_config', '{ "rules_redirect_cart_after_adding_product" : {
      "LABEL" : "Redirect to cart after adding product",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Cart", "ULearn" ],
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "DO" : [ { "redirect" : { "url" : "cart" } } ]
    }
  }');
  $items['rules_ulearn_commerce_change_order_status_complete'] = entity_import('rules_config', '{ "rules_ulearn_commerce_change_order_status_complete" : {
      "LABEL" : "Complete the order if there is no balance due",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-2",
      "OWNER" : "rules",
      "TAGS" : [ "ULearn" ],
      "REQUIRES" : [ "commerce_payment", "commerce_order", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "commerce_payment_order_balance_comparison" : { "commerce_order" : [ "commerce_order" ], "value" : "0" } }
      ],
      "DO" : [
        { "commerce_order_update_state" : { "commerce_order" : [ "commerce_order" ], "order_state" : "completed" } },
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "completed" } }
      ]
    }
  }');
  $items['ulearn_commerce_paytostudy_order_notification_email'] = entity_import('rules_config', '{ "ulearn_commerce_paytostudy_order_notification_email" : {
      "LABEL" : "Send an order notification e-mail to paytostudy",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "ULearn" ],
      "REQUIRES" : [ "commerce_payment", "variable_email", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "commerce_payment_selected_payment_method" : {
            "commerce_order" : [ "commerce_order" ],
            "method_id" : "commerce_paytostudy"
          }
        }
      ],
      "DO" : [
        { "variable_email_mail" : {
            "to" : "invoices@paytostudy.com",
            "variable" : "ulearn_commerce_order_created_mail_[mail_part]",
            "language" : "default"
          }
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_default_rules_configuration_alter().
 */
function ulearn_commerce_default_rules_configuration_alter(&$configs) {
  $configs['commerce_checkout_order_status_update']->weight = '-5';
}
