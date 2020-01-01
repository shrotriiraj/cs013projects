#include "IntList.h"
#include <iostream>
using namespace std;
// Initializes an empty list.
IntList::IntList(){
    Head = 0;
    Tail = 0;
}

//  Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList(){
    IntNode *T;
    T = Head;
    // 0 could be NULL in while loop
    while ( Head != 0){
        delete Head; // dealocates memory
        T = T -> next;
        Head = T;
    }
}

// Displays to a single line all of the int values stored in the list, each separated by a space.
// This function does NOT output a newline or space at the end.
void IntList::display() const {
    IntNode *T;
    T = Head;
    if (T != 0) {
        cout << T -> data;
        T = T -> next;
    }
    while (T != 0) {
        cout << " " << T -> data;
        T = T -> next;
    }
}

// Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int value) {
    // IntNode* temp;
    // temp = new IntNode(value);
    // temp -> 
    IntNode *T;
    T = Head;
    Head = new IntNode(value);
    Head->next = T;  //outputs 13
}

// Removes the value (actually removes the node that contains the value) at the front end of the list.
// Does nothing if the list is already empty.
void IntList::pop_front(){
    IntNode *T;
    T = Head;
    if ( Head != 0 ){
        delete Head;
        T = T -> next;
        Head = T;
    }
}

// Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
bool IntList::empty() const {
    if (Head == 0){
        return true;
    }
    else {
        return false;
    }
}

// use gdb debugger  
// g++ -g -std=c++ll main.cpp IntList.cpp -Wall -Werror -o a.out
// gdb ./a.out