#pragma once
#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

struct BlockContent {
    int blockNumber;
    string parentHash;
    int transactionCount;
    vector<Transaction> transactions;
};