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

