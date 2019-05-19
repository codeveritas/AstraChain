//
// Created by Артем Закиров on 2019-05-19.
//
#ifndef JSON_CONVERTER
#define JSON_CONVERTER

#include <iostream>
#include <errno.h>
#include <event.h>
#include <evhttp.h>
#include <jansson.h>

class defaultMessageStrcut {
public:
    std::string text
    defaultMessage(std::string message) : message(message) {}
};


class JSONConverter {
public:
    defaultMessageStrcut fromJsonToDefaultMessage(json_t *requestJSON);
};

#endif // JSON_CONVERTER
