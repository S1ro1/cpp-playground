#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
  int numerator;
  int denominator;
  bool isSimple;

public:
  Fraction();
  Fraction(int, int);

  int getNumerator();
  void setNumerator(int);

  int getDenominator();
  void setDenominator(int);

  bool isIrreducible();
  void convertToIrreducible();

  void printFraction();

  Fraction operator*(Fraction const &);
  Fraction operator/(Fraction const &);
  Fraction operator+(Fraction const &);
  Fraction operator-(Fraction const &);

  Fraction operator*(int);
  Fraction operator/(int);
  Fraction operator+(int);
  Fraction operator-(int);
};

int gcd(int, int);

#endif
