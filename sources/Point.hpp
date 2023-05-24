#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <cmath>
using namespace std;
namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point();
        Point(double, double);
        double getX();
        double getY();

        double distance(const Point &otherP);
        void print();
        static Point moveTowards(Point &source, Point &target, double);
        string convert_ToString();
    };

};

#endif
