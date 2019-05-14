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
        ar & HIBERLITE_NVP(fk_Vallet_id);
        ar & HIBERLITE_NVP(CurrentValletPays);
        ar & HIBERLITE_NVP(fk_bName);
        ar & HIBERLITE_NVP(bPays);
    }
public:
    int pk_id;
    long fk_Vallet_id;
    int CurrentValletPays;
    long fk_bName;
    int bPays;
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
    int vallet_id;
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
    long Status;
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


int main(){
    createDB();
    hiberlite::Database db("Vallet.db");
    for (int i=0; i<5; i++){
        Vallet x;
        x.pk_id = i;
        x.fk_Transactions = i + 20;
        x.fk_Status = 2;

        hiberlite::bean_ptr<Vallet> p=db.copyBean(x);
    }

    return 0;
}






