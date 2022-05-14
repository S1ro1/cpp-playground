#include "fraction.hpp"
#include <iostream>

int main(void) {
  Fraction a = Fraction(4, 2);

  a = a + 1;
  a.printFraction();
  
  a = a - 1;
  a.printFraction();

  a = a * 2;
  a.printFraction();
   
  a = a / 2;
  a.printFraction();
  return 0;
}
