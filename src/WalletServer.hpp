#ifndef ASTRACHAIN_WALLET_SERVER_HPP
#define ASTRACHAIN_WALLET_SERVER_HPP

#include "Wallet.hpp"

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

};

#endif //ASTRACHAIN_WALLET_SERVER_HPP