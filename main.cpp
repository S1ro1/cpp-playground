#include "fraction.hpp"
#include <iostream>

int main(void) {
  Fraction a = Fraction();

  Fraction b = Fraction(5, 3);
  
  a.printFraction();
  std::cout << "------------------" << std::endl;
  b.printFraction();

  return 0;
}
