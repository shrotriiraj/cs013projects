/**
 * Course: CS 013 Winter 2019
 *
 * First Name: Iraj
 * Last Name: Shrotri
 * Username: ishro001
 * email address: ishro001@ucr.edu
 *
 *
 * Assignment: assn 1
 * Filename : Vector.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
// CS013 
// Vector.h
#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
  private:
    int capacity = 100; //initialize capacity to 100
    int v[100]; //declare internal array of size 100
    int s = 0;  //initialize current number of items in v to 0
  public:
    Vector(); //default constructor
    // mutators
    void push_back(int item);  //inserts item at position size-1
    
    /*
    void push_front(int item); //inserts item at position 0, shifts items right
    bool swap_i_j(int i, int j); //swaps the items at pos i and j, true if success 
    void swap(Vector &v2); //swaps contents, at same positions of v and v2 
    void reverse(); //reverses the items in v
    void clear();   //clears the items in v, sets s to 0
    
    //accessors
    */
    int size() const;  // returns the number of items in v
    /*
    void display() const;  //prints the contents of v to std::out
    bool is_empty() const; //true if size()==0, false otherwise
    int get_capacity() const; //returns the capacity

    const int& at(int i) const;  //returns const item& at position i in v, rvalue
    int& at(int i) ;  //returns const item& at position i in v, lvalue
    int find(int p) const; //returns position of 1st instance of p in v, -1 if not found
    int find(int a[], int size_a); //returns pos of 1st instance a[size_a] in v, -1 if not found

    // overloaded operators
    bool operator==(Vector rhs); //true if this==rhs, item wise, false otherwise
    const int& operator[](int i) const; //returns const item& at position i in v
    */
};



#endif /* VECTOR_H_ */
