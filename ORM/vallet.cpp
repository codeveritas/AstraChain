//#include "hiberlite.h"
#include "hiberlite/include/hiberlite.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Vallet{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(fk_Transactions);
        ar & HIBERLITE_NVP(fk_Status);
        ar & HIBERLITE_NVP(Date);
    }
public:
    int pk_id;
    int fk_Transactions;
    int fk_Status;
    int Date;
};

HIBERLITE_EXPORT_CLASS(Vallet)

class Transactions{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(aName);
        ar & HIBERLITE_NVP(aPays);
        ar & HIBERLITE_NVP(bName);
        ar & HIBERLITE_NVP(bPays);
    }
public:
    int pk_id;
    long aName;
    float aPays;
    long bName;
    float bPays;
};

HIBERLITE_EXPORT_CLASS(Transactions)

class User{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(vallet_id);

    }
public:
    int pk_id;
    long vallet_id;
};

HIBERLITE_EXPORT_CLASS(User)


class Status{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(Status);
    }
public:
    int pk_id;
    string Status;
};

HIBERLITE_EXPORT_CLASS(Status)

void createDB()
{
    hiberlite::Database db("Vallet.db");

    db.registerBeanClass<Vallet>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<Transactions>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<User>();
    db.dropModel();
    db.createModel();

    db.registerBeanClass<Status>();
    db.dropModel();
    db.createModel();
}

template <class T>
long getTableLength(){
    hiberlite::Database db("Vallet.db");
    vector< hiberlite::bean_ptr<T> > v=db.getAllBeans<T>();
//    cout << "found " << v.size() << " records in the table\n";
    return v.size();
}

void creatingStatusTable(){
    hiberlite::Database db("Vallet.db");

    Status x;
    x.pk_id = 1;
    x.Status = "done";
    hiberlite::bean_ptr<Status> p=db.copyBean(x);

    x.pk_id = 2;
    x.Status = "pending";
    hiberlite::bean_ptr<Status> p1=db.copyBean(x);
}

int insertDoneTransaction(Transactions _transaction){
    hiberlite::Database db("Vallet.db");

    if (getTableLength<Transactions>() == 0){
        Transactions x;
        x.pk_id = getTableLength<Transactions>() + 1;
        x.aName = _transaction.aName;
        x.aPays = _transaction.aPays;
        x.bName = _transaction.bName;
        x.bPays = _transaction.bPays;
        hiberlite::bean_ptr<Transactions> p=db.copyBean(x);

        Vallet y;
        y.pk_id = x.pk_id = getTableLength<Vallet>() + 1;
        y.fk_Transactions = x.pk_id;
        y.fk_Status = 1;
        hiberlite::bean_ptr<Vallet> p1=db.copyBean(y);
        cout << "Added with Done!!!" << endl;
        return 0;
    }

    int existsTransaction = 0;
    int existsWithPending = 0;
    int existsWithDone = 0;
    int existingTransactionIndex = 0;
    vector< hiberlite::bean_ptr<Transactions> > transactions=db.getAllBeans<Transactions>();
    cout << "TableLength = " << getTableLength<Transactions>() << endl;
    for (int i=1; i< getTableLength<Transactions>(); i++){
//        cout << transactions[i]->aName << endl;
//        cout << _transaction.aName << endl;
//        cout << transactions[i]->bName << endl;
//        cout << _transaction.bName << endl;

        if (transactions[i]->aName == _transaction.aName &&
            transactions[i]->aPays == _transaction.aPays &&
            transactions[i]->bName == _transaction.bName &&
            transactions[i]->aPays == _transaction.aPays ){
            existsTransaction = 1;
            existingTransactionIndex = transactions[i]->pk_id;
            break;
        }
    }

    if (existsTransaction == 1) {
        vector<hiberlite::bean_ptr<Vallet> > vallet = db.getAllBeans<Vallet>();
        for (int j = 1; j < getTableLength<Vallet>(); j++) {
            if (vallet[j]->fk_Transactions == existingTransactionIndex){
                if (vallet[j]->fk_Status == 2){
                    existsWithPending = 1;
                    vallet[j]->fk_Status = 1;
                    cout << "Transaction exists with Pending -> Changed status for Done" << endl;
                    break;
                }
                else {
                    existsWithDone = 1;
                    cout << "Transaction exists with Done" << endl;
                    return 1;
                }
            }
        }
    }
    else {
        cout << "existsTransaction == " << existsTransaction << endl;

        Transactions x;
        x.pk_id = getTableLength<Transactions>() + 1;
        x.aName = _transaction.aName;
        x.aPays = _transaction.aPays;
        x.bName = _transaction.bName;
        x.bPays = _transaction.bPays;
        hiberlite::bean_ptr<Transactions> p=db.copyBean(x);

        Vallet y;
        y.pk_id = x.pk_id = getTableLength<Vallet>() + 1;
        y.fk_Transactions = x.pk_id;
        y.fk_Status = 1;
        hiberlite::bean_ptr<Vallet> p1=db.copyBean(y);
        cout << "Added with Done!!!" << endl;
    }

    return 0;
}


int insertPendingTransaction(Transactions _transaction){
    hiberlite::Database db("Vallet.db");

    if (getTableLength<Transactions>() == 0){
        Transactions x;
        x.pk_id = getTableLength<Transactions>() + 1;
        x.aName = _transaction.aName;
        x.aPays = _transaction.aPays;
        x.bName = _transaction.bName;
        x.bPays = _transaction.bPays;
        hiberlite::bean_ptr<Transactions> p=db.copyBean(x);

        Vallet y;
        y.pk_id = x.pk_id = getTableLength<Vallet>() + 1;
        y.fk_Transactions = x.pk_id;
        y.fk_Status = 2;
        hiberlite::bean_ptr<Vallet> p1=db.copyBean(y);
        cout << "Added with Pending!!!" << endl;
        return 0;
    }

    int existsTransaction = 0;
    int existsWithPending = 0;
    int existsWithDone = 0;
    int existingTransactionIndex = 0;
    vector< hiberlite::bean_ptr<Transactions> > transactions=db.getAllBeans<Transactions>();
//    cout << getTableLength<Transactions>() << endl;
    for (int i=1; i< getTableLength<Transactions>(); i++){
//        cout << transactions[i]->aName << endl;
//        cout << _transaction.aName << endl;
//        cout << transactions[i]->bName << endl;
//        cout << _transaction.bName << endl;

        if (transactions[i]->aName == _transaction.aName &&
            transactions[i]->aPays == _transaction.aPays &&
            transactions[i]->bName == _transaction.bName &&
            transactions[i]->aPays == _transaction.aPays ){
            existsTransaction = 1;
            existingTransactionIndex = transactions[i]->pk_id;
            break;
        }
    }
    if (existsTransaction == 1) {
//        vector<hiberlite::bean_ptr<Vallet> > vallet = db.getAllBeans<Vallet>();
//        for (int j = 1; j < getTableLength<Vallet>(); j++) {
//            if (vallet[j]->fk_Transactions == existingTransactionIndex){
//                if (vallet[j]->fk_Status == 1){
//                    int existsWithDone  = 1;
//                    cout << "Already Done" << endl;
//                    break;
//                }
//                if (vallet[j]->fk_Status == 2){
//                    existsWithPending = 1;
//                    cout << "Transaction existed with Pending" << endl;
//                }
//            }
//        }
        cout << "Transaction exists" << endl;
        return 1;
    }
    else{
        Transactions x;
        x.pk_id = getTableLength<Transactions>() + 1;
        x.aName = _transaction.aName;
        x.aPays = _transaction.aPays;
        x.bName = _transaction.bName;
        x.bPays = _transaction.bPays;
        hiberlite::bean_ptr<Transactions> p=db.copyBean(x);

        Vallet y;
        y.pk_id = x.pk_id = getTableLength<Vallet>() + 1;
        y.fk_Transactions = x.pk_id;
        y.fk_Status = 2;
        hiberlite::bean_ptr<Vallet> p1=db.copyBean(y);
        cout << "Added with Pending!!!" << endl;
    }

}

void Test(){
    createDB();
    hiberlite::Database db("Vallet.db");

    Transactions a;
    a.aName = 0123453;
    a.aPays = 8;
    a.bName = 6644375;
    a.bPays = 9;


    Transactions b;
    b.aName = 77777;
    b.aPays = 3;
    b.bName = 66666;
    b.bPays = 4;

    Transactions c;
    c.aName = 11111;
    c.aPays = 4;
    c.bName = 22222;
    c.bPays = 9;

    creatingStatusTable();
    insertPendingTransaction(c);
    insertPendingTransaction(c);
    insertDoneTransaction(c);
    insertDoneTransaction(c);

    cout << "---------" << endl;
    insertPendingTransaction(a);
    insertPendingTransaction(a);
    insertPendingTransaction(b);
    insertDoneTransaction(a);
    insertDoneTransaction(b);
    insertDoneTransaction(b);
}


int main(){
    Test();
    return 0;
}






