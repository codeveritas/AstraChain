#ifndef ASTRACHAIN_OBSERVER_ERRORS_HPP
#define ASTRACHAIN_OBSERVER_ERRORS_HPP

#include <iostream>
#include <exception>

struct NoObserver : public std::exception {
   const char * what () const throw () {
      return "NoObserver Exception";
   }
};

struct ObserverPresent : public std::exception {
   const char * what () const throw () {
      return "ObserverPresent Exception";
   }
};

struct NegativeValueTransaction : public std::exception {
   const char * what () const throw () {
      return "NegativeValueTransaction Exception";
   }
};

struct SameAddressTransaction : public std::exception {
   const char * what () const throw () {
      return "SameAddressTransaction Exception";
   }
};

struct EmptyTransactionList : public std::exception {
   const char * what () const throw () {
      return "EmptyTransactionList Exception";
   }
};

struct TryingToAddTwoPendingTransactions : public std::exception {
   const char * what () const throw () {
      return "TryingToAddTwoPendingTransactions Exception";
   }
};

struct TryingToAddTwoDoneTransactions : public std::exception {
   const char * what () const throw () {
      return "TryingToAddTwoDoneTransactions Exception";
   }
};

#endif //ASTRACHAIN_OBSERVER_ERRORS_HPP
