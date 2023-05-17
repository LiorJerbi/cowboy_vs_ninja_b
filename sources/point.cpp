#include "point.hpp"
#include <iostream>
#include <cmath>
using namespace ariel;
using namespace std;

Point::Point(double xval, double yval):_x(xval),_y(yval){
}
double Point::getX() const{
    return _x;
}
double Point::getY() const{
    return _y;
}

double Point::distance(const Point &other) const{
    return sqrt(pow((other._x-_x),2.0)+pow((other._y-_y),2.0));
}

string Point::print() const{
    string ans;
    ans += "(" + to_string(getX()) + "," + to_string(getY()) + ")";
    return ans;
}

Point Point::moveTowards(const Point &src,const Point &dst,double dist){ 
    if(dist<0)
        throw invalid_argument("Cannot move negative moves!");
    else if(dist==0)
    return src;
    else{
        //calc the distance from the dest.
        double totdist = src.distance(dst);
        if(totdist <= dist)
            return dst;
        
        //calc the diff between distances.
        double diff = dist / totdist;

        //define colsest point.
        double nx = src.getX() + (dst.getX() - src.getX()) * diff;
        double ny = src.getY() + (dst.getY() - src.getY()) * diff;
        return Point(nx,ny);
    }
}
