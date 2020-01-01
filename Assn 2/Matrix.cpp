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
 * Filename : Matrix.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
 #include <fstream>
 #include "Matrix.h"
 #include <iostream>
 #include <cstdlib>
 
 using namespace std;
 
// private:

    // vector<vector<int> > M;
    // unsigned int ROWS;
    // unsigned int COLS;

bool Matrix::operationIsValid(const Matrix &m, const string &s) const{
    if (s == "ADD" || s == "SUBTRACT"){
        if (m.ROWS == ROWS && m.COLS == COLS){
            return true;
        }
    }
    if (s == "MULTIPLY"){
        if (m.ROWS == COLS ){
            return true;
        }
    }
    return false;
}

//public:
    
    //Constructos
Matrix::Matrix(){

    ROWS = 3;
    COLS = 3;
    //cout << "hello";
    //I got this idea from stackoverflow, where you go through each 
    //colum and then switch to rows to fill values
    // unsigned int x, y;
    // x = ROWS + 1;
    // y = COLS + 1;
    for (unsigned int i = 0; i < ROWS; ++i){
        std::vector<int> N;
        for (unsigned int j = 0; j < COLS; ++j){
            N.push_back(0);
        }
        M.push_back(N);
    }
}

Matrix::Matrix(const string &s){
    fstream file;
    int c;
    file.open(s.c_str()); //works if i put text file directly inside it
        // .c_str() is from stack overflow
    if (file){
        if (file >> c)
            ROWS = c;
        if (file >> c)
            COLS = c;
        for (unsigned int i = 0; i < ROWS; i++){
            std::vector<int> N;
            for (unsigned int j = 0; j < COLS; j++){
                if (file >> c){
                    N.push_back(c);
                }
            }
        M.push_back(N);
        }
    }
    else {
        cout << "An error occurred in opening the " << s << endl;
        exit(1);   
    }
    
   file.close();
};
    
Matrix::Matrix(int a, int b, int c){
    ROWS = a;
    COLS = b;
    for ( int i = 0; i < a; i++){
        std::vector<int> N;
        for ( int j = 0; j < b; j++){
            N.push_back(c);
        }
        M.push_back(N);
    }
}

// FOR TESTING
// const void Matrix::display(){
//     for (unsigned int i = 0; i + 1 < ROWS; i++){
//         for (unsigned int j = 0; j + 1 < COLS; j++){
//             cout << M[i][j] << "    ";
//         }
//     cout << endl;
//     }
// }
    
    // Accessors
const Matrix Matrix::transpose() const{
    Matrix mt = Matrix(COLS, ROWS, 0);
    for (unsigned int i = 0; i < COLS; i++){
        for (unsigned int j = 0; j < ROWS; j++){
            mt.M.at(i).at(j)= M.at(j).at(i);
        }
    }
    return mt;
}

const Matrix Matrix::add(const Matrix &m) const{
    Matrix mt = Matrix(ROWS, COLS, 0);
    if (operationIsValid(m, "ADD")) {
        for (unsigned int i = 0; i < ROWS; i++){
            for (unsigned int j = 0; j < COLS; j++){
                mt.M.at(i).at(j)= m.M.at(i).at(j) + M.at(i).at(j);
            }
        }
    }
    return mt;
}

const Matrix Matrix::subtract(const Matrix &m) const{
    Matrix mt = Matrix(ROWS, COLS, 0);
    if (operationIsValid(m, "SUBTRACT")) {
        for (unsigned int i = 0; i < ROWS; i++){
            for (unsigned int j = 0; j < COLS; j++){
                mt.M.at(i).at(j)= M.at(i).at(j) - m.M.at(i).at(j);
            }
        }
    }
    return mt;
}

    //c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0]
const Matrix Matrix::multiply(const Matrix &m) const{
    Matrix mt = Matrix(ROWS ,m.COLS, 0);
    // for (unsigned int i = 0; i < m.COLS; i++){
    //     for (unsigned int j = 0; j < ROWS; j++){
    //         mt.M.at(i).at(j)= m.M.at(i).at(j) * M[i][j];// + m.M.at(i).at(j) * M[i][j];
    //     }
    // }
    if (operationIsValid(m, "MULTIPLY")) {
        for(unsigned int i = 0; i < m.COLS; ++i){
            for(unsigned int j = 0; j < ROWS; ++j){
                for(unsigned int k = 0; k < COLS; ++k)
                {
                 mt.M.at(j).at(i) += m.M.at(k).at(i) * M.at(j).at(k);
                 //cout << i <<  " " << j << " " << k <<endl; 
                }
            }
        }
    }
    return mt;
}

const void Matrix::saveMatrix(const string &s) const{
    ofstream myfile;
    myfile.open (s.c_str());
    myfile << ROWS << endl;
    myfile << COLS << endl;
    for (unsigned int i = 0; i < ROWS; i++){
        for (unsigned int j = 0; j < COLS; j++){
            myfile << M.at(i).at(j) << "    ";
        }
    myfile << endl;
    }
    myfile.close();
}

    //Friend function
ostream & operator<<(ostream &out, const Matrix &m){
    cout << m.ROWS << "    " << endl;
    cout << m.COLS << "    " <<endl;
    // basically just m.display();
    for (unsigned int i = 0; i < m.ROWS; i++){
        for (unsigned int j = 0; j < m.COLS; j++){
            if(m.M.at(i).at(j) < 10)
                cout << m.M.at(i).at(j) << "    ";
            else if (m.M.at(i).at(j) >= 10)
                cout << m.M.at(i).at(j) << "   ";
        }
    cout << endl;
    }
    return out << "";
}
    