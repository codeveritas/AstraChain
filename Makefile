CC=$(CXX)

CFLAGS=-c -std=c++14

all: chain.out
	
chain.out: main.o Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o
	$(CC) main.o Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o -lsqlite3 -lhiberlite -Isrc/hiberlite/include -Lsrc/hiberlite/build -o chain.out -pthread -ldl

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

Transaction.o: src/Transaction.cpp
	$(CC) $(CFLAGS) src/Transaction.cpp

TransactionWithStatus.o: src/TransactionWithStatus.cpp
	$(CC) $(CFLAGS) src/TransactionWithStatus.cpp

BlockContent.o: src/BlockContent.cpp
	$(CC) $(CFLAGS) src/BlockContent.cpp

Block.o: src/Block.cpp
	$(CC) $(CFLAGS) src/Block.cpp

gtest: Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o
	$(CC) -pthread -std=c++14 test/test.cpp -lgtest -lgtest_main Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o -o test.out -lsqlite3 -lhiberlite -I/Users/bogdansalyp/projects/AstraChain/src/hiberlite/include -L/Users/bogdansalyp/projects/AstraChain/src/hiberlite/build -pthread -ldl
	./test.out

clean:
	rm -rf *.o *.out