//
// Created by Артем Закиров on 2019-05-19.
//
#ifndef JSON_CONVERTER
#define JSON_CONVERTER

#include <iostream>
#include <string>
#include <errno.h>
#include <event.h>
#include <evhttp.h>
#include <jansson.h>

class Transaction {
public:
    const std::string sender;
    const std::string recipient;
    const uint64_t value;
    Transaction() : sender(""), recipient(""), value(0) {}
    Transaction(std::string _sender, std::string _recipient, int64_t _value) : sender(_sender), recipient(_recipient), value(_value) {};
    ~Transaction(){};
};


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
