#include "WalletDatabase.hpp"
#include "ObserverErrors.hpp"

WalletDatabase::WalletDatabase() {
    walletObserver = nullptr;
}

WalletDatabase::~WalletDatabase() {}

void WalletDatabase::registerWalletObserver(Wallet* wallet) {
    if (!walletObserver) {
        walletObserver = wallet;
    } else {
        throw ObserverPresent();
    }
}

void WalletDatabase::removeWalletObserver() {
    if (walletObserver) {
        walletObserver = nullptr;
    } else {
        throw NoObserver();
    }
}

// TODO: normal addTransaction()
void WalletDatabase::addTransaction(TransactionWithStatus transactionWithStatus) {
    return;
}

// TODO: normal getAllTransactions()
std::vector<TransactionWithStatus> WalletDatabase::getAllTransactions() {
    std::vector<TransactionWithStatus> transactions;
    return transactions;
}

// TODO: normal getAllTransactionsByDate()
std::vector<TransactionWithStatus> WalletDatabase::getAllTransactionsByDate(time_t datetime) {
    std::vector<TransactionWithStatus> transactions;
    return transactions;
}

// TODO: normal getAllPendingTransactions()
std::vector<TransactionWithStatus> WalletDatabase::getAllPendingTransactions() {
    std::vector<TransactionWithStatus> transactions;
    return transactions;
}

// TODO: normal getAllDoneTransactions()
std::vector<TransactionWithStatus> WalletDatabase::getAllDoneTransactions() {
    std::vector<TransactionWithStatus> transactions;
    return transactions;
}