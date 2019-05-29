#ifndef HANDLER
#define HANDLER

#include <event.h>
#include <evhttp.h>
#include <jansson.h>

void unspecified_URL(struct evhttp_request *request, void *arg);
void test(struct evhttp_request *request, void *arg);
void sendBlock(struct evhttp_request *request, void *arg);


#endif //HANDLER
