//
// Created by Артем Закиров on 2019-05-19.
//
#include <iostream>
#include <jansson.h>
#include <string>
#include "json_converter.hpp"
using namespace std;

defaultMessageStrcut JSONConverter::fromJsonToDefaultMessage(json_t *requestJSON) {
    json_t *root = json_object_get(requestJSON, "message");
    json_t *text_json = json_object_get(root, "text");
    defaultMessageStrcut msg(json_string_value(text_json));
    return  msg;
}

Transaction JSONConverter::fromJsonGetTransaction(json_t *requestJSON) {
    json_t *serverType = json_object_get(serverType, "serverType");
    json_t *function = json_object_get(function, "function");

    if (json_string_value(function) == "sendBlock") {
        json_t *Transaction = json_object_get(Transaction, "Transaction");

        json_t *sender_json = json_object_get(Transaction, "sender");
        string sender = json_string_value(sender_json);

        json_t *recipient_json = json_object_get(Transaction, "recipient");
        string recipient = json_string_value(recipient_json);

        json_t *value_json = json_object_get(Transaction, "value");
        string value = json_string_value(value_json);
    }
    Transaction transaction("Ann", "Mike", 5);
    //defaultMessageStrcut msg(json_string_value(text_json));
    return  transaction;
}
