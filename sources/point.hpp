#pragma once
#include <string>

namespace ariel{

class Point{

    private:
        double _x,_y;

    public:
        Point(double xval, double yval);

        double getX() const;
        double getY() const;
        double distance(const Point &other) const;

        std::string print() const;
        static Point moveTowards(const Point &src,const Point &dst,double dist);

};



}