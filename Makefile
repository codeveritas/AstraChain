CC=g++

CFLAGS=-c -std=c++11

GTEST_DIR=/Users/bogdansalyp/googletest/googletest

all: chain.out
	
chain.out: main.o Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o
	$(CC) main.o Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o -o chain.out

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Node.o: src/Node.cpp
	$(CC) $(CFLAGS) src/Node.cpp

NodeDatabase.o: src/NodeDatabase.cpp
	$(CC) $(CFLAGS) src/NodeDatabase.cpp

NodeServer.o: src/NodeServer.cpp
	$(CC) $(CFLAGS) src/NodeServer.cpp

Wallet.o: src/Wallet.cpp
	$(CC) $(CFLAGS) src/Wallet.cpp

WalletDatabase.o: src/WalletDatabase.cpp
	$(CC) $(CFLAGS) src/WalletDatabase.cpp

WalletInterface.o: src/WalletInterface.cpp
	$(CC) $(CFLAGS) src/WalletInterface.cpp

WalletServer.o: src/WalletServer.cpp
	$(CC) $(CFLAGS) src/WalletServer.cpp

gtest: Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o
	$(CC) -pthread -stdlib=libc++ -std=c++11 test/test.cpp -I$(GTEST_DIR)/include -lgtest -lgtest_main -L$(GTEST_DIR) Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o -o test.out
	./test.out

clean:
	rm -rf *.o *.out