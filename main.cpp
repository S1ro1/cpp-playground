#include "fraction.hpp"
#include <iostream>

int main(void) {
  Fraction a = Fraction(4, 2);
  Fraction b = Fraction(2, 3);

  Fraction c = a - b;
  
  c.printFraction();

  return 0;
}
