#ifndef ASTRACHAIN_TRANSACTION_WITH_STATUS_HPP
#define ASTRACHAIN_TRANSACTION_WITH_STATUS_HPP

#include "Transaction.hpp"

/**
 * Transaction, status (pending/done) and date
 */
class TransactionWithStatus {

public:

    Transaction transaction;
    bool status;
    time_t time;

    TransactionWithStatus();
    
    TransactionWithStatus(Transaction _transaction, bool _status, time_t _time);

    ~TransactionWithStatus();

};

#endif //ASTRACHAIN_TRANSACTION_WITH_STATUS_HPP