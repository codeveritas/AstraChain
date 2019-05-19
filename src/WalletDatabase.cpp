#include "WalletDatabase.hpp"
#include "ObserverErrors.hpp"
#include "hiberlite/include/hiberlite.h"
#include <string.h>
#include <vector>


class Transactions{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(pk_id);
        ar & HIBERLITE_NVP(sender);
        ar & HIBERLITE_NVP(recipient);
        ar & HIBERLITE_NVP(value);
        ar & HIBERLITE_NVP(status);
    }
public:
    int pk_id;
    std::string sender;
    std::string recipient;
    float value;
    int status;
};

HIBERLITE_EXPORT_CLASS(Transactions)

template <class T>
long getTableLength(){
    hiberlite::Database db("db/Wallet.db");
    std::vector< hiberlite::bean_ptr<T> > v=db.getAllBeans<T>();
//    cout << "found " << v.size() << " records in the table\n";
    return v.size();
}

WalletDatabase::WalletDatabase() {
    walletObserver = nullptr;
    hiberlite::Database db("db/Wallet.db");
    db.registerBeanClass<Transactions>();
    db.dropModel();
    db.createModel();

}

WalletDatabase::~WalletDatabase() {}

void WalletDatabase::registerWalletObserver(Wallet* wallet) {
    if (!walletObserver) {
        walletObserver = wallet;
    } else {
        throw ObserverPresent();
    }
}

void WalletDatabase::removeWalletObserver() {
    if (walletObserver) {
        walletObserver = nullptr;
    } else {
        throw NoObserver();
    }
}

void WalletDatabase::addTransaction(TransactionWithStatus transactionWithStatus) {
    hiberlite::Database db("db/Wallet.db");

    if (getTableLength<Transactions>() == 0){
        Transactions x;
        x.pk_id = getTableLength<Transactions>() + 1;
        x.sender = transactionWithStatus.transaction.sender;
        x.recipient = transactionWithStatus.transaction.recipient;
        x.value = transactionWithStatus.transaction.value;
        x.status = transactionWithStatus.status;
        hiberlite::bean_ptr<Transactions> p=db.copyBean(x);

        std::cout << "Added with Pending!!!" << std::endl;
        return;
    }

    int existsWithPending = 0;
    int existsWithDone = 0;
    int existingTransactionIndex = 0;
    std::vector< hiberlite::bean_ptr<Transactions> > transactions=db.getAllBeans<Transactions>();
    std::cout << "TableLength = " << getTableLength<Transactions>() << std::endl;
    for (int i = 0; i < getTableLength<Transactions>(); i++){
        if ((transactions[i]->sender == transactionWithStatus.transaction.sender) &&
            (transactions[i]->recipient == transactionWithStatus.transaction.recipient) &&
            (transactions[i]->value == transactionWithStatus.transaction.value)){
                if (transactions[i] -> status == 0) {
                    existsWithPending = 1;
                    std::cout << "existsWithPending" << std::endl;
                    throw TryingToAddTwoPendingTransactions();
                } else if (transactions[i] -> status == 1) {
                    existsWithDone = 1;
                    std::cout << "existsWithDone" << std::endl;
                    throw TryingToAddTwoDoneTransactions();
                }
            // existingTransactionIndex = transactions[i]->pk_id;
            break;
        }
    }

    if ((existsWithPending && transactionWithStatus.status == false) || // if new pending and db has pending
    (existsWithDone && transactionWithStatus.status == true)) { // if new done and db has done
        std::cout << "Same transaction exists; do nothing" << std::endl;
    } else if (existsWithPending && transactionWithStatus.status == true){
        std::cout << "Changing status" << std::endl;
        for (int i=0; i<getTableLength<Transactions>(); i++){
            if (transactions[i]->sender == transactionWithStatus.transaction.sender &&
                transactions[i]->recipient == transactionWithStatus.transaction.recipient &&
                transactions[i]->value == transactionWithStatus.transaction.value &&
                transactions[i]->status == 0){
                  transactions[i]->status = 1;
              }
        }
    } else {
        Transactions x;
        x.pk_id = getTableLength<Transactions>() + 1;
        x.sender = transactionWithStatus.transaction.sender;
        x.recipient = transactionWithStatus.transaction.recipient;
        x.value = transactionWithStatus.transaction.value;
        x.status = transactionWithStatus.status;
        hiberlite::bean_ptr<Transactions> p=db.copyBean(x);

        std::cout << "New transaction adding" << std::endl;
    }
}

// TODO: normal getAllTransactions()
std::vector<TransactionWithStatus> WalletDatabase::getAllTransactions() {
    std::vector<TransactionWithStatus> transactions;
    hiberlite::Database db("db/Wallet.db");
    std::vector<hiberlite::bean_ptr<Transactions> > DBtransactions = db.getAllBeans<Transactions>();

    for (int i=0; i< getTableLength<Transactions>(); i++){
        TransactionWithStatus x(Transaction(DBtransactions[i]->sender,
                                            DBtransactions[i]->sender,
                                            DBtransactions[i]->value),
                                            DBtransactions[i]->status,0);
        // x.transaction.sender = DBtransactions[i]->sender;
        // x.transaction.recipient = DBtransactions[i]->sender;
        // x.transaction.value = DBtransactions[i]->value;
        // x.status = DBtransactions[i]->status;
        transactions.push_back(x);

    }
    return transactions;
}

// TODO: normal getAllTransactionsByDate()
std::vector<TransactionWithStatus> WalletDatabase::getAllTransactionsByDate(time_t datetime) {
    std::vector<TransactionWithStatus> transactions;
    return transactions;
}

// TODO: normal getAllPendingTransactions()
std::vector<TransactionWithStatus> WalletDatabase::getAllPendingTransactions() {
    std::vector<TransactionWithStatus> transactions;
    hiberlite::Database db("db/Wallet.db");
    std::vector<hiberlite::bean_ptr<Transactions> > DBtransactions = db.getAllBeans<Transactions>();

    for (int i=0; i< getTableLength<Transactions>(); i++){
        if (DBtransactions[i]->status == 0){
          TransactionWithStatus x(Transaction(DBtransactions[i]->sender,
                                              DBtransactions[i]->sender,
                                              DBtransactions[i]->value),
                                              DBtransactions[i]->status,0);
          // x.sender = DBtransactions[i]->sender;
          // x.recipient = DBtransactions[i]->recipient;
          // x.value = DBtransactions[i]->value;
          // x.status = DBtransactions[i]->status;
          transactions.push_back(x);
        }
    }
    return transactions;
}

// TODO: normal getAllDoneTransactions()
std::vector<TransactionWithStatus> WalletDatabase::getAllDoneTransactions() {
  std::vector<TransactionWithStatus> transactions;
  hiberlite::Database db("db/Wallet.db");
  std::vector<hiberlite::bean_ptr<Transactions> > DBtransactions = db.getAllBeans<Transactions>();

  for (int i=0; i< getTableLength<Transactions>(); i++){
      if (DBtransactions[i]->status == 1){
        TransactionWithStatus x(Transaction(DBtransactions[i]->sender,
                                            DBtransactions[i]->sender,
                                            DBtransactions[i]->value),
                                            DBtransactions[i]->status,0);
        // x.transaction.sender = DBtransactions[i]->sender;
        // x.transaction.recipient = DBtransactions[i]->recipient;
        // x.transaction.value = DBtransactions[i]->value;
        // x.status = DBtransactions[i]->status;
        transactions.push_back(x);
      }
  }
  return transactions;
}
