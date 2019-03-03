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
    cout << endl;

    return 0;

}
