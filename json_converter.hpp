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
    std::string text;
    defaultMessageStrcut(std::string text) : text(text) {}
};


class JSONConverter {
public:
    defaultMessageStrcut fromJsonToDefaultMessage(json_t *requestJSON);
    Transaction fromJsonGetTransaction(json_t *requestJSON);
};

#endif // JSON_CONVERTER
