#ifndef ASTRACHAIN_NODE_HPP
#define ASTRACHAIN_NODE_HPP

#include "NodeDatabase.hpp"
#include "NodeServer.hpp"
#include "Block.hpp"

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

    /**
     * Write block to node's database
     * @param block block to be added to database
     */
    void addBlockToDatabase(Block block);

    /**
     * Get chain length from node's database
     */
    uint64_t getBlockchainLengthFromDatabase();

    /**
     * Get last block from node
     */
    Block getLastBlockFromDatabase();

    /**
     * Handle new transaction
     * @param transaction new transaction from a wallet
     */
    void handleNewTransaction(Transaction transaction);

    /**
     * Broadcast mined block via server
     * @param block mined block
     */
    void broadcastBlockByServer(Block block);

    /**
     * Handle new block mined by other node
     * @param block new mined block from other nodes
     */
    void handleNewBlock(Block block);

    /**
     * Send last blocks to updating node by server
     * @param blocks last blocks to updating node
     */
    void sendBlocksByServer(std::vector<Block> blocks);

    /**
     * Ask other nodes if need to update by server
     */
    bool checkUpToDateByServer();
    
    /**
     * Send chain length to asking node via server
     */
    void sendBlockchainLengthByServer();

};


#endif //ASTRACHAIN_NODE_HPP