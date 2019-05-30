CC=g++

CFLAGS=-c -std=c++17

INTERFACE=src/interface/Builds/CLion/build/CMakeFiles/APP.dir/Users/bogdansalyp/projects/AstraChain/src/interface

all: chain.out
	
chain.out: utils.o Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o
	# $(CC) main.o Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o -lsqlite3 -lhiberlite -Isrc/hiberlite/include -Lsrc/hiberlite/build -o chain.out -pthread -ldl
	$(CC) utils.o Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o -lsqlite3 -lhiberlite -Isrc/hiberlite/include -Lsrc/hiberlite/build -o chain.out -pthread -ldl $(INTERFACE)/Source/MainComponent.cpp.o $(INTERFACE)/Source/Main.cpp.o $(INTERFACE)/JuceLibraryCode/include_juce_audio_basics.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_audio_devices.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_audio_formats.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_audio_processors.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_core.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_cryptography.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_data_structures.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_events.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_graphics.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_gui_basics.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_gui_extra.mm.o $(INTERFACE)/JuceLibraryCode/include_juce_opengl.mm.o -Isrc/hiberlite/include -Lsrc/hiberlite/build -o chain.out -pthread -ldl -fno-common -Wswitch -Wunused-variable -Wparentheses -Wnon-virtual-dtor -Wshorten-64-to-32 -Wundeclared-selector -Wuninitialized -Wunused-function -Wbool-conversion -Wcomma -Wconstant-conversion -Wempty-body -Wenum-conversion -Winfinite-recursion -Wint-conversion -Wrange-loop-analysis -Wstrict-prototypes -Wmove -Wunreachable-code -Wduplicate-method-match -Wreorder -fvisibility-inlines-hidden -g -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk -Wl,-search_paths_first -Wl,-headerpad_max_install_names -framework Accelerate -framework AudioToolbox -framework Carbon -framework Cocoa -framework CoreAudio -framework CoreMIDI -framework IOKit -framework OpenGL -framework QuartzCore -framework WebKit

utils.o: utils.cpp
	$(CC) $(CFLAGS) utils.cpp

Node.o: src/Node.cpp
	$(CC) $(CFLAGS) src/Node.cpp src/NodeServer.cpp src/NodeDatabase.cpp src/Block.cpp src/Transaction.cpp src/BlockContent.cpp

NodeDatabase.o: src/NodeDatabase.cpp
	$(CC) $(CFLAGS) src/NodeDatabase.cpp src/Block.cpp src/Transaction.cpp src/BlockContent.cpp

NodeServer.o: src/NodeServer.cpp
	$(CC) $(CFLAGS) src/NodeServer.cpp src/Transaction.cpp

Wallet.o: src/Wallet.cpp
	$(CC) $(CFLAGS) src/Wallet.cpp src/WalletInterface.cpp

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
	$(CC) $(CFLAGS) src/Block.cpp src/BlockContent.cpp src/Transaction.cpp src/BlockContent.cpp

gtest: Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o
	$(CC) -pthread -std=c++14 test/test.cpp -lgtest -lgtest_main Node.o NodeDatabase.o NodeServer.o Wallet.o WalletDatabase.o WalletInterface.o WalletServer.o Transaction.o TransactionWithStatus.o BlockContent.o Block.o -o test.out -lsqlite3 -lhiberlite -I/Users/bogdansalyp/projects/AstraChain/src/hiberlite/include -L/Users/bogdansalyp/projects/AstraChain/src/hiberlite/build -pthread -ldl
	./test.out

clean:
	rm -rf *.o *.out