#include "Rational.h"
#include <iostream>

using namespace std;

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}
Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

Rational getRational() {
   int choice;
   int numer, denom;

   cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
      << "1 - 2 parameters (numerator & denominator)" << endl
      << "2 - 1 parameter (numerator)" << endl
      << "3 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

int main() {
   Rational A, B, result;
   int choice;

   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;

   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;

   cout << "Enter Operation (1 - 4):" << endl
      << "1 - Addition (A + B)" << endl
      << "2 - Subtraction (A - B)" << endl
      << "3 - Multiplication (A * B)" << endl
      << "4 - Division (A / B)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 2) {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 3) {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 4) {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;

   return 0;
}