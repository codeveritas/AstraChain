SRCS=main.cpp
LDFLAGS=-levent
CXXFLAGS=-I/usr/local/include -L/usr/local/lib
PROG=http_server

all:
	g++ -std=c++17 ${SRCS} -o ${PROG} ${LDFLAGS} ${CXXFLAGS}

clean:
	rm -f ${PROG}