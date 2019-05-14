//#include "hiberlite.h"
#include "hiberlite/include/hiberlite.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Node{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_Node);
        ar & HIBERLITE_NVP(fk_Block);
    }
public:
    int pk_Node;
    int fk_Block;
};

HIBERLITE_EXPORT_CLASS(Node)

class Block{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_Block);
        ar & HIBERLITE_NVP(fk_BlockContent);
    }
public:
    int pk_Block;
    int fk_BlockContent;
};

HIBERLITE_EXPORT_CLASS(Block)

class BlockContent{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_BlockContent);
        ar & HIBERLITE_NVP(Number);
        ar & HIBERLITE_NVP(fk_ParentHash);
        ar & HIBERLITE_NVP(Count);
        ar & HIBERLITE_NVP(fk_ArrayID);

    }
public:
    int pk_BlockContent;
    int Number;
    long fk_ParentHash;
    long Count;
    long fk_ArrayID;
};

HIBERLITE_EXPORT_CLASS(BlockContent)

class Array{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_Array);
        ar & HIBERLITE_NVP(fk_Transactions);
        ar & HIBERLITE_NVP(fk_ArrayID);
    }
public:
    int pk_Array;
    int fk_Transactions;
    long fk_ArrayID;
};

HIBERLITE_EXPORT_CLASS(Array)

class Transactions{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_Transactions);
        ar & HIBERLITE_NVP(aName);
        ar & HIBERLITE_NVP(aPays);
        ar & HIBERLITE_NVP(bName);
        ar & HIBERLITE_NVP(bPays);
        ar & HIBERLITE_NVP(fk_Status);
    }
public:
    int pk_Transactions;
    long aName;
    int aPays;
    long bName;
    int bPays;
    int fk_Status;
};

HIBERLITE_EXPORT_CLASS(Transactions)

class Hash{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_Hash);
        ar & HIBERLITE_NVP(Value);
    }
public:
    int pk_Hash;
    long Value;
};

HIBERLITE_EXPORT_CLASS(Hash)


class Status{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_Status);
        ar & HIBERLITE_NVP(Status);
    }
public:
    int pk_Status;
    long Status;
};

HIBERLITE_EXPORT_CLASS(Status)

void createDB()
{
    hiberlite::Database db("Node.db");

    db.registerBeanClass<Node>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<Block>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<BlockContent>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<Array>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<Transactions>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<Hash>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<Status>();
    db.dropModel();
    db.createModel();
}

template <class T>
long getTableLength(){
    hiberlite::Database db("Node.db");
    vector< hiberlite::bean_ptr<T> > v=db.getAllBeans<T>();
//    cout << "found " << v.size() << " records in the table\n";
    return v.size();
}


long getBlockChainLength(){
    hiberlite::Database db("Node.db");
    vector< hiberlite::bean_ptr<Block> > v=db.getAllBeans<Block>();
//    cout << "found " << v.size() << " records in the database\n";
//    cout << "length = " << v.size() << endl;
    return v.size();
}


void writeBlock(int _BlockContent){
    hiberlite::Database db("Node.db");

    Block block;
    block.pk_Block = getBlockChainLength() + 1;
    block.fk_BlockContent = _BlockContent;
    hiberlite::bean_ptr<Block> p=db.copyBean(block);
}


hiberlite::bean_ptr<Block> getLastBlock(){
    hiberlite::Database db("Node.db");
    vector< hiberlite::bean_ptr<Block> > v=db.getAllBeans<Block>();
    hiberlite::bean_ptr<Block> p=db.loadBean<Block>(v.size());

    cout << p->pk_Block << endl;
    cout << p->fk_BlockContent << endl;
    cout << endl;
    return p;
}

int main(){
//    createDB();
//    hiberlite::Database db("Node.db");
//    for (int i=0; i<5; i++){
//        Node x;
//        x.fk_Block = 1;
//
//        hiberlite::bean_ptr<Node> p=db.copyBean(x);
//    }
    createDB();
    writeBlock(888);
    cout << "last Block:";
    getLastBlock();
    cout << "length = " << getBlockChainLength() << endl;
    writeBlock(777);
    cout << "last Block:";
    getLastBlock();
    cout << "length = " << getBlockChainLength() << endl;

    return 0;
}






