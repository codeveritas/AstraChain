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

float Wallet::getBalance() {
    return balance;
}

std::string Wallet::getAddress() {
    return address;
}

// TODO: normal transactionHistory
std::vector<TransactionWithStatus> Wallet::transactionHistory() {
    std::vector<TransactionWithStatus> result;
    return result;
}

void Wallet::notifyInterfaceStartUpdating() {
    if (walletInterfaceObserver) {
        walletInterfaceObserver -> startWalletUpdating();
    } else {
        throw NoObserver();
    }
}

void Wallet::notifyInterfaceFinishUpdating() {
    if (walletInterfaceObserver) {
        walletInterfaceObserver -> finishWalletUpdating();
    } else {
        throw NoObserver();
    }
}

// TODO: normal handleNewTransactionFromInterface
void Wallet::handleNewTransactionFromInterface(Transaction transaction) {
    return;
}

void Wallet::notifyInterfaceTransactionUpdated(TransactionWithStatus transactionWithStatus) {
    if (walletInterfaceObserver) {
        walletInterfaceObserver -> transactionUpdated(transactionWithStatus);
    } else {
        throw NoObserver();
    }
}

void Wallet::addTransactionToDatabase(TransactionWithStatus transactionWithStatus) {
    if (walletDatabaseObserver) {
        walletDatabaseObserver -> addTransaction(transactionWithStatus);
    } else {
        throw NoObserver();
    }
}

std::vector<TransactionWithStatus> Wallet::getAllTransactionsFromDatabase() {
    if (walletDatabaseObserver) {
        return walletDatabaseObserver -> getAllTransactions();
    } else {
        throw NoObserver();
    }
}

std::vector<TransactionWithStatus> Wallet::getAllTransactionsByDateFromDatabase(time_t datetime) {
    if (walletDatabaseObserver) {
        return walletDatabaseObserver -> getAllTransactionsByDate(datetime);
    } else {
        throw NoObserver();
    }
}

std::vector<TransactionWithStatus> Wallet::getAllPendingTransactionsFromDatabase() {
    if (walletDatabaseObserver) {
        return walletDatabaseObserver -> getAllPendingTransactions();
    } else {
        throw NoObserver();
    }
}

std::vector<TransactionWithStatus> Wallet::getAllDoneTransactionsFromDatabase() {
    if (walletDatabaseObserver) {
        return walletDatabaseObserver -> getAllDoneTransactions();
    } else {
        throw NoObserver();
    }
}

void Wallet::sendTransactionByServer(Transaction transaction) {
    if (walletServerObserver) {
        return walletServerObserver -> sendTransaction(transaction);
    } else {
        throw NoObserver();
    }
}

// TODO: normal handleMinedBlocks
void Wallet::handleMinedBlocks(std::vector<Block> blocks) {
    return;
}