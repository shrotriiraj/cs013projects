// sorting.cpp
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <list>
//#include <array>

using namespace std;

void swap(int *xp, int *yp);

// Display function declarations
void Display(list<int>&);        // displays std::list to std::out
void Display(int a[], int size); // displays array to std::out

// Sorting function declarations
list<int>& Merge(list<int>& C, list<int>& A, list<int>& B); // Merge for list
void Merge(int numbers[], int i, int j, int k);         // Merge for array
void MergeSort(list<int>& S);                           // MergeSort for list
void MergeSort(int numbers[], int i, int k);          // MergeSort for array
void SelectionSort(list<int>& S);                       // SelectionSort for list
void SelectionSort(int numbers[], int numbersSize);     // SelectionSort for array
void InsertionSort(int numbers[], int numbersSize);     // InsertionSort for array
void RadixSort(list<int>& S);                        // RadixSort for list

//Test function declarations
void TestInsertionSortArray(int a[], int size);      // InsertionSort list test
void TestMergeSortList(list<int>& S);                // MergeSort list test
void TestSelectionSortList(list<int>& S);            // SelectionSort list test
void TestRadixSortList(list<int>& S);                // RadixSort list test

int main() {
  srand((unsigned)time(0));   // seed random number generator

    //array (numbers_a*) declarations/initialization
    const int NUMBERS_SIZE = 8; 
    int numbers_a0[] = { 11, 2, 88, 5, 45, 29, 7, 12 };
    int numbers_a1[] = { 88, 45, 29, 12, 11, 7, 5, 2 };
    int numbers_a2[] = { 1, -3, 7, 99, -77, 2, 4, -1 };
    int numbers_a3[] = { 1, 2, 3, 13, 12, 11, 19, 10 };
    //int numbers_a4[] = { 1, 2, 3, 13, 12, 11, 19, 10 }; // added for testing


   //  cout << "SelectionSort Array" << endl;
   //  Display(numbers_a0, NUMBERS_SIZE);
   //  SelectionSort(numbers_a0, NUMBERS_SIZE);
   //  Display(numbers_a0, NUMBERS_SIZE);
    
   //  cout << "InsertionSort Array" << endl;
   //  Display(numbers_a1, NUMBERS_SIZE);
   //  InsertionSort(numbers_a1, NUMBERS_SIZE);
   //  Display(numbers_a1, NUMBERS_SIZE);
    
   //  cout << "MergeSort Array" << endl;
   //  Display(numbers_a2, NUMBERS_SIZE);
   //  MergeSort(numbers_a2, 0, NUMBERS_SIZE);
   //  Display(numbers_a2, NUMBERS_SIZE);
    
  // test InsertionSort on arrays (numbers_a*)
 TestInsertionSortArray(numbers_a0, NUMBERS_SIZE);
 TestInsertionSortArray(numbers_a1, NUMBERS_SIZE);
 TestInsertionSortArray(numbers_a2, NUMBERS_SIZE);
 TestInsertionSortArray(numbers_a3, NUMBERS_SIZE);

//   // list (seq_l*) declarations
   list<int> seq_l0;
   list<int> seq_l1;
   list<int> seq_l2;
   list<int> seq_l3;
   //list<int> seq_l4; // added for testing

   // build lists (seq_l*) from arrays (numbers_a*)
   for(int i = 0; i < NUMBERS_SIZE; i++) {
    seq_l0.push_back(numbers_a0[i]);
    seq_l1.push_back(numbers_a1[i]);
    seq_l2.push_back(numbers_a2[i]);
    seq_l3.push_back(numbers_a3[i]);
    //seq_l4.push_back(numbers_a4[i]); // added for testing
   }
   
   // TestMergeSortList(seq_l3);
   // TestSelectionSortList(seq_l4);

   // MergeSort tests on lists (seq_l*)
   TestMergeSortList(seq_l0); 
   TestMergeSortList(seq_l1);  
   TestMergeSortList(seq_l2);  
   TestMergeSortList(seq_l3); 

   // list (seq_l*) declarations
   list<int> seq_l4;
   list<int> seq_l5;
   list<int> seq_l6;
   list<int> seq_l7;

   const int LARGE_N = 10;     // size for lists *increase* value
   int* a = NULL;              // pointer to int, initialize to OxO
   a = new int[LARGE_N];       // allocate LARGE_N ints pointed to by a

   for(int i = 0; i < LARGE_N; i++) {
    a[i] = (rand() % (LARGE_N*LARGE_N)) + 1; 
    seq_l4.push_back((rand() % (LARGE_N*LARGE_N)) + 1);
    seq_l5.push_back((rand() % (LARGE_N*LARGE_N)) + 1);
    seq_l6.push_back((rand() % (LARGE_N*LARGE_N)) + 1);
    seq_l7.push_back((rand() % (LARGE_N*LARGE_N)) + 1);
   }

//   InsertionSort, MergeSort, SelectionSort, 
//   tests (for LARGE_N, on lists (seq_l*)
   TestInsertionSortArray(a, LARGE_N);
   TestMergeSortList(seq_l4);
   TestMergeSortList(seq_l5); 
   TestSelectionSortList(seq_l6); 
   TestSelectionSortList(seq_l7); 

  return 0;
}

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// Display list contents to std::out
void Display(list<int>& S) {
  for(list<int>::iterator it = S.begin(); it != S.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

//Display array contents to std::out
void Display(int a[], int size) {
 for(int i = 0; i < size; ++i) 
    cout << a[i] << " ";
 cout << endl;
}

list<int>& Merge(list<int>& C, list<int>& A, list<int>& B){ // Merge for list
   C.clear();
   while(!A.empty() && !B.empty()){
      if (A.front() < B.front()){
         C.push_back(A.front());
         A.pop_front();
      }
      else {
         C.push_back(B.front());
         B.pop_front();
      }
   }
   while(!A.empty()){
      int tmp = A.front();
      A.pop_front();
      C.push_back(tmp);
   }
   while(!B.empty()){
      int tmp = B.front();
      B.pop_front();
      C.push_back(tmp);
   }
   return C;
}

void Merge(int numbers[], int i, int j, int k) {    // Merge for array
    int l, m, r;
    int n1 = j - i + 1; 
    int n2 =  k - j; 
    int L[n1], R[n2]; 
  
    for (l = 0; l < n1; l++)  {
        L[l] = numbers[i + l]; 
    }
    for (m = 0; m < n2; m++) {
        R[m] = numbers[j + 1+ m]; 
    }
    l = 0, m = 0, r = l; 
    while (l < n1 && m < n2) { 
        if (L[l] <= R[m]) { 
            numbers[r] = L[l]; 
            l++; 
        } 
        else{ 
            numbers[r] = R[m]; 
            m++; 
        } 
        r++; 
    } 
    while (l < n1) { 
        numbers[r] = L[l]; 
        l++, r++; 
    } 
    while (m < n2) { 
        numbers[r] = R[m]; 
        m++, r++; 
    } 
}

void MergeSort(list<int>& S){ // MergeSort for list
    list<int> S1, S2;
    list<int>::iterator it;
    if (S.size() > 1) {
        it = S.begin();
        for (unsigned int i = 0; i < S.size()/2; i++, it++) {
            S1.push_back(*it);
        }
        for (unsigned int i = S.size()/2; i < S.size(); i++, it++) {
            S2.push_back(*it);
        }
        MergeSort(S1);
        MergeSort(S2);
        Merge(S, S1, S2);
    }
}   

void MergeSort(int numbers[], int i, int k)   {     // MergeSort for array
    int m;
    if (i < k) { 
        m = i + (k - i) / 2; 
        MergeSort(numbers, i, m); 
        MergeSort(numbers, m+1, k); 
        Merge(numbers, i, m, k); 
    } 
}

void SelectionSort(list<int>& S) { // SelectionSort for list
    list<int>::iterator it, it2, it3;
    int minVal;// = 10000;//, oldVal;
    for (it2 = S.begin(); it2 != S.end(); ++it2){
        minVal = 10000;
        for (it = it2; it != S.end(); ++it){
            if (*it < minVal ){
                minVal = *it;
                it3 = it;
            }
        }
        *it3 = *it2;
        *it2 = minVal;
    }
}

void SelectionSort(int numbers[], int numbersSize) { // SelectionSort for array
    int minIndex;
    for (int i = 0; i < (numbersSize - 1); i++){
        minIndex = i;
        for (int j = i + 1; j < numbersSize; j++){
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        swap(&numbers[minIndex], &numbers[i]);
    }
}

void InsertionSort(int numbers[], int numbersSize) { // InsertionSort for array
    int k = 1, j, i, m, key, l, temp, lastVal = numbers[0];
    for (m = 0; l < numbersSize; l++){
       if (numbers[m] > lastVal){
         lastVal = numbers[m]; 
         
       }
    }
    for (j = 0; j < numbersSize; j++){
        key = numbers[j];
        i = j - 1;
        while(i > 0 and numbers[i] > key){
            numbers[i+1] = numbers[i];
            i = i - 1;
        }
        numbers[i+1] = key;
    }
    while (numbers[0] > numbers[k]){
        k++;
    }
    temp = numbers[0];
    //cout << temp << endl;
    for (l = 0; l < (k - 1); l++){
        numbers[l] = numbers[l+1];
    }
    //cout << k << endl;
    numbers[k - 1] = temp;
    if (numbers[numbersSize - 1] == 0){
      numbers[numbersSize - 1] = lastVal;
    }
}

 void RadixSort(list<int>& S) {                       // RadixSort for list
   list<int> S1;
   S1 = S;
}


// InsertionSort list test
void TestInsertionSortArray(int a[], int size) {
 cout << "ARRAY UNSORTED: "; 
 Display(a, size);
 InsertionSort(a, size);
 cout << "ARRAY INSERTION-SORTED: ";
 Display(a, size);  
}

// MergeSort list test
void TestMergeSortList(list<int>& S) { 
 cout << "LIST UNSORTED: ";
 Display(S);
 MergeSort(S);            
 cout << "LIST MERGE-SORTED: ";
 Display(S);
}

// SelectionSort list test
void TestSelectionSortList(list<int>& S) {
 cout << "LIST UNSORTED: ";
 Display(S);
 SelectionSort(S);
 cout << "LIST SELECTION-SORTED: ";
 Display(S);
}

// RadixSort list test
void TestRadixSortList(list<int>& S) {
 cout << "LIST UNSORTED: ";
 Display(S);
 RadixSort(S);
 cout << "LIST RADIX-SORTED: ";
 Display(S);
}