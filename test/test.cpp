#include "gtest/gtest.h"

#include "../src/Node.hpp"
#include "../src/NodeDatabase.hpp"
#include "../src/NodeServer.hpp"
#include "../src/Wallet.hpp"
#include "../src/WalletDatabase.hpp"
#include "../src/WalletInterface.hpp"
#include "../src/WalletServer.hpp"
#include "../src/ObserverErrors.hpp"

//------------------------ Node DatabaseObserver tests ------------------------

TEST(NodeDatabaseObserver, FirstAdd) {
    Node node;
    NodeDatabase nodeDatabase;
    EXPECT_NO_THROW(node.registerDatabaseObserver(&nodeDatabase));
}

TEST(NodeDatabaseObserver, SecondAdd) {
    Node node;
    NodeDatabase nodeDatabase;
    node.registerDatabaseObserver(&nodeDatabase);
    EXPECT_THROW(node.registerDatabaseObserver(&nodeDatabase), ObserverPresent);
}

TEST(NodeDatabaseObserver, FirstRemove) {
    Node node;
    NodeDatabase nodeDatabase;
    node.registerDatabaseObserver(&nodeDatabase);
    EXPECT_NO_THROW(node.removeDatabaseObserver());
}

TEST(NodeDatabaseObserver, SecondRemove) {
    Node node;
    NodeDatabase nodeDatabase;
    node.registerDatabaseObserver(&nodeDatabase);
    node.removeDatabaseObserver();
    EXPECT_THROW(node.removeDatabaseObserver(), NoObserver);
}

//------------------------ Node ServerObserver tests ------------------------

TEST(NodeServerObserver, FirstAdd) {
    Node node;
    NodeServer nodeServer;
    EXPECT_NO_THROW(node.registerServerObserver(&nodeServer));
}

TEST(NodeServerObserver, SecondAdd) {
    Node node;
    NodeServer nodeServer;
    node.registerServerObserver(&nodeServer);
    EXPECT_THROW(node.registerServerObserver(&nodeServer), ObserverPresent);
}

TEST(NodeServerObserver, FirstRemove) {
    Node node;
    NodeServer nodeServer;
    node.registerServerObserver(&nodeServer);
    EXPECT_NO_THROW(node.removeServerObserver());
}

TEST(NodeServerObserver, SecondRemove) {
    Node node;
    NodeServer nodeServer;
    node.registerServerObserver(&nodeServer);
    node.removeServerObserver();
    EXPECT_THROW(node.removeServerObserver(), NoObserver);
}

//------------------------ Wallet DatabaseObserver tests ------------------------

TEST(WalletDatabaseObserver, FirstAdd) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    EXPECT_NO_THROW(wallet.registerDatabaseObserver(&walletDatabase));
}

TEST(WalletDatabaseObserver, SecondAdd) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    wallet.registerDatabaseObserver(&walletDatabase);
    EXPECT_THROW(wallet.registerDatabaseObserver(&walletDatabase), ObserverPresent);
}

TEST(WalletDatabaseObserver, FirstRemove) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    wallet.registerDatabaseObserver(&walletDatabase);
    EXPECT_NO_THROW(wallet.removeDatabaseObserver());
}

TEST(WalletDatabaseObserver, SecondRemove) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    wallet.registerDatabaseObserver(&walletDatabase);
    wallet.removeDatabaseObserver();
    EXPECT_THROW(wallet.removeDatabaseObserver(), NoObserver);
}

//------------------------ Wallet InterfaceObserver tests ------------------------

TEST(WalletInterfaceObserver, FirstAdd) {
    Wallet wallet;
    WalletInterface walletInterface;
    EXPECT_NO_THROW(wallet.registerInterfaceObserver(&walletInterface));
}

TEST(WalletInterfaceObserver, SecondAdd) {
    Wallet wallet;
    WalletInterface walletInterface;
    wallet.registerInterfaceObserver(&walletInterface);
    EXPECT_THROW(wallet.registerInterfaceObserver(&walletInterface), ObserverPresent);
}

TEST(WalletInterfaceObserver, FirstRemove) {
    Wallet wallet;
    WalletInterface walletInterface;
    wallet.registerInterfaceObserver(&walletInterface);
    EXPECT_NO_THROW(wallet.removeInterfaceObserver());
}

TEST(WalletInterfaceObserver, SecondRemove) {
    Wallet wallet;
    WalletInterface walletInterface;
    wallet.registerInterfaceObserver(&walletInterface);
    wallet.removeInterfaceObserver();
    EXPECT_THROW(wallet.removeInterfaceObserver(), NoObserver);
}

//------------------------ Wallet ServerObserver tests ------------------------

TEST(WalletServerObserver, FirstAdd) {
    Wallet wallet;
    WalletServer walletServer;
    EXPECT_NO_THROW(wallet.registerServerObserver(&walletServer));
}

TEST(WalletServerObserver, SecondAdd) {
    Wallet wallet;
    WalletServer walletServer;
    wallet.registerServerObserver(&walletServer);
    EXPECT_THROW(wallet.registerServerObserver(&walletServer), ObserverPresent);
}

TEST(WalletServerObserver, FirstRemove) {
    Wallet wallet;
    WalletServer walletServer;
    wallet.registerServerObserver(&walletServer);
    EXPECT_NO_THROW(wallet.removeServerObserver());
}

TEST(WalletServerObserver, SecondRemove) {
    Wallet wallet;
    WalletServer walletServer;
    wallet.registerServerObserver(&walletServer);
    wallet.removeServerObserver();
    EXPECT_THROW(wallet.removeServerObserver(), NoObserver);
}

//------------------------ NodeDatabase NodeObserver tests ------------------------

TEST(NodeDatabaseNodeObserver, FirstAdd) {
    Node node;
    NodeDatabase nodeDatabase;
    EXPECT_NO_THROW(nodeDatabase.registerNodeObserver(&node));
}

TEST(NodeDatabaseNodeObserver, SecondAdd) {
    Node node;
    NodeDatabase nodeDatabase;
    nodeDatabase.registerNodeObserver(&node);
    EXPECT_THROW(nodeDatabase.registerNodeObserver(&node), ObserverPresent);
}

TEST(NodeDatabaseNodeObserver, FirstRemove) {
    Node node;
    NodeDatabase nodeDatabase;
    nodeDatabase.registerNodeObserver(&node);
    EXPECT_NO_THROW(nodeDatabase.removeNodeObserver());
}

TEST(NodeDatabaseNodeObserver, SecondRemove) {
    Node node;
    NodeDatabase nodeDatabase;
    nodeDatabase.registerNodeObserver(&node);
    nodeDatabase.removeNodeObserver();
    EXPECT_THROW(nodeDatabase.removeNodeObserver(), NoObserver);
}

//------------------------ NodeServer NodeObserver tests ------------------------

TEST(NodeServerNodeObserver, FirstAdd) {
    Node node;
    NodeServer nodeServer;
    EXPECT_NO_THROW(nodeServer.registerNodeObserver(&node));
}

TEST(NodeServerNodeObserver, SecondAdd) {
    Node node;
    NodeServer nodeServer;
    nodeServer.registerNodeObserver(&node);
    EXPECT_THROW(nodeServer.registerNodeObserver(&node), ObserverPresent);
}

TEST(NodeServerNodeObserver, FirstRemove) {
    Node node;
    NodeServer nodeServer;
    nodeServer.registerNodeObserver(&node);
    EXPECT_NO_THROW(nodeServer.removeNodeObserver());
}

TEST(NodeServerNodeObserver, SecondRemove) {
    Node node;
    NodeServer nodeServer;
    nodeServer.registerNodeObserver(&node);
    nodeServer.removeNodeObserver();
    EXPECT_THROW(nodeServer.removeNodeObserver(), NoObserver);
}

//------------------------ WalletDatabase NodeObserver tests ------------------------

TEST(WalletDatabaseNodeObserver, FirstAdd) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    EXPECT_NO_THROW(walletDatabase.registerWalletObserver(&wallet));
}

TEST(WalletDatabaseNodeObserver, SecondAdd) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    walletDatabase.registerWalletObserver(&wallet);
    EXPECT_THROW(walletDatabase.registerWalletObserver(&wallet), ObserverPresent);
}

TEST(WalletDatabaseNodeObserver, FirstRemove) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    walletDatabase.registerWalletObserver(&wallet);
    EXPECT_NO_THROW(walletDatabase.removeWalletObserver());
}

TEST(WalletDatabaseNodeObserver, SecondRemove) {
    Wallet wallet;
    WalletDatabase walletDatabase;
    walletDatabase.registerWalletObserver(&wallet);
    walletDatabase.removeWalletObserver();
    EXPECT_THROW(walletDatabase.removeWalletObserver(), NoObserver);
}

//------------------------ WalletInterface NodeObserver tests ------------------------

TEST(WalletInterfaceNodeObserver, FirstAdd) {
    Wallet wallet;
    WalletInterface walletInterface;
    EXPECT_NO_THROW(walletInterface.registerWalletObserver(&wallet));
}

TEST(WalletInterfaceNodeObserver, SecondAdd) {
    Wallet wallet;
    WalletInterface walletInterface;
    walletInterface.registerWalletObserver(&wallet);
    EXPECT_THROW(walletInterface.registerWalletObserver(&wallet), ObserverPresent);
}

TEST(WalletInterfaceNodeObserver, FirstRemove) {
    Wallet wallet;
    WalletInterface walletInterface;
    walletInterface.registerWalletObserver(&wallet);
    EXPECT_NO_THROW(walletInterface.removeWalletObserver());
}

TEST(WalletInterfaceNodeObserver, SecondRemove) {
    Wallet wallet;
    WalletInterface walletInterface;
    walletInterface.registerWalletObserver(&wallet);
    walletInterface.removeWalletObserver();
    EXPECT_THROW(walletInterface.removeWalletObserver(), NoObserver);
}

//------------------------ WalletServer NodeObserver tests ------------------------

TEST(WalletServerNodeObserver, FirstAdd) {
    Wallet wallet;
    WalletServer walletServer;
    EXPECT_NO_THROW(walletServer.registerWalletObserver(&wallet));
}

TEST(WalletServerNodeObserver, SecondAdd) {
    Wallet wallet;
    WalletServer walletServer;
    walletServer.registerWalletObserver(&wallet);
    EXPECT_THROW(walletServer.registerWalletObserver(&wallet), ObserverPresent);
}

TEST(WalletServerNodeObserver, FirstRemove) {
    Wallet wallet;
    WalletServer walletServer;
    walletServer.registerWalletObserver(&wallet);
    EXPECT_NO_THROW(walletServer.removeWalletObserver());
}

TEST(WalletServerNodeObserver, SecondRemove) {
    Wallet wallet;
    WalletServer walletServer;
    walletServer.registerWalletObserver(&wallet);
    walletServer.removeWalletObserver();
    EXPECT_THROW(walletServer.removeWalletObserver(), NoObserver);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}