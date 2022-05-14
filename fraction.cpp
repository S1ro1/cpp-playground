#include "fraction.hpp"
#include <assert.h>
#include <iostream>

Fraction::Fraction() {
  numerator = 1;
  denominator = 1;
  isSimple = true;
}

Fraction::Fraction(int a, int b) {
  numerator = a;
  denominator = b;
  isSimple = false; // assert it's false, TODO
}

int Fraction::getNumerator() { return numerator; }

int Fraction::getDenominator() { return denominator; }

void Fraction::setNumerator(int a) { numerator = a; }

void Fraction::setDenominator(int a) { denominator = a; }

bool Fraction::isIrreducible() { return isSimple; }

void Fraction::convertToIrreducible() { assert("To be implemented!" && 0); }

void Fraction::printFraction() {
  std::cout << "Numerator : " << numerator << std::endl;
  std::cout << "Denominator : " << denominator << std::endl;
  if (isSimple) {
    std::cout << "This fraction is irreducible" << std::endl;
  } else {
    std::cout << "This fraction isn't irreducible" << std::endl;
  }
}
