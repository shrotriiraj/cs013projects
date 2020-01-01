#include <iostream>
#include <vector>

using namespace std;

// Passes in an array along with the size of the array and returns 
// the mean of all values stored in the array.

double mean(const double array[], int arraySize){
    double mean = 0;
    for (int i = 0; i < arraySize; ++i){
        mean = mean + array[i];
    }
    mean = mean / arraySize;
    return mean;
}

// Passes in an array, the size of the array, and the index of a value
// to be removed from the array. The function should remove the value 
// at this index by shifting all of the values after this value up, keeping 
// the same relative order of all values not removed.

void remove(double array[], int arraySize, int index){
    for (int i = index; i < arraySize - 1; ++i){
        array[i] = array[i + 1];
    }
}

// Passes in an array and the size of the array, and
// then outputs each value in the array separated by a comma and 
// space, with no comma, space or newline at the end.

void display(const double array[], int arraySize){
    cout << array[0];
    for (int i = 1; i < arraySize; ++i){
        cout << ", " << array[i];
    }
    cout << endl;
}

int main() {
    // Declare an array of doubles of size 10.
    double a[10];
    double count;
    int index;
    // Fill the array with 10 doubles entered by the user.
    cout << "Enter 10 values:" << endl;
    cout << endl;
    for (int i = 0; i < 10; ++i){
        cin >> count;
        a[i] = count;
    }
    
    //display(a, 10);
    
    // Call the mean function passing it this array and output the value returned.
    cout << "Mean: " << mean(a, 10) << endl;
    cout << endl;
    // Ask the user for the index (0 to 9) of the value they want to remove.
    cout << "Enter index of value to be removed: " << endl;
    cin >> index;
    // Call the display function to output the array.
    cout << "Before removing value: ";
    display(a, 10);
    // Call the remove function to remove the value at the index provided by the user.
    remove(a, 10, index);
    // Call the display function again to output the array with the value removed.
    cout << "After removing value: ";
    display(a, 9);
    return 0;
}
