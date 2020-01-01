#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
};

Rational::Rational(int numerator)
{
    this->numerator = numerator;
    denominator = 1;
};

Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
};

const Rational Rational::add(const Rational &rhs) const
{
    Rational Solution;
    Solution.numerator = (numerator * rhs.denominator) + (denominator * rhs.numerator);
    Solution.denominator = denominator * rhs.denominator;
    return Solution;
};

const Rational Rational::subtract(const Rational &rhs) const
{
    Rational Solution;
    Solution.numerator = (numerator * rhs.denominator) - (denominator * rhs.numerator);
    Solution.denominator = denominator * rhs.denominator;
    return Solution;
};

const Rational Rational::multiply(const Rational &rhs) const
{
    Rational Solution;
    Solution.numerator = numerator * rhs.numerator;
    Solution.denominator = denominator * rhs.denominator;
    return Solution;
};

const Rational Rational::divide(const Rational &rhs) const
{
    Rational Solution;
    Solution.numerator = numerator * rhs.denominator;
    Solution.denominator = denominator * rhs.numerator;
    return Solution;
};

void Rational::display() const{
    
    cout << numerator << " / " << denominator;
}