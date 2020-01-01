#include "MyList.h"
#include <string.h>
#include <iostream>

using namespace std;

MyList::MyList(){
  head = NULL;
}
    
MyList::MyList(const MyList& str){
   head = new Node();
   for( int i = 0; i <str.size(); i++){
      push_back(str.head->next->value);
  }
}
        
MyList::MyList(const string& str){
   head = NULL;
   for(unsigned int i = 0; i < str.length(); i++){
      push_back(str[i]);
   }
}

MyList::MyList(const char* str){
   head = NULL;
      for(unsigned int i = 0; i < strlen(str); i++){
         push_back(str[i]);
       }
    }

MyList::~MyList(){
   Node* temp = head;
      while(head != 0){
         temp = temp -> next;
         delete head;
         head = temp;
      }
}

void MyList::push_back(char value){
   Node* temp = head;
      if( temp == NULL){
         head = new Node();
         head->value = value;
         head->next=NULL;
      }
      else{
         while( temp -> next !=  0 ){
            temp = temp ->next;
         }
            temp ->next = new Node();
            temp ->next-> value = value;
      }
}
            
void MyList::push_front(char value){
   Node* temp = head;
   head = new Node();
   head->value = value;
   head -> next = temp;
}
    
int MyList::size()const{
   int count = 0;
   Node* temp = head;
   while(temp != 0){
      count++;
      temp = temp -> next;
   }
   return count;
}

void MyList::pop_front(){
   if( head == NULL){
      return;
   }
   Node* temp = head;
   head = head->next;
   delete temp;
}

void MyList::pop_back(){
   if(head == NULL){
      return;
   }
   Node* temp = head;
   Node* temp2 = NULL;
   while(temp->next !=NULL){
      temp2 = temp;
      temp = temp ->next; 
   }
   if(temp2 != NULL){
      temp2 -> next = NULL;
   }
   delete temp;
}

void MyList::swap(int i, int j){
   if(i >= 0 && i < size() && j >= 0 && j < size()){
      Node* temp = head;
      Node* temp2 = head;
      char TEMP;
      for(int k = 0; k < i; k++){
         temp = temp -> next;
      }
      for( int k = 0; k < j; k++){
         temp2 = temp2 -> next;
      }
      TEMP = temp -> value;
      temp->value = temp2 -> value;
      temp2->value = TEMP;
   }
}
       
void MyList::insert_at_pos(int i, char value){
   if(i < 0 || i > size()){
      return;
   } 
   else{
      if(i == 0){
         push_front(value);
      }
      else if(i == size()){
         push_back(value);
      }
      else{
         Node* temp = head;
         for( int j = 0; j < i-1; j++){
            Node* temp2 = temp->next;
            temp->next = new Node();
            temp->next->value = value;
            temp-> next ->next = temp2;
         }
      }
   }   
}

void MyList::reverse(){
   for(int i = 0;i<size()/2;i++){
      swap(i,(size()-i-1));
   }
}

void MyList::print()const{
   if(head == NULL){
      return;
   }
   Node *temp = head;
   while(temp != NULL){
      cout<< temp -> value;
         temp = temp->next;
   }
}

int MyList::find(char value)const{
   Node* temp = head;
   for(int i = 0; i < size(); i++){
      if(temp->value == value){
         return i;
      }
   temp = temp->next;
   }
   return -1; 
}

int MyList::find(MyList& query_str)const{
   Node *temp = head;
   Node* temp2;
   temp2 = head;
   int m = query_str.size();
   for( int i = 0; i < size(); i++){
      if( temp->value == query_str[0]){
         for(int j = 0; j<= m; j++){
            if( j == m){
               return i;
            }
            if(temp2->value != query_str[j]){
               break;
            }
         temp2 = temp2->next;
         }
      }
   temp = temp->next;
   temp2 = temp;
   }
   return -1;
}

MyList& MyList::operator=(const MyList &str){
   Node* temp = head;
   while(head != 0){
      temp = temp -> next;
      delete head;
      head = temp;
   }
   for( temp = str.head; temp != NULL; temp = temp->next){
      push_back(temp->value);
   }
   return *this;
}
     
char& MyList::operator[](const int i) {
   Node *temp = head;
   for(int j = 0; j < i; j++){
      temp = temp->next;
   }
   return temp->value;
}

MyList MyList::operator+(const MyList &str){
   for(Node* T =str.head; T != NULL; T = T->next){
      push_back(T->value);
   }
   return *this;
}