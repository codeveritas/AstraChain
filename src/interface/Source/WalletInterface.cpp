#include "WalletInterface.hpp"
#include "../../ObserverErrors.hpp"

// #include "../JuceLibraryCode/JuceHeader.h"
// #include "MainComponent.h"

// #include "MainComponent.h"
// #include "../JuceLibraryCode/JuceHeader.h"
#include "Main.cpp"

WalletInterface::WalletInterface() {
    walletObserver = nullptr;
    // juce::JUCEApplicationBase* a = new NewProjectApplication();
    // initialiseJuce_GUI();
    // START_JUCE_APPLICATION (NewProjectApplication);
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

float WalletInterface::getWalletBalance() {
    if (walletObserver) {
        return walletObserver -> getBalance();
    } else {
        throw NoObserver();
    }
}

std::string WalletInterface::getWalletAddress() {
    if (walletObserver) {
        return walletObserver -> getAddress();
    } else {
        throw NoObserver();
    }
}

std::vector<TransactionWithStatus> WalletInterface::getWalletTransactionHistory() {
    if (walletObserver) {
        return walletObserver -> transactionHistory();
    } else {
        throw NoObserver();
    }
}

// TODO: normal startWalletUpdating()
void WalletInterface::startWalletUpdating() {
    return;
}

// TODO: normal finishWalletUpdating()
void WalletInterface::finishWalletUpdating() {
    return;
}

// TODO: normal sendTransactionToWallet()
void WalletInterface::sendTransactionToWallet(Transaction transaction) {
    if (walletObserver) {
        return walletObserver -> handleNewTransactionFromInterface(transaction);
    } else {
        throw NoObserver();
    }
}

// TODO: normal transactionUpdated()
void WalletInterface::transactionUpdated(TransactionWithStatus transactionWithStatus) {
    return;
}