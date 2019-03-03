#pragma once
#include <string>
#include <vector>
#include <Block.h>
#include "Transaction.h"
#include "BlockContent.h"
#include "Block.h"
#include "StateRecord.h"

using namespace std;


string hashMe(BlockContent blockContent);

Transaction* makeTransaction(int maxValue);

void updateState(Transaction* transaction, vector<StateRecord> &state);

bool isValidTxn();

Block makeBlock(vector<Transaction> transactions, vector<Block> chain);

bool checkBlockHash();

bool checkBlockValidity();

bool checkChain();
