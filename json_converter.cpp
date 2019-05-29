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
    string sender = "default", recipient = "default";
    int value= 0;
    json_t *serverType = json_object_get(requestJSON, "serverType");
    json_t *function = json_object_get(requestJSON, "function");


    if ((string)json_string_value(function) == "sendBlock") {
        json_t *Transaction = json_object_get(requestJSON, "Transaction");

        json_t *sender_json = json_object_get(Transaction, "sender");
        sender = (string)json_string_value(sender_json);

        json_t *recipient_json = json_object_get(Transaction, "recipient");
        recipient = (string)json_string_value(recipient_json);

        json_t *value_json = json_object_get(Transaction, "value");
        value = stoi((string)json_string_value(value_json));
    }
    // Transaction transaction("Ann", "Mike", 5);
    Transaction transaction(sender, recipient, value);
    return  transaction;
}
