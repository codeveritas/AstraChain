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

void Node::addBlockToDatabase(Block block) {
    if (nodeDatabaseObserver) {
        nodeDatabaseObserver -> addBlock(block);
    } else {
        throw NoObserver();
    }
}

uint64_t Node::getBlockchainLengthFromDatabase() {
    if (nodeDatabaseObserver) {
        return nodeDatabaseObserver -> getBlockchainLength();
    } else {
        throw NoObserver();
    }
}

Block Node::getLastBlockFromDatabase() {
    if (nodeDatabaseObserver) {
        return nodeDatabaseObserver -> getLastBlock();
    } else {
        throw NoObserver();
    }
}

// TODO: normal handleNewTransaction
void Node::handleNewTransaction(Transaction transaction) {
    return;
}

void Node::broadcastBlockByServer(Block block) {
    if (nodeServerObserver) {
        nodeServerObserver -> broadcastBlock(block);
    } else {
        throw NoObserver();
    }
}

// TODO: normal handleNewBlock
void Node::handleNewBlock(Block block) {
    return;
}

void Node::sendBlocksByServer(std::vector<Block> blocks) {
    if (nodeServerObserver) {
        nodeServerObserver -> sendBlocks(blocks);
    } else {
        throw NoObserver();
    }
}

bool Node::checkUpToDateByServer() {
    if (nodeServerObserver) {
        return nodeServerObserver -> checkUpToDate();
    } else {
        throw NoObserver();
    }
}

// TODO: normal sendBlockchainLengthByServer
void Node::sendBlockchainLengthByServer() {
    if (nodeServerObserver) {
        nodeServerObserver -> sendBlockchainLength(0);
    } else {
        throw NoObserver();
    }
}
