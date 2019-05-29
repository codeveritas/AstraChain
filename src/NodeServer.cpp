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

/**
 * Get new transaction from wallet and give to node
 * @param transaction new transaction from a wallet
 */
void getNewTransactionToNode(Transaction transaction) {
    return;
}

/**
 * Broadcast mined block
 * @param block mined block
 */
void broadcastBlock(Block block) {
    return;
}

/**
 * Get new mined block from other nodes and give to node
 * @param block new mined block from other nodes
 */
void getNewBlockToNode(Block block) {
    return;
}

/**
 * Send last blocks to updating node
 * @param blocks last blocks to updating node
 */
void sendBlocks(std::vector<Block> blocks) {
    return;
}

/**
 * Ask other nodes if need to update
 */
bool checkUpToDate() {
    return false;
}

/**
 * Send chain length to asking node
 * @param length chain length
 */
void sendBlockchainLength(int length) {
    return;
}