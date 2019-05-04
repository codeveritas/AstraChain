#include "Wallet.hpp"
#include "ObserverErrors.hpp"

Wallet::Wallet() {
    walletDatabaseObserver = nullptr;
    walletInterfaceObserver = nullptr;
    walletServerObserver = nullptr;
}

Wallet::~Wallet() {}

void Wallet::registerDatabaseObserver(WalletDatabase* walletDatabase) {
    if (!walletDatabaseObserver) {
        walletDatabaseObserver = walletDatabase;
    } else {
        throw ObserverPresent();
    }
}

void Wallet::removeDatabaseObserver() {
    if (walletDatabaseObserver) {
        walletDatabaseObserver = nullptr;
    } else {
        throw NoObserver();
    }
}

void Wallet::registerInterfaceObserver(WalletInterface* walletInterface) {
    if (!walletInterfaceObserver) {
        walletInterfaceObserver = walletInterface;
    } else {
        throw ObserverPresent();
    }
}

void Wallet::removeInterfaceObserver() {
    if (walletInterfaceObserver) {
        walletInterfaceObserver = nullptr;
    } else {
        throw NoObserver();
    }
}

void Wallet::registerServerObserver(WalletServer* walletServer) {
    if (!walletServerObserver) {
        walletServerObserver = walletServer;
    } else {
        throw ObserverPresent();
    }
}

void Wallet::removeServerObserver() {
    if (walletServerObserver) {
        walletServerObserver = nullptr;
    } else {
        throw NoObserver();
    }
}