#include "Transaction.hpp"
#include "ObserverErrors.hpp"

Transaction::Transaction() : sender(""), recipient(""), value(0) {}

Transaction::Transaction(std::string _sender, std::string _recipient, int64_t _value) : sender(_sender), recipient(_recipient), value(_value) {
    if (_value < 0) {
        throw NegativeValueTransaction();
    }
    if (_sender.compare(_recipient) == 0) {
        throw SameAddressTransaction();
    }
}

Transaction::~Transaction() {}