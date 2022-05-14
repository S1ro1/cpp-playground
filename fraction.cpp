#include "fraction.hpp"
#include <assert.h>
#include <iostream>
#include <pthread.h>

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

Fraction::Fraction() {
  numerator = 1;
  denominator = 1;
  isSimple = true;
}

Fraction::Fraction(int a, int b) {
  if (b == 0) {
    throw std::overflow_error("Fraction: division by zero exception!\n");
  }
  numerator = a;
  denominator = b;
  if (gcd(numerator, denominator) == 1) {
    isSimple = true;
  } else {
    isSimple = false;
  }
}

int Fraction::getNumerator() { return numerator; }

int Fraction::getDenominator() { return denominator; }

void Fraction::setNumerator(int a) { numerator = a; }

void Fraction::setDenominator(int a) { denominator = a; }

bool Fraction::isIrreducible() { return isSimple; }

void Fraction::convertToIrreducible() {
  int greatestDivisor = gcd(numerator, denominator);
  if (greatestDivisor == 1) {
    isSimple = true;
    return;
  } else {
    numerator /= greatestDivisor;
    denominator /= greatestDivisor;
    isSimple = true;
  }
}

void Fraction::printFraction() {
  std::cout << "Fraction: " << numerator << "/" << denominator << std::endl;
  if (isSimple) {
    std::cout << "This fraction is irreducible" << std::endl;
  } else {
    std::cout << "This fraction isn't irreducible" << std::endl;
  }
}

Fraction Fraction::operator*(const Fraction &obj) {
  Fraction result =
      Fraction(numerator * obj.numerator, denominator * obj.denominator);
  return result;
}

Fraction Fraction::operator/(const Fraction &obj) {
  Fraction result =
      Fraction(numerator * obj.denominator, denominator * obj.numerator);
  return result;
}

Fraction Fraction::operator+(const Fraction &obj) {
  if (denominator == obj.denominator) {
    return Fraction(numerator + obj.numerator, denominator);
  } else {
    int smallestMultiple =
        (denominator * obj.denominator) / gcd(denominator, obj.denominator);
    int x = smallestMultiple / denominator;
    int y = smallestMultiple / obj.denominator;

    Fraction res =
        Fraction(numerator * x + obj.numerator * y, smallestMultiple);
    res.convertToIrreducible();

    return res;
  }
}

Fraction Fraction::operator-(const Fraction &obj) {
  if (denominator == obj.denominator) {
    return Fraction(numerator - obj.numerator, denominator);
  } else {
    int smallestMultiple =
        (denominator * obj.denominator) / gcd(denominator, obj.denominator);
    int x = smallestMultiple / denominator;
    int y = smallestMultiple / obj.denominator;

    Fraction res =
        Fraction(numerator * x - obj.numerator * y, smallestMultiple);
    res.convertToIrreducible();

    return res;
  }
}

Fraction Fraction::operator*(int a) {
  return Fraction(numerator * a, denominator);
}

Fraction Fraction::operator/(int a) {
  return Fraction(numerator, denominator * a);
}

Fraction Fraction::operator+(int a) {
  Fraction tmp1 = Fraction(numerator, denominator);
  Fraction tmp2 = Fraction(a, 1);
  return tmp1 + tmp2;
}

Fraction Fraction::operator-(int a) {
  Fraction tmp1 = Fraction(numerator, denominator);
  Fraction tmp2 = Fraction(a, 1);
  return tmp1 - tmp2;
}
