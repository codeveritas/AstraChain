#ifndef ASTRACHAIN_WALLET_DATABASE_HPP
#define ASTRACHAIN_WALLET_DATABASE_HPP

#include "Wallet.hpp"
#include "TransactionWithStatus.hpp"

class Wallet;

/**
 * User transactions database for wallet
 */
class WalletDatabase {

private:

    Wallet* walletObserver;

public:

    WalletDatabase();

    ~WalletDatabase();

    void registerWalletObserver(Wallet* wallet);

    void removeWalletObserver();

    /**
     * Add to DB transaction that node gives
     * @param transactionWithStatus
     */
    void addTransaction(TransactionWithStatus transactionWithStatus);

    /**
     * Return full list of transactions
     */
    std::vector<TransactionWithStatus> getAllTransactions();

    /**
     * Return full list of transactions by date
     */
    std::vector<TransactionWithStatus> getAllTransactionsByDate(time_t datetime);

    /**
     * Return full list of transactions with status 'pending'
     */
    std::vector<TransactionWithStatus> getAllPendingTransactions();

    /**
     * Return full list of transactions with status 'done'
     */
    std::vector<TransactionWithStatus> getAllDoneTransactions();

};

#endif //ASTRACHAIN_WALLET_DATABASE_HPP