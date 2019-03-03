#include <iostream>
#include <string>

using namespace std;

struct Transaction {
	string A_name;
	string B_name;
	int aPays;
	int bPays; 
};


void hashMe() {
    
}


Transaction* makeTransaction(int maxValue = 3) {
	//This will create valid transactions in the range of(1, maxValue)
	Transaction* ptr;
	ptr = new Transaction;
    ptr -> A_name = "Alice";
    ptr -> B_name = "Bob";

	int sign = rand() % 1 - 1;
	int amount = rand() % maxValue + 1;
	ptr->aPays = sign * amount;
	ptr->bPays = -1 * ptr->aPays;
	// By construction, this will always return transactions that respect the conservation of tokens.
	// However, note that we have not done anything to check whether these overdraft an account
	return ptr;
 }


void updateState() {
   
}


bool isValidTxn() {
    return true;
}


void makeBlock() {

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

int main() {
    return 0;
}
