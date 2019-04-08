#include <iostream>
#include <errno.h>
#include <event.h>
#include <evhttp.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void brokenPipe(int signum) {
    fprintf(stderr, "Broken Pipe (%d)\n", signum);
}
void logger(struct evhttp_request *request) {
    printf("URL '%s' from %s\n", evhttp_request_uri(request), evhttp_request_get_host(request));
}
void generic_handler(struct evhttp_request *request, void *arg) {
    logger(request);
    struct evbuffer *buf;
    buf = evbuffer_new();

    if (buf == NULL) {
        std::cout << "Failed to create response buffer " << strerror(errno) << std::endl;
    }

    evbuffer_add_printf(buf, "URL %s doesn't exist.", evhttp_request_uri(request));
    evhttp_send_reply(request, HTTP_BADMETHOD, "Bad Method", buf);
}


int main(int argc, char **argv) {
    short http_port = 8000;
    const char *http_addr = "127.0.0.1";
    struct evhttp *http_server = NULL;

    if (argc > 1) {
        http_addr = argv[1];

        if (argc > 2) {
            http_port = atol(argv[2]);
        }
    }
    /* Don't exit on broken pipe (just fail with message). It's just recomended... */
    signal(SIGPIPE, brokenPipe);

    event_init();
    http_server = evhttp_start(http_addr, http_port);

    evhttp_set_gencb(http_server, generic_handler, NULL);

    fprintf(stderr, "Server started on %s port %d\n", http_addr, http_port);

    event_dispatch();
    evhttp_free(http_server);
    return 0;
}