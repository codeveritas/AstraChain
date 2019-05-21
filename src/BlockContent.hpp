#ifndef ASTRACHAIN_BLOCK_CONTENT_HPP
#define ASTRACHAIN_BLOCK_CONTENT_HPP

#include <string>
#include <vector>

#include "Transaction.hpp"

/**
 * Block content - transactions and additional info
 */
class BlockContent {

// private:
public:
    std::vector<Transaction> transactions;
    uint64_t txnCount;
    uint64_t blockNumber;
    std::string parentHash;

public:

    BlockContent();

    BlockContent(std::vector<Transaction> _transactions, uint64_t _blockNumber, std::string _parentHash);

    ~BlockContent();

};

#endif //ASTRACHAIN_BLOCK_CONTENT_HPP
