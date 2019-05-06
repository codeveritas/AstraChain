#ifndef ASTRACHAIN_WALLET_SERVER_HPP
#define ASTRACHAIN_WALLET_SERVER_HPP

#include "Wallet.hpp"
#include "Block.hpp"

class Wallet;

/**
 * Network interactions for the wallet
 */
class WalletServer {

private:

    Wallet* walletObserver;

public:

    WalletServer();

    ~WalletServer();

    void registerWalletObserver(Wallet* wallet);

    void removeWalletObserver();

    /**
     * Send transaction to nodes
     */
    void sendTransaction(Transaction transaction);

    /**
     * Give mined blocks to wallet obtained from node
     */
    void giveBlocksToNode(std::vector<Block> blocks);

};

#endif //ASTRACHAIN_WALLET_SERVER_HPP