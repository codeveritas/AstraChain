#include "NodeDatabase.hpp"
#include "ObserverErrors.hpp"
#include "hiberlite/include/hiberlite.h"
#include <string.h>
#include <vector>


class TransactionsArray{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(sender);
        ar & HIBERLITE_NVP(recipient);
        ar & HIBERLITE_NVP(value);
        ar & HIBERLITE_NVP(status);
        ar & HIBERLITE_NVP(blockNumber);
    }
public:
    int pk_id;
    std::string sender;
    std::string recipient;
    float value;
    int status;
    int blockNumber;
};

HIBERLITE_EXPORT_CLASS(TransactionsArray)

class Nodes{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(blockNumber);
        ar & HIBERLITE_NVP(hash);
        ar & HIBERLITE_NVP(parentHash);
        ar & HIBERLITE_NVP(txnCount);
        // ar & HIBERLITE_NVP(transactions);
    }
public:
    int pk_id;
    uint64_t blockNumber;
    std::string hash;
    std::string parentHash;
    uint64_t txnCount;
    // std::vector<Transact> transactions();

};

HIBERLITE_EXPORT_CLASS(Nodes)

template <class T>
long getTableLength(){
    hiberlite::Database db("db/Node.db");
    std::vector< hiberlite::bean_ptr<T> > v=db.getAllBeans<T>();
//    cout << "found " << v.size() << " records in the table\n";
    return v.size();
}


NodeDatabase::NodeDatabase() {
    nodeObserver = nullptr;
    hiberlite::Database db("db/Node.db");
    db.registerBeanClass<Nodes>();

    db.dropModel();
    db.createModel();
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
    hiberlite::Database db("db/Node.db");
    std::vector< hiberlite::bean_ptr<Nodes> > nodes=db.getAllBeans<Nodes>();
    Nodes x;
    x.pk_id = getTableLength<Nodes>() + 1;
    x.blockNumber = x.pk_id;
    x.hash = block.hash;
    x.parentHash = nodes[getTableLength<Nodes>() - 1]->hash;
    hiberlite::bean_ptr<Nodes> p=db.copyBean(x);

    for (int i = 0; i < block.blockContent.txnCount; i++){
        TransactionsArray y;
        y.pk_id = getTableLength<TransactionsArray>() + 1;
        y.sender = block.blockContent.transactions[i].sender;
        y.recipient = block.blockContent.transactions[i].recipient;
        y.value = block.blockContent.transactions[i].value;
        y.blockNumber = block.blockContent.blockNumber;
        hiberlite::bean_ptr<TransactionsArray> p=db.copyBean(y);
    }
    return;
}

// TODO: normal getBlockchainLength
uint64_t NodeDatabase::getBlockchainLength() {
    if (getTableLength<Nodes>() != 0){
      return getTableLength<Nodes>();
    } else {
      throw BlockchainIsEmpty();
      return 0;
    }
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
