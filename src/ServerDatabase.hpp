#ifndef ASTRACHAIN_SERVER_DATABASE_HPP
#define ASTRACHAIN_DERVER_DATABASE_HPP

#include "Node.hpp"
#include "hiberlite/include/hiberlite.h"


class Server;

class ServerDatabase {
private:

    Server* serverObserver;

public:
    ServerDatabase();

    ~ServerDatabase();

    void registerServerObserver(Server* server);

    void removeServerObserver();

    void addNode(std::str Node);

    std::vector<Node> getAllNodes();

    void changeStatus(Node node, std::str status);

    bool Existence(std::str node);
};

#endif //ASTRACHAIN_WALLET_SERVER_HPP
