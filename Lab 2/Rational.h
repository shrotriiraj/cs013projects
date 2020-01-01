#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational
{
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const; 
      void display() const; 
};

#endif