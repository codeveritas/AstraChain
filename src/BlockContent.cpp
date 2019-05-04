#include "BlockContent.hpp"
#include "ObserverErrors.hpp"

BlockContent::BlockContent() {}

BlockContent::BlockContent(std::vector<Transaction> _transactions, uint64_t _blockNumber, std::string _parentHash) : transactions(_transactions), txnCount(_transactions.size()), blockNumber(_blockNumber), parentHash(_parentHash) {
    if (txnCount == 0) {
        throw EmptyTransactionList();
    }
}

BlockContent::~BlockContent() {}