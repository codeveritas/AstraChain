#include "chainTools.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    cout << endl;
    cout << "Testing transaction creation..." << endl << endl;

    for(int i = 0; i < 10; i++) {
        Transaction* txn = makeTransaction(5);
        cout << "Transaction #" << i + 1 << ": "
            << txn -> A_name << " ("
            << txn -> aPays << ") - "
            << txn -> B_name << " ("
            << txn -> bPays << ")" << endl;
    }
    cout << endl << endl;

    
    cout << "Testing state update..." << endl << endl;

    StateRecord stateRecordA;
    stateRecordA.name = "Alice";
    stateRecordA.value = 10;

    StateRecord stateRecordB;
    stateRecordB.name = "Bob";
    stateRecordB.value = 7;

    vector<StateRecord> state;
    state.push_back(stateRecordA);
    state.push_back(stateRecordB);

    cout << "Initial state:" << endl;
    for(vector<StateRecord>::iterator it = state.begin(); it != state.end(); ++it) {
        cout << it -> name << " -> " << it -> value << endl;
    }
    cout << endl;


    Transaction* txn = makeTransaction(5);
    cout << "Transaction: "
        << txn -> A_name << " ("
        << txn -> aPays << ") - "
        << txn -> B_name << " ("
        << txn -> bPays << ")" << endl;

    cout << "Applying transaction..." << endl << endl;
    updateState(txn, state);

    cout << "Resulting state:" << endl;
    for(vector<StateRecord>::iterator it = state.begin(); it != state.end(); ++it) {
        cout << it -> name << " -> " << it -> value << endl;
    }
    cout << endl << endl;


    cout << "Chain testing..." << endl;

    stateRecordA.name = "Alice";
    stateRecordA.value = 0;
    stateRecordB.name = "Bob";
    stateRecordB.value = 0;

    state.clear();
    state.push_back(stateRecordA);
    state.push_back(stateRecordB);


    Transaction initialTransaction;
    initialTransaction.A_name = "Alice";
    initialTransaction.aPays = 50;
    initialTransaction.B_name = "Bob";
    initialTransaction.bPays = 50;
    vector<Transaction> initialTransactions;
    initialTransactions.push_back(initialTransaction);

    BlockContent genesisBlockContent;
    genesisBlockContent.blockNumber = 0;
    genesisBlockContent.parentHash = "";
    genesisBlockContent.transactionCount = 1;
    genesisBlockContent.transactions = initialTransactions;
    
    string genesisHash = hashMe(genesisBlockContent);
    Block genesisBlock;
    genesisBlock.blockContent = genesisBlockContent;
    genesisBlock.blockHash = genesisHash;

    vector<Block> chain;
    chain.push_back(genesisBlock);

    updateState(&initialTransaction, state);

    cout << "State after genesis:" << endl;
    for(vector<StateRecord>::iterator it = state.begin(); it != state.end(); ++it) {
        cout << it -> name << " -> " << it -> value << endl;
    }
    cout << endl;

    vector<Transaction> transactionList;
    for(int i = 0; i < 5; i++) {
        Transaction* txn = makeTransaction(5);
        transactionList.push_back(*txn);
        cout << "Transaction #" << i + 1 << ": " 
            << txn -> A_name << " ("
            << txn -> aPays << ") - "
            << txn -> B_name << " ("
            << txn -> bPays << ")" << endl;

        cout << "Old state: ";
        for(vector<StateRecord>::iterator it = state.begin(); it != state.end(); ++it) {
            cout << it -> name << " -> " << it -> value << " ";
        }
        cout << endl;

        updateState(txn, state);

        cout << "New state: ";
        for(vector<StateRecord>::iterator it = state.begin(); it != state.end(); ++it) {
            cout << it -> name << " -> " << it -> value << " "; 
        }
        cout << endl;
    }
    chain.push_back(makeBlock(transactionList, chain));

    return 0;

}
