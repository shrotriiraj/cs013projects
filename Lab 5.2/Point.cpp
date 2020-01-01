#include "Point.h"

Point::Point():X(0),Y(0){}

Point::Point(double _x, double _y):X(_x),Y(_y){}

double Point::Distance(const Point &p)const
{
    return sqrt(pow((X - p.X),2) + pow((Y - p.Y),2));
}
double Point::getX() {return X;}
double Point::getY() {return Y;}