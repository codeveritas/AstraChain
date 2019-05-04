#ifndef ASTRACHAIN_TRANSACTION_HPP
#define ASTRACHAIN_TRANSACTION_HPP

#include <string>

/**
 * Atomic transaction between two people
 */
class Transaction {

public:

    const std::string sender;
    const std::string recipient;
    const uint64_t value;

    Transaction();

    Transaction(std::string _sender, std::string _recipient, int64_t _value);

    ~Transaction();

};
#endif //ASTRACHAIN_TRANSACTION_HPP