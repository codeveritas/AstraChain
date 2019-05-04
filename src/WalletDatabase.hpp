#ifndef ASTRACHAIN_WALLET_DATABASE_HPP
#define ASTRACHAIN_WALLET_DATABASE_HPP

#include "Wallet.hpp"

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

};

#endif //ASTRACHAIN_WALLET_DATABASE_HPP