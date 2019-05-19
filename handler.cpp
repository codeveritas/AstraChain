#include "handler.h"
#include <iostream>
#include <event.h>
#include <evhttp.h>
#include <jansson.h>
#include <iostream>


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
    struct evkeyvalq uri_params;
    printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
    evhttp_parse_query (request->uri, &uri_params);
    printf("%s\n",request->uri);
//    size_t requestLen = evbuffer_get_length(requestBuffer);
//    char *requestDataString = (char *)malloc(sizeof(char) * requestLen);
//    memset(requestDataString, 0, requestLen);
//    evbuffer_copyout(requestBuffer, requestDataString, requestLen);
//    char errorText[1024];
//    json_error_t error;
//    json_t *requestJSON = json_loadb(requestDataString, requestLen, 0, &error);
//    struct evbuffer *buffer = evbuffer_new();
//    if (buffer == NULL) {
//        fprintf(stderr,
//                "ERROR: Can not create evbuffer(An evbuffer is an opaque data type for efficiently buffering data to be sent or received on the network.)");
//    }
//    evbuffer_add_printf(buffer, " test");
//    printf ("Request from: %s:%d URI: %s\n", request->remote_host, request->remote_port, request->uri);
//    evhttp_send_reply(request, 404, "Not Found", buffer);
//    evbuffer_free(buffer);
}

