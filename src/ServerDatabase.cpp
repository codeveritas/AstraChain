#include "ServerDatabase.hpp"
#include "ObserverErrors.hpp"
#include "hiberlite/include/hiberlite.h"
#include <string.h>
#include <vector>

class Nodes{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(node);
        ar & HIBERLITE_NVP(status);
    }
public:
    int pk_id;
    std::string node;
    std::string status;
};

HIBERLITE_EXPORT_CLASS(Nodes)

template <class T>
long getTableLength(){
    hiberlite::Database db("db/Server.db");
    std::vector< hiberlite::bean_ptr<T> > v=db.getAllBeans<T>();
//    cout << "found " << v.size() << " records in the table\n";
    return v.size();
}


ServerDatabase::ServerDatabase() {
    serverObserver = nullptr;
    hiberlite::Database db("db/Server.db");
    db.registerBeanClass<Nodes>();
    db.dropModel();
    db.createModel();
}

ServerDatabase::~ServerDatabase() {}

void ServerDatabase::registerServerObserver(Server* server) {
    if (!serverObserver) {
        serverObserver = server;
    } else {
        throw ObserverPresent();
    }
}


void ServerDatabase::removeServerObserver() {
    if (serverObserver) {
        serverObserver = nullptr;
    } else {
        throw NoObserver();
    }
}


std::vector<Node> ServerDatabase::getAllNodes() {
  std::vector<Node> nodes;
  hiberlite::Database db("db/Server.db");
  std::vector<hiberlite::bean_ptr<Nodes> > DBnodes = db.getAllBeans<Nodes>();

  for (int i=0; i< getTableLength<Nodes>(); i++){
        Node x(Node(DBnodes[i]->node,
                    DBnodes[i]->status,
                    DBnodesi]->value);
        nodes.push_back(x);
  }


  void addNode(std::str node){
      hiberlite::Database db("db/Server.db");

      Nodes x;
      x.pk_id = getTableLength<Transactions>() + 1;
      x.node = node.node
      x.status = node.status
      hiberlite::bean_ptr<Nodes> p=db.copyBean(x);

  }


void changeStatus(Node node, std::str status){
  hiberlite::Database db("db/Server.db");
  std::vector< hiberlite::bean_ptr<Transactions> > nodes=db.getAllBeans<Nodes>();
  for (int i=0; i< getTableLength<Nodes>(); i++){
    if (nodes[i]->node == node.node){
      nodes[i]->status = node.status
  }
}


bool Existence(std::str node){
    hiberlite::Database db("db/Server.db");
    std::vector< hiberlite::bean_ptr<Transactions> > nodes=db.getAllBeans<Nodes>();
    for (int i=0; i< getTableLength<Nodes>(); i++){
        if (nodes[i]->node == node.node &&
            nodes[i]->status == node.status){
          return True;
        }
    return False;
}
