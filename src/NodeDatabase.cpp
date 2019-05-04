#include "NodeDatabase.hpp"
#include "ObserverErrors.hpp"

NodeDatabase::NodeDatabase() {
    nodeObserver = nullptr;
}

NodeDatabase::~NodeDatabase() {}

void NodeDatabase::registerNodeObserver(Node* node) {
    if (!nodeObserver) {
        nodeObserver = node;
    } else {
        throw ObserverPresent();
    }
}

void NodeDatabase::removeNodeObserver() {
    if (nodeObserver) {
        nodeObserver = nullptr;
    } else {
        throw NoObserver();
    }
}