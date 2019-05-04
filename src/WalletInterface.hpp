#ifndef ASTRACHAIN_WALLET_INTERFACE_HPP
#define ASTRACHAIN_WALLET_INTERFACE_HPP

#include "Wallet.hpp"

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

};

#endif //ASTRACHAIN_WALLET_INTERFACE_HPP