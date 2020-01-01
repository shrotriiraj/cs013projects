#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;


template<typename T>
void display(T* vals, int n){
    for(int i = 0; i < n; i++){
        cout << setw(5)<< vals[i];
        if(i != n-1){
            cout << ", ";
        }
    
    }cout << endl;
}


/* 
1) A templatized function that sorts contents of v using insertion sort method.
n = size of array
*/
template<typename T>
void insertionSort(T* v, int n){
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int counter = i; counter > 0 && v[counter - 1] > v[counter]; counter--) {
            tmp = v[counter];
            v[counter] = v[counter - 1];
            v[counter - 1] = tmp;
        }
    }
}

/*
2) Returns the length, in number of digits, of value.
For example: radixGetLength(239) returns 3
*/
int radixGetLength(int value){
    int counter = 0;
    for (int i = 1; i <= abs(value); i *= 10 ){
        counter++;
    }
    return counter;
}

/*
3) Returns the maximum length, in number of digits, out of all elements in the array. 
arraySize indicates the size of array.
*/
int radixGetMaxLength(int* array, int arraySize){
    int maxLength = 0;
    for (int i = 0; i < arraySize; i++){
        if (maxLength < radixGetLength(array[i])){
            maxLength = radixGetLength(array[i]);
        }
    }
    return maxLength;
}

int getMax(int array[], int arraySize) { 
    int temp = array[0]; 
    for (int i = 1; i < arraySize; i++) {
        if (array[i] > temp) {
            temp = array[i]; 
        }
    }
    return temp; 
} 
  
void countSort(int array[], int arraySize, int exp) { 
    int output[arraySize]; 
    int i, count[10] = {0}; 
    for (i = 0; i < arraySize; i++) {
        count[ (array[i]/exp)%10 ]++; 
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }
    for (i = arraySize - 1; i >= 0; i--) { 
        output[count[ (array[i]/exp)%10 ] - 1] = array[i]; 
        count[ (array[i]/exp)%10 ]--; 
    } 
    for (i = 0; i < arraySize; i++) {
        array[i] = output[i]; 
    }
} 

/*
4) Sorts contents of array using Radix Sort method. You may assume array only contains positive numbers.
arraySize indicates the size of array.
*/
void radixSort(int* array, int arraySize){
    int max = getMax(array, arraySize); 
    for (int exp = 1; max/exp > 0; exp *= 10) {
        countSort(array, arraySize, exp); 
    }
}

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

int main(){
    srand(time(0));

    int* intVals1 = new int[10];
    int* intVals2 = new int[10];
    char* charVals = new char[10];

    charVals[0] = 'a';
    charVals[1] = 'b';
    charVals[2] = 'c';
    charVals[3] = 'd';
    charVals[4] = 'e';
    charVals[5] = 'f';
    charVals[6] = 'g';
    charVals[7] = 'h';
    charVals[8] = 'i';
    charVals[9] = 'j';

    for(int i = 0; i < 10; i++)
    {
        intVals1[i] = genRandInt(-1000,1000);
        int rnd = genRandInt(0,9);

        intVals2[i] = genRandInt(10,1000);
        rnd = genRandInt(0,9);

        char tmp = charVals[rnd];
        charVals[rnd] = charVals[9-rnd];
        charVals[9-rnd] = tmp;
    }
    
    
    cout << "1) Insertion sort: (sorting array of int) " << endl;
    cout << "Before: ";
    display(intVals1,10);
    cout << "After:  ";
    insertionSort(intVals1,10);
    display(intVals1,10);

    cout << endl << "2) Insertion sort: (sorting array of chars)" << endl;
    cout << "Before: ";
    display(charVals,10);
    cout << "After:  ";
    insertionSort(charVals,10);
    display(charVals,10);

    cout << endl << "3) Radix sort: " << endl;
    cout << "Before: ";
    display(intVals2,10);
    cout << "After:  ";
    radixSort(intVals2,10);
    display(intVals2,10);

    return 0;
}