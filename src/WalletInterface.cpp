#include "WalletInterface.hpp"
#include "ObserverErrors.hpp"

WalletInterface::WalletInterface() {
    walletObserver = nullptr;
}

WalletInterface::~WalletInterface() {}

void WalletInterface::registerWalletObserver(Wallet* wallet) {
    if (!walletObserver) {
        walletObserver = wallet;
    } else {
        throw ObserverPresent();
    }
}

void WalletInterface::removeWalletObserver() {
    if (walletObserver) {
        walletObserver = nullptr;
    } else {
        throw NoObserver();
    }
}