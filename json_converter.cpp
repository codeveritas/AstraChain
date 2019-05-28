//
// Created by Артем Закиров on 2019-05-19.
//
#include <iostream>
#include <jansson.h>

#include "json_converter.hpp"
defaultMessageStrcut JSONConverter::fromJsonToDefaultMessage(json_t *requestJSON) {
    json_t *root = json_object_get(requestJSON, "message");
    json_t *text_json = json_object_get(root, "text");
    defaultMessageStrcut msg(json_string_value(text_json));
    return  msg;
}

Transaction JSONConverter::fromJsonGetTransaction(json_t *requestJSON) {
    json_t *serverType = json_object_get(requestJSON, "serverType");
    json_t *function = json_object_get(requestJSON, "function");
    if (*function == sendBlock) {
        json_t *Transaction = json_object_get(requestJSON, "Transaction");
        json_t *sender = json_object_get(Transaction, "sender");
        json_t *recipient = json_object_get(Transaction, "recipient");
        json_t *value = json_object_get(Transaction, "value");
    }
    Transaction transaction{*sender, *recipient, *value};
    //defaultMessageStrcut msg(json_string_value(text_json));
    return  transaction;
}
