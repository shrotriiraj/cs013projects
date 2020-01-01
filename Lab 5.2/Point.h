#ifndef _POINT_H_
#define _POINT_H_
#include <cmath>

class Point{
    private:    
        double X;
        double Y;
    public:
        Point();
        Point(double,double);
        double Distance(const Point&)const;
        double getX();
        double getY();
};
#endif