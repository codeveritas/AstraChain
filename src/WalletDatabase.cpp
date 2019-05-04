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