#include <string>
#define MAX_TRANSACTIONS_AMOUNT 5

using namespace std;

struct Transaction {
    string A_name;
    string B_name;
    int aPays;
    int bPays;
};


struct BlockContent {
    int blockNumber;
    string parentHash;
    int transactionCount;
    Transaction transactions[MAX_TRANSACTIONS_AMOUNT];
};

struct Block {
    BlockContent blockContent;
    string blockHash;

    Block* prev;
    Block* next;
};

string hashMe();

Transaction* makeTransaction(int maxValue);

void updateState();

bool isValidTxn();

void makeBlock();

bool checkBlockHash();

bool checkBlockValidity();

bool checkChain();
