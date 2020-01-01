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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "Matrix.h"
#include <iostream>
#include <ios>
#include <iomanip>

//declare operator<< function in here

ostream & operator<<(ostream &, const Matrix &); 

int main(){
    int operationChoice = -1;
    int displayChoice = -1;

    string matFile1;
    string matFile2;
    string resFile;
    Matrix res;// = Matrix("m1.txt");
    // cout << res;
    // res = res.transpose();
    // cout << res;

    // For Testing
    //Matrix m1 = Matrix( 3, 3, 2);  
    // Matrix m2 = Matrix( 3, 3, 3);
    // Matrix m3;
    // m1.display();
    // m2.display();
    // m3 = m1.multiply(m2);
    // cout << endl;
    // m3.display();
    //cout << m1;
    
    // Matrix m1("t.txt");
    

    cout << "Enter operation (1-4):" << endl
    << "1 - Addition (A + B)" << endl
    << "2 - Subtraction (A - B)" << endl
    << "3 - Multiplication (A * B)" << endl
    << "4 - Transpose A" << endl;

    cin >> operationChoice;

    if(operationChoice == 1 || operationChoice == 2 || operationChoice == 3)
    {
        
        cout << "Enter the filename for the first matrix: " << endl;
        cin >> matFile1;
        cout << "Enter the filename for the second matrix: " << endl;
        cin >> matFile2;
        Matrix A(matFile1);
        Matrix B(matFile2);
        
        // Matrix A;
        // Matrix B;
        
        if(operationChoice == 1)
            res = A.add(B);
        if(operationChoice == 2)
            res = A.subtract(B);
        if(operationChoice == 3)
            res = A.multiply(B);
    }
    else if(operationChoice == 4)
    {
        
        cout << "Enter the file name for matrix: " << endl;
        cin >> matFile1;
        Matrix A(matFile1);
        
        //Matrix A;
        res = A.transpose();
    }

    
    cout << "Display result (1-2):" << endl
    << "1 - Save into a file" << endl
    << "2 - Display in console" << endl;

    cin >> displayChoice;

    if(displayChoice == 1){
        cout << "Enter the file name for saving result: " << endl;
        cin >> resFile;
        res.saveMatrix(resFile);
    }
    else if(displayChoice == 2){
        cout << res;
    }
    

    return 0;
}

//define operator<< function in here