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
    db.registerBeanClass<TransactionsArray>();
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
    if (getTableLength<Nodes>() == 0){
        x.parentHash = "GenesisBlockWithoutParentHash";
    } else {
        x.parentHash = nodes[getTableLength<Nodes>() - 2]->hash;
    }
    hiberlite::bean_ptr<Nodes> p=db.copyBean(x);

    for (int i = 0; i < block.blockContent.transactions.size(); i++){
        TransactionsArray y;
        y.pk_id = getTableLength<TransactionsArray>() + 1;
        y.sender = block.blockContent.transactions[i].sender;
        y.recipient = block.blockContent.transactions[i].recipient;
        y.value = block.blockContent.transactions[i].value;
        y.blockNumber = block.blockContent.blockNumber;
        hiberlite::bean_ptr<TransactionsArray> p=db.copyBean(y);
    }

    //TEST of BlockAdding
    int count = 0;
    std::vector< hiberlite::bean_ptr<TransactionsArray> > transactions=db.getAllBeans<TransactionsArray>();
    for (int i=0; i < getTableLength<TransactionsArray>(); i++){
        if (transactions[i]->blockNumber == block.blockContent.blockNumber){
            count++;
        }
    }
    std::cout << count << "  " << block.blockContent.transactions.size() << std::endl;
    if (count == block.blockContent.transactions.size()){
        return;
    } else {
        throw BlockDidnotAdded();
        return;
    }
    //TEST of BlockAdding
}


uint64_t NodeDatabase::getBlockchainLength() {
    if (getTableLength<Nodes>() != 0){
      return getTableLength<Nodes>();
    } else {
      throw BlockchainIsEmpty();
      return 0;
    }
}


Block NodeDatabase::getLastBlock() {
      hiberlite::Database db("db/Node.db");
      std::vector<Transaction> transactions;
      int LastBlockNumber = getTableLength<Nodes>();
      std::vector< hiberlite::bean_ptr<TransactionsArray> > DBtransactions=db.getAllBeans<TransactionsArray>();

      for (int i = 0; i < getTableLength<TransactionsArray>(); i++){
          if (DBtransactions[i]->blockNumber == LastBlockNumber){
              Transaction x(DBtransactions[i]->sender,
                            DBtransactions[i]->recipient,
                            DBtransactions[i]->value);
              transactions.push_back(x);
          }
      }

      std::vector< hiberlite::bean_ptr<Nodes> > nodes=db.getAllBeans<Nodes>();
      Block block(BlockContent(transactions, nodes[LastBlockNumber-1]->blockNumber, nodes[LastBlockNumber-1]->parentHash), nodes[LastBlockNumber-1]->hash);
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
