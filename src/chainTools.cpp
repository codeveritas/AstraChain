#include "chainTools.h"
#include "BlockContent.h"
#include <string>
#include <vector>

using namespace std;

string hashMe(BlockContent blockContent) {
    return "deadbeef";
}


Transaction* makeTransaction(int maxValue) {
	//This will create valid transactions in the range of(1, maxValue)
	Transaction* ptr;
	ptr = new Transaction;
	ptr -> A_name = A_name;
    ptr -> B_name = B_name;
	
	int sign;
	(rand() % 2 == 0) ? sign = -1 : sign = 1;
	int amount = rand() % maxValue + 1;
	ptr->aPays = sign * amount;
	ptr->bPays = -1 * ptr->aPays;
	// By construction, this will always return transactions that respect the conservation of tokens.
	// However, note that we have not done anything to check whether these overdraft an account
	return ptr;
 }


void updateState(Transaction* transaction, vector<StateRecord> &state) {
    bool foundA = false;
    bool foundB = false;
    for(vector<StateRecord>::iterator it = state.begin(); it != state.end(); ++it) {
        if(transaction -> A_name == it -> name) {
            foundA = true;
            it -> value += transaction -> aPays;
        }
        if(transaction -> B_name == it -> name) {
            foundB = true;
            it -> value += transaction -> bPays;
        }
    }

    if(!foundA) {
        StateRecord st;
        st.name = transaction -> A_name;
        st.value = transaction -> aPays;
        state.push_back(st);
    }
    if(!foundB) {
        StateRecord st;
        st.name = transaction -> B_name;
        st.value = transaction -> bPays;
        state.push_back(st);
    }
}


bool isValidTxn() {
    return true;
}


Block makeBlock(vector<Transaction> transactions, vector<Block> chain) {
    Block parentBlock = chain.back();
    string parentHash = parentBlock.blockHash;
    int blockNumber = parentBlock.blockContent.blockNumber + 1;
    int transactionCounts = transactions.size();

    BlockContent blockContent;
    blockContent.blockNumber = blockNumber;
    blockContent.parentHash = parentHash;
    blockContent.transactionCount = transactionCounts;
    blockContent.transactions = transactions;

    string blockHash = hashMe(blockContent);

    Block block;
    block.blockHash = blockHash;
    block.blockContent = blockContent;

    return block;
}


bool checkBlockHash() {
    return true;
}


bool checkBlockValidity() {
    return true;
}


bool checkChain() {
    return true;
}
