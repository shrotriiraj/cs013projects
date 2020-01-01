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
 * Filename : Vector.ccp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include <iostream>
#include "Vector.h"

using namespace std;

  
  void Vector::push_back(int item) {
    int g = size();
    v[g - 1] = item;  //inserts item at position size-1
    s++;
  };
  
  /*
  
  void Vector::push_front(int item){
    //inserts item at position 0, shifts items right
  }; 
  
  bool Vector::swap_i_j(int i, int j){
    //swaps the items at pos i and j, true if success 
  }; 
      
  void Vector::swap(Vector &v2){
    //swaps contents, at same positions of v and v2 
  }; 
     
  void Vector::reverse(){
    //reverses the items in v
  }; 
      
  void Vector::clear(){
    //clears the items in v, sets s to 0
  }; 
  
  */
  
  int Vector::size() const {
    return s;
   };  
  
  /*
  
  void Vector::display() const{
    //prints the contents of v to std::out
  };  
      
  bool Vector::is_empty() const{
    //true if size()==0, false otherwise
  }; 
    
  int Vector::get_capacity() const{
    //returns the capacity
  }; 
  
  const int& Vector::at(int i) const{
    //returns const item& at position i in v, rvalue
  };  
      
  */    
      
  int& Vector::at(int i) {
    return v[i];   //returns const item& at position i in v, lvalue
  };  
    
  /*
      
  const sint find(int p) const{
    //returns position of 1st instance of p in v, -1 if not found
  }; 
      
  int find(int a[], int size_a){
    //returns pos of 1st instance a[size_a] in v, -1 if not found
  }; 
  
  bool operator==(Vector rhs){
    //true if this==rhs, item wise, false otherwise
  }; 
  

      
  int& operator[](int i) const{
    //returns const item& at position i in v
  }; 
  
    */
  