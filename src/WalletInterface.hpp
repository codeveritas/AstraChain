#ifndef ASTRACHAIN_WALLET_INTERFACE_HPP
#define ASTRACHAIN_WALLET_INTERFACE_HPP

#include "Wallet.hpp"
#include "Transaction.hpp"
#include "TransactionWithStatus.hpp"

class Wallet;

/**
 * GUI interface methods for the wallet
 */
class WalletInterface {

private:

    Wallet* walletObserver;

public:

    WalletInterface();

    ~WalletInterface();

    void registerWalletObserver(Wallet* wallet);

    void removeWalletObserver();

    /**
     * Get current balance from wallet
     */
    float getWalletBalance();

    /**
     * Get current address from wallet
     */
    std::string getWalletAddress();

    /**
     * Get full transactions list from the wallet
     */
    std::vector<TransactionWithStatus> getWalletTransactionHistory();

    /**
     * Receives a 'start updating' event from the wallet
     */
    void startWalletUpdating();

    /**
     * Receives a 'finish updating' event from the wallet
     */
    void finishWalletUpdating();

    /**
     * Send new transaction to the wallet
     * @param transaction the transaction object to be handled
     */
    void sendTransactionToWallet(Transaction transaction);

    /**
     * Update interface according to the new transaction data from the wallet
     * @param transactionWithStatus transaction to be displayed
     */
    void transactionUpdated(TransactionWithStatus transactionWithStatus);
    
};

#endif //ASTRACHAIN_WALLET_INTERFACE_HPP