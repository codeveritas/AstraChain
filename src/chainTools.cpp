#include <iostream>

using namespace std;

struct MakeTransaction
{	
	char A_name[6]="Alice";
	char B_name[4]="Bob";
	int alicePays;
	int bobPays; 
};


void hashMe() {
    
}


MakeTransaction* makeTransaction(int maxValue = 3) {
	//This will create valid transactions in the range of(1, maxValue)
	MakeTransaction* ptr;
	ptr = new MakeTransaction;
	int sign = rand() % 1 - 1;
	int amount = rand() % maxValue + 1;
	ptr->alicePays = sign * amount;
	ptr->bobPays = -1 * ptr->alicePays;
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
