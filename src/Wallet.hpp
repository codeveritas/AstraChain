#ifndef ASTRACHAIN_WALLET_HPP
#define ASTRACHAIN_WALLET_HPP

#include <vector>

#include "WalletDatabase.hpp"
#include "interface/Source/WalletInterface.hpp"
#include "WalletServer.hpp"
#include "Transaction.hpp"
#include "TransactionWithStatus.hpp"
#include "Block.hpp"

class WalletDatabase;
class WalletInterface;
class WalletServer;

// class NewProjectApplication;

/**
 * User client (wallet)
 */
class Wallet {

private:

    WalletDatabase* walletDatabaseObserver;
    WalletInterface* walletInterfaceObserver;
    WalletServer* walletServerObserver;

    std::string address;
    float balance;

public:

    Wallet();

    ~Wallet();

    void registerDatabaseObserver(WalletDatabase* walletDatabase);

    void removeDatabaseObserver();

    void registerInterfaceObserver(WalletInterface* walletInterface);

    void removeInterfaceObserver();

    void registerServerObserver(WalletServer* walletServer);

    void removeServerObserver();

    /**
     * Return current balance
     */
    float getBalance();

    /**
     * Return current address
     */
    std::string getAddress();

    /**
     * Return full transaction list
     */
    std::vector<TransactionWithStatus> transactionHistory();

    /**
     * Notify interface that the wallet is updating
     */
    void notifyInterfaceStartUpdating();

    /**
     * Notify interface that the wallet finished updating
     */
    void notifyInterfaceFinishUpdating();

    /**
     * Get new transaction from the interface
     * @param transaction the transaction object to be handled
     */
    void handleNewTransactionFromInterface(Transaction transaction);

    /**
     * Send transaction with status to interface to update it
     * @param transactionWithStatus transaction to be displayed
     */
    void notifyInterfaceTransactionUpdated(TransactionWithStatus transactionWithStatus);

    /**
     * Add new transaction with status to local DB
     * @param transactionWithStatus new transaction with status to be added
     */
    void addTransactionToDatabase(TransactionWithStatus transactionWithStatus);

    /**
     * Get full list of transactions from DB
     */
    std::vector<TransactionWithStatus> getAllTransactionsFromDatabase();

    /**
     * Get full list of transactions by date from DB
     */
    std::vector<TransactionWithStatus> getAllTransactionsByDateFromDatabase(time_t datetime);

    /**
     * Get full list of transactions with status 'pending' from DB
     */
    std::vector<TransactionWithStatus> getAllPendingTransactionsFromDatabase();

    /**
     * Get full list of transactions with status 'done' from DB
     */
    std::vector<TransactionWithStatus> getAllDoneTransactionsFromDatabase();

    /**
     * Send transaction by server
     */
    void sendTransactionByServer(Transaction transaction);

    /**
     * Handle mined blocks obtained by wallet server from node
     */
    void handleMinedBlocks(std::vector<Block> blocks);
    
};

#endif //ASTRACHAIN_WALLET_HPP