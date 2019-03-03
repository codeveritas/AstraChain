#include "chainTools.h"
#include <iostream>

using namespace std;

int main() {
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

    return 0;
}
