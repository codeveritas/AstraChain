#include "TransactionWithStatus.hpp"

TransactionWithStatus::TransactionWithStatus() {}

TransactionWithStatus::TransactionWithStatus(Transaction _transaction, bool _status, time_t _time) : transaction(_transaction), status(_status), time(_time) {}

TransactionWithStatus::~TransactionWithStatus() {}