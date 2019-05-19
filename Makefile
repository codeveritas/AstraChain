SRCS=main.cpp handler.cpp json_converter.cpp
LDFLAGS=-levent
JANSONFLAG=-ljansson
CXXFLAGS=-I/usr/local/include -L/usr/local/lib
PROG=http_server

all:
	g++ -std=c++17 ${SRCS} -o ${PROG} ${LDFLAGS} ${JANSONFLAG}  ${CXXFLAGS}
clean:
	rm -f ${PROG}