#include <iostream>
#include <math.h> // pow function
using namespace std;

int factorial (int n);

int fibonacci (int n);

/*
'n' is the number of disks. 
'from', 'to' and 'aux' are towers.
*/
void towerOfHanoi(int n, char from, char to, char aux);

int main()
{
    int n; // Number of disks
    cout << "Enter num of disks:" << endl;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    
    //cout << factorial(4) << endl;  //factorial test
    //cout << fibonacci(4) << endl;   //f
    
    return 0;
}

int factorial (int n){
    if (n == 0)
        return 1;
    return n * factorial (n - 1);
}

int fibonacci (int n){
    if (n <= 1)
        return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

void towerOfHanoi(int n, char from, char to, char aux){
    // num of steps equals pow (2,n) - 1
    if (n == 1) 
    { 
        cout << "Disk 1 from " << from << " to " << to << endl; 
        return; 
    } 
    towerOfHanoi(n - 1, from, aux, to); 
    cout << "Disk " << n << " from " << from << " to " << to << endl; 
    towerOfHanoi(n - 1, aux, to, from);
}
