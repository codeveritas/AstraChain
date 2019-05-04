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

#endif //ASTRACHAIN_OBSERVER_ERRORS_HPP