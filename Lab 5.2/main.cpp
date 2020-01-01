#include <iostream>
#include "Point.h"
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
double** ComputeDistances(const Point*, int);
vector<Point> GetPointsFromFile(string&);
Point* ToDynamicArray(vector<Point>);
void DisplayDistances(double**, int);
int main()
{
    string filePoint;
    cout << "Enter the name of point file:" << endl;
    cin >> filePoint;
    vector<Point> pts = GetPointsFromFile(filePoint);
    Point* dpts = ToDynamicArray(pts);
    double** distances = ComputeDistances(dpts, pts.size());
    DisplayDistances(distances, pts.size());
    return 0;
}
vector<Point> GetPointsFromFile(string& filename){
    ifstream inFS(filename.c_str());

    if (!inFS.is_open())
    {
        cout << "Error: can not open the file point." << endl;
        exit(1);
    }

    vector<Point> pts;
    double X;
    double Y;

    while(inFS >> X)
    {
        inFS >> Y;    
        Point newP = Point(X,Y);
        pts.push_back(newP);
    }
    return pts;
}
void DisplayDistances(double** distances, int size){

    for(unsigned int r = 0; r < size; r++){
        for(unsigned int c = 0; c < size; c++){
                cout << setw(10) << left << distances[r][c];
        }
        if(r != size - 1)
             cout << endl;
    }
}

//Passes in a vector of points and returns a pointer to 1D dynamic array of points.
Point* ToDynamicArray(vector<Point> pts){
    Point* toArray = new Point[pts.size()];
    for (int i = 0; i < pts.size(); ++i) {
        toArray[i] = pts.at(i);
    }
    return toArray;
} 

//Passes in 1D dynamic array of points and returns 2D dynamic array of distances.
double** ComputeDistances(const Point* pts, int size){
    double** newDist = new double*[size];
    for (int i = 0; i < size; ++i){
        newDist[i] = new double[size];
        for (int j = 0; j < size; ++j){
            newDist[i][j] = pts[i].Distance(pts[j]);
        }
    }
    return newDist;
}