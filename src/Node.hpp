#ifndef ASTRACHAIN_NODE_HPP
#define ASTRACHAIN_NODE_HPP

#include "NodeDatabase.hpp"
#include "NodeServer.hpp"

class NodeDatabase;
class NodeServer;

/**
 * Mining node
 */
class Node {

private:

    NodeDatabase* nodeDatabaseObserver;
    NodeServer* nodeServerObserver;

public:

    Node();

    ~Node();

    void registerDatabaseObserver(NodeDatabase* nodeDatabase);

    void removeDatabaseObserver();

    void registerServerObserver(NodeServer* nodeServer);

    void removeServerObserver();

};


#endif //ASTRACHAIN_NODE_HPP