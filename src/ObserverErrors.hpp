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