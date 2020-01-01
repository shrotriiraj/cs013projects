/**
 * Course: CS 013 Winter 2019
 *
 * First Name: Iraj
 * Last Name: Shrotri
 * Username: ishro001
 * email address: ishro001@ucr.edu
 *
 *
 * Assignment: Lab 3
 * Filename : Distance.ccp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include "Distance.h"
#include <iostream>
#include <math.h>  

using namespace std;

// ./a.out to run program

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
    */
Distance::Distance(){
    feet = 0;
    inches = 0.0;
};

/* Constructs a distance of ft feet and in inches,
unless in >= 12, in which case the values of feet and inches
are adjusted accordingly. A Distance will always be positive.*/
    
Distance::Distance(unsigned ft, double in){
    Distance dis;
    inches = in;
    feet = ft;
    if ( in >= 12 ){
        while (inches > 12) {
            inches -= 12;
        ++feet;
        } 
    }
};

/*
    Constructs a distance of 0 ft and in inches, 
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
*/ 
Distance::Distance(double in){
    inches = in;
    feet = 0;
    if ( in >= 12 ){
        while (inches > 12) {
            inches -= 12;
            ++feet;
        } 
    }
};



    // Returns just the feet portion of the Distance
    
unsigned Distance::getFeet() const{
    return fabs(feet);
};


    // Returns just the inches portion of the Distance
    
double Distance::getInches() const{
    return fabs(inches);
};

/*
     Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)*/
    
double Distance::distanceInInches() const{
    return ((feet * 12) + inches);
};


    // Returns the entire distance as the equivalent amount of feet.
      //  (e.g., 3 feet 6 inches would be returned as 3.5 feet)
    
double Distance::distanceInFeet() const{
    return ((inches / 12) + feet);
};


//     Returns the entire distance as the equivalent amount of meters.
//        1 inch equals 0.0254 meters.
//        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
    
double Distance::distanceInMeters() const{
    double count = feet * 12;
    count = (count + inches) * 0.0254;
    return count;
};
  

//     Returns the sum of 2 Distances.
 
  
const Distance Distance::operator+(const Distance &rhs) const {
    Distance g = Distance(feet + rhs.getFeet(), inches + rhs.getInches());
    return g;
};

//     Returns the difference between 2 Distances.
    
const Distance Distance::operator-(const Distance &rhs) const{
    Distance g;
    if (feet > rhs.getFeet()) {
        if (inches < rhs.getInches()){
            if (feet == 0){
                g = Distance( feet - rhs.getFeet(), - rhs.getInches() );
            }
            else{
                g = Distance( feet - 1 - rhs.getFeet(), inches + 12 - rhs.getInches() );
            }
        }
        else {
            g = Distance( feet- rhs.getFeet(), inches - rhs.getInches() );
        }
    }
    else {
        if (rhs.getInches() < inches) {
            if (rhs.getFeet() == 0){
                g = Distance(rhs.getFeet() - feet, rhs.getInches() - inches);
            }
            else {
                g = Distance(rhs.getFeet() - 1  - feet, rhs.getInches() + 12 - inches);
            }
        }
        else {
            g = Distance(rhs.getFeet() - feet, rhs.getInches()- inches);
        }
    }
    g.init();
    return g;
};

/*
     Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
*/    
ostream & operator<<(ostream &out, const Distance &rhs){
    return out << rhs.getFeet() << "' " << rhs.getInches() << "\"";
};
/*
        Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
*/

void Distance::init(){
    inches = fabs(inches);
    /*
    if (inches < 0) {
        inches *= -1;
    }
    */
};

