#include "Node.hpp"
#include "ObserverErrors.hpp"

Node::Node() {
    nodeDatabaseObserver = nullptr;
    nodeServerObserver = nullptr;
}

Node::~Node() {}

void Node::registerDatabaseObserver(NodeDatabase* nodeDatabase) {
    if (!nodeDatabaseObserver) {
        nodeDatabaseObserver = nodeDatabase;
    } else {
        throw ObserverPresent();
    }
}

void Node::removeDatabaseObserver() {
    if (nodeDatabaseObserver) {
        nodeDatabaseObserver = nullptr;
    } else {
        throw NoObserver();
    }
}

void Node::registerServerObserver(NodeServer* nodeServer) {
    if (!nodeServerObserver) {
        nodeServerObserver = nodeServer;
    } else {
        throw ObserverPresent();
    }
}

void Node::removeServerObserver() {
    if (nodeServerObserver) {
        nodeServerObserver = nullptr;
    } else {
        throw NoObserver();
    }
}