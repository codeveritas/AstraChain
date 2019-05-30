#include <iostream>
#include "src/Node.hpp"
#include "src/NodeDatabase.hpp"
#include "src/NodeServer.hpp"
#include "src/Wallet.hpp"
#include "src/WalletDatabase.hpp"
#include "src/interface/Source/WalletInterface.hpp"
#include "src/WalletServer.hpp"
#include "sqlite3.h"
#include "src/interface/Source/Main.cpp"

int nope() {
    std::cout << "HELLL YEEEAHHHH";
    // Node node;
    // NodeDatabase nodeDatabase;
    // NodeServer nodeServer;
    Wallet wallet;
    // WalletDatabase walletDatabase;
    WalletInterface walletInterface;
    // WalletServer walletServer;
    // node.registerServerObserver(&nodeServer);
    // node.registerDatabaseObserver(&nodeDatabase);
    // node.removeServerObserver();
    // node.removeDatabaseObserver();
    // nodeDatabase.registerNodeObserver(&node);
    // nodeServer.registerNodeObserver(&node);
    // nodeDatabase.removeNodeObserver();
    // nodeServer.removeNodeObserver();

    // wallet.registerDatabaseObserver(&walletDatabase);
    // wallet.registerInterfaceObserver(&walletInterface);
    // wallet.registerServerObserver(&walletServer);
    // wallet.removeDatabaseObserver();
    // wallet.removeInterfaceObserver();
    // wallet.removeServerObserver();
    // walletDatabase.registerWalletObserver(&wallet);
    // walletInterface.registerWalletObserver(&wallet);
    // walletServer.registerWalletObserver(&wallet);
    // walletDatabase.removeWalletObserver();
    // walletInterface.removeWalletObserver();
    // walletServer.removeWalletObserver();
    return 0;
}