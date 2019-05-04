#ifndef ASTRACHAIN_NODE_DATABASE_HPP
#define ASTRACHAIN_NODE_DATABASE_HPP

#include "Node.hpp"

class Node;

/**
 * Database for a mining node
 */
class NodeDatabase {

private:

    Node* nodeObserver;

public:

    NodeDatabase();

    ~NodeDatabase();

    void registerNodeObserver(Node* node);

    void removeNodeObserver();

};

#endif //ASTRACHAIN_NODE_DATABASE_HPP