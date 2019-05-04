#include "NodeServer.hpp"
#include "ObserverErrors.hpp"

NodeServer::NodeServer() {
    nodeObserver = nullptr;
}

NodeServer::~NodeServer() {}

void NodeServer::registerNodeObserver(Node* node) {
    if (!nodeObserver) {
        nodeObserver = node;
    } else {
        throw ObserverPresent();
    }
}

void NodeServer::removeNodeObserver() {
    if (nodeObserver) {
        nodeObserver = nullptr;
    } else {
        throw NoObserver();
    }
}