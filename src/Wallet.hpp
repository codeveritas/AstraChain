#ifndef ASTRACHAIN_WALLET_HPP
#define ASTRACHAIN_WALLET_HPP

#include "WalletDatabase.hpp"
#include "WalletInterface.hpp"
#include "WalletServer.hpp"

class WalletDatabase;
class WalletInterface;
class WalletServer;

/**
 * User client (wallet)
 */
class Wallet {

private:

    WalletDatabase* walletDatabaseObserver;
    WalletInterface* walletInterfaceObserver;
    WalletServer* walletServerObserver;

public:

    Wallet();

    ~Wallet();

    void registerDatabaseObserver(WalletDatabase* walletDatabase);

    void removeDatabaseObserver();

    void registerInterfaceObserver(WalletInterface* walletInterface);

    void removeInterfaceObserver();

    void registerServerObserver(WalletServer* walletServer);

    void removeServerObserver();

};

#endif //ASTRACHAIN_WALLET_HPP