#include "WalletServer.hpp"
#include "ObserverErrors.hpp"

WalletServer::WalletServer() {
    walletObserver = nullptr;
}

WalletServer::~WalletServer() {}

void WalletServer::registerWalletObserver(Wallet* wallet) {
    if (!walletObserver) {
        walletObserver = wallet;
    } else {
        throw ObserverPresent();
    }
}

void WalletServer::removeWalletObserver() {
    if (walletObserver) {
        walletObserver = nullptr;
    } else {
        throw NoObserver();
    }
}

// TODO: normal sendTransaction
void WalletServer::sendTransaction(Transaction transaction) {
    return;
}

void WalletServer::giveBlocksToNode(std::vector<Block> blocks) {
    if (walletObserver) {
        walletObserver -> handleMinedBlocks(blocks);
    } else {
        throw NoObserver();
    }
}