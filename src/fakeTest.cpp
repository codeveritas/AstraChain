#include "chainTools.h"
#include <iostream>

using namespace std;

int main() {
    Transaction* txn = makeTransaction(5);
    cout << txn -> A_name << " " << txn -> aPays << endl;
    return 0;
}
