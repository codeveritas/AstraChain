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

// TODO: normal addBlock
void NodeDatabase::addBlock(Block block) {
    return;
}

// TODO: normal getBlockchainLength
uint64_t NodeDatabase::getBlockchainLength() {
    return 0;
}

// TODO: normal getLastBlock
Block NodeDatabase::getLastBlock() {
    Block block;
    return block;
}

void NodeServer::getNewTransactionToNode(Transaction transaction) {
    if (nodeObserver) {
        nodeObserver -> handleNewTransaction(transaction);
    } else {
        throw NoObserver();
    }
}

// TODO: normal broadcastBlock
void NodeServer::broadcastBlock(Block block) {
    return;
}

void NodeServer::getNewBlockToNode(Block block) {
    if (nodeObserver) {
        nodeObserver -> handleNewBlock(block);
    } else {
        throw NoObserver();
    }
}

// TODO: normal sendBlocks
void NodeServer::sendBlocks(std::vector<Block> blocks) {
    return;
}

// TODO: normal checkUpToDate
bool NodeServer::checkUpToDate() {
    return false;
}

// TODO: normal sendBlockchainLength
void NodeServer::sendBlockchainLength(int length) {
    return;
}