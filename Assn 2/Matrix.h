/**
 * Course: CS 013 Winter 2019
 *
 * First Name: Iraj
 * Last Name: Shrotri
 * Username: ishro001
 * email address: ishro001@ucr.edu
 *
 *
 * Assignment: Assn 2
 * Filename : Matrix.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Matrix {
    private:

        vector<vector<int> > M;
        unsigned int ROWS;
        unsigned int COLS;
        bool operationIsValid(const Matrix &m, const string &s) const;
        // added m and s

    public:

        //Constructors
        Matrix();
        Matrix(const string &s);        // i added the s
        Matrix(int,int,int);

        //Accessors
        //const void display();     for testing
        const Matrix transpose() const;
        const Matrix add(const Matrix &m) const;
        const Matrix subtract(const Matrix &m) const;
        const Matrix multiply(const Matrix &m) const;
        const void saveMatrix(const string &s) const;       // i added the s

        //Friend function
        friend ostream & operator<<(ostream &, const Matrix &m);    // i added the m
};