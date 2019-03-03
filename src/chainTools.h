#include <string>
#include <vector>
#define MAX_TRANSACTIONS_AMOUNT 5

using namespace std;

struct Transaction {
    string A_name;
    string B_name;
    int aPays;
    int bPays;
};


struct StateRecord {
    string name;
    int value;
};


struct BlockContent {
    int blockNumber;
    string parentHash;
    int transactionCount;
    vector<Transaction> transactions;
};

struct Block {
    BlockContent blockContent;
    string blockHash;
};

string hashMe(BlockContent blockContent);

Transaction* makeTransaction(int maxValue);

void updateState(Transaction* transaction, vector<StateRecord> &state);

bool isValidTxn();

Block makeBlock(vector<Transaction> transactions, vector<Block> chain);

bool checkBlockHash();

bool checkBlockValidity();

bool checkChain();
