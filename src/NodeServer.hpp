#ifndef ASTRACHAIN_NODE_SERVER_HPP
#define ASTRACHAIN_NODE_SERVER_HPP

#include "Node.hpp"

class Node;

/**
 * Server for a mining node
 */
class NodeServer {

private:

    Node* nodeObserver;

public:

    NodeServer();

    ~NodeServer();

    void registerNodeObserver(Node* node);

    void removeNodeObserver();

};

#endif //ASTRACHAIN_NODE_SERVER_HPP