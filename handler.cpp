#include "handler.hpp"
#include <iostream>
#include <event.h>
#include <evhttp.h>
#include <jansson.h>
#include <iostream>
#include "json_converter.hpp"
#include <string.h>


void unspecified_URL(struct evhttp_request *request, void *arg){

    struct evbuffer *buffer = evbuffer_new();
    if (buffer == NULL){
        fprintf(stderr, "ERROR: Can not create evbuffer(An evbuffer is an opaque data type for efficiently buffering data to be sent or received on the network.)");
    }
    evbuffer_add_printf(buffer, "Takogo net");
    printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
    evhttp_send_reply(request, 404, "Not Found", buffer);
    evbuffer_free(buffer);
}

void test(struct evhttp_request *request, void *arg) {
    printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
    struct event_base *base = (struct event_base *)arg;
    struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
    size_t requestLen = evbuffer_get_length(requestBuffer);
    char *requestDataString = (char *)malloc(sizeof(char) * requestLen);
    memset(requestDataString, 0, requestLen);
    evbuffer_copyout(requestBuffer, requestDataString, requestLen);
    char errorText[1024];
    json_error_t error;
    json_t *requestJSON = json_loadb(requestDataString, requestLen, 0, &error);
    struct evbuffer *responseBuffer = evbuffer_new();

    if (requestJSON != NULL){
        requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
        printf("%s\n",requestDataString);
        JSONConverter jsonConv;
        defaultMessageStrcut msg = jsonConv.fromJsonToDefaultMessage(requestJSON);
        printf("%s\n", msg.text.c_str());
        evbuffer_add_printf(responseBuffer, "%s\n", msg.text.c_str());
        evhttp_send_reply(request, HTTP_OK, "OK", responseBuffer);
    } else {
        snprintf(errorText, 1024, "Input error: on line %d: %s\n", error.line, error.text);
    }
}


void sendBlock(struct evhttp_request *request, void *arg) {
    printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
    struct event_base *base = (struct event_base *)arg;
    struct evbuffer *requestBuffer = evhttp_request_get_input_buffer(request);
    size_t requestLen = evbuffer_get_length(requestBuffer);
    char *requestDataString = (char *)malloc(sizeof(char) * requestLen);
    memset(requestDataString, 0, requestLen);
    evbuffer_copyout(requestBuffer, requestDataString, requestLen);
    char errorText[1024];
    json_error_t error;
    json_t *requestJSON = json_loadb(requestDataString, requestLen, 0, &error);
    struct evbuffer *responseBuffer = evbuffer_new();

    if (requestJSON != NULL){
        requestDataString = json_dumps(requestJSON, JSON_INDENT(4));
        printf("%s\n",requestDataString);
        JSONConverter jsonConv;
        Transaction transaction = jsonConv.fromJsonGetTransaction(requestJSON);
        std::cout << "sender: " << transaction.sender << std::endl;
        std::cout << "recipient: " << transaction.recipient << std::endl;
        std::cout << "value: " << transaction.value << std::endl;
        evhttp_send_reply(request, HTTP_OK, "OK", responseBuffer);
    } else {
        snprintf(errorText, 1024, "Input error: on line %d: %s\n", error.line, error.text);
    }
}
