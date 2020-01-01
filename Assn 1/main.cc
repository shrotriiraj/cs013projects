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
 * Filename : main.ccp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
// CS 013, RUSICH
// Vector Class
// testbench main.cc
// sol
#include <iostream>
#include "Vector.h"
//#include "Vector.cc"

using namespace std;

// local non-class-member display functon, used for testing
// prints contents of Vector, format example: 3 6 7
// inserts a new-line character and flushes the stream
void local_display(const Vector& myv)
{
   for(int i = 0; i < myv.size(); i++)
     cout << myv.at(i) << " ";
   cout << endl;
} 

// tests push_back() operation, displays contents of Vector
void test1_push_back(Vector& myv) {
  myv.push_back(0);
  myv.push_back(1);
  myv.push_back(2);
  cout << "Expected sequence: 0 1 2" << endl;
  cout << "Actual   sequence: ";
  local_display(myv);
}

/*


// tests push_back() operation into a full Vector
// program aborts on an assert failure, (s < capacity)
void test2_push_back(Vector& myv) {
  for(int i = myv.size(); i < myv.get_capacity(); i++)
    myv.push_back(i);
  myv.push_back(-1);//causes program to abort, if assert() used in push_front()
}

// tests clear(), checks that Vector size() is zero after operartion
void test3_clear(Vector& myv) {
  myv.clear();
  if (myv.size() != 0)
    cout << "FAILED, size() != 0 after clear()" << endl;
  else
    cout << "SUCCESS for clear()" << endl;
}

// tests push_front() operation, displays contents of Vector
void test4_push_front(Vector& myv) {
  myv.push_front(0);
  myv.push_front(1);
  myv.push_front(2);
  
  cout << "Expected sequence: 2 1 0" << endl;
  cout << "Actual   sequence: ";
  local_display(myv);
}

// tests push_front() operation into a full Vector
// program aborts on an assert failure, (s < capacity)
void test5_push_front(Vector& myv) {
  for(int i = myv.size(); i < myv.get_capacity(); i++)
    myv.push_front(i);
  myv.push_front(-1);//causes program to abort, if assert() used in push_front()
}

*/

int main ()
{
  // Testbench begin
  cout << "Beginning tests..." << endl;
  
  Vector myv;
  cout << "test1_push_back():" << endl;
  test1_push_back(myv);
  
  /*
  
  cout << "test2_push_back():" << endl;
  test2_push_back(myv);
  
  cout << "test3_clear():" << endl;
  test3_clear(myv);
  
  cout << "test4_push_front():" << endl;
  test4_push_front(myv);
  
  cout << "test5_push_front():" << endl;
  test5_push_front(myv); 
  
  */
  
  cout << "Testing completed." << endl;
  
  
  return 0;
}
