#ifndef ASTRACHAIN_NODE_SERVER_HPP
#define ASTRACHAIN_NODE_SERVER_HPP

#include "Node.hpp"
#include "Transaction.hpp"
#include "Block.hpp"

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

    /**
     * Get new transaction from wallet and give to node
     * @param transaction new transaction from a wallet
     */
    void getNewTransactionToNode(Transaction transaction);

    /**
     * Broadcast mined block
     * @param block mined block
     */
    void broadcastBlock(Block block);

    /**
     * Get new mined block from other nodes and give to node
     * @param block new mined block from other nodes
     */
    void getNewBlockToNode(Block block);

    /**
     * Send last blocks to updating node
     * @param blocks last blocks to updating node
     */
    void sendBlocks(std::vector<Block> blocks);

    /**
     * Ask other nodes if need to update
     */
    bool checkUpToDate();

    /**
     * Send chain length to asking node
     * @param length chain length
     */
    void sendBlockchainLength(int length);

};

#endif //ASTRACHAIN_NODE_SERVER_HPP