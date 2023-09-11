#include "someclass.hpp"

someclass::someclass()
    : member1(42) { // I've initialized member1 to 42 for demonstration purposes
  // implementation
}

int someclass::getMember1() const { return member1; }
