#ifndef ASTRACHAIN_NODE_DATABASE_HPP
#define ASTRACHAIN_NODE_DATABASE_HPP

#include "Node.hpp"
#include "Block.hpp"

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

    /**
     * Write new block to database
     * @param block block to be added to database
     */
    void addBlock(Block block);

    /**
     * Get chain length
     */
    uint64_t getBlockchainLength();

    /**
     * Get last block
     */
    Block getLastBlock();

};

#endif //ASTRACHAIN_NODE_DATABASE_HPP