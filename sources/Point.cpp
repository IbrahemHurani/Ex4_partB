#include "Point.hpp"
using namespace std;
namespace ariel
{
    Point::Point() : x(0), y(0)
    {
    }
    Point::Point(double inX, double inY) : x(inX), y(inY)
    {
    }
    double Point::getX()
    {
        return this->x;
    }
    double Point::getY()
    {
        return this->y;
    }
    double Point::distance(const Point &otherP)
    {
        double dx = this->getX() - otherP.x;
        double dy = this->getY() - otherP.y;
        double result = ((dx * dx) + (dy * dy));
        result = sqrt(result);
        return result;
    }
    void Point::print()
    {
        cout << "(" << this->x << "," << this->y << ")" << endl;
    }
    Point Point::moveTowards(Point &source, Point &target, double distance)
    {
        if (distance < 0)
        {
            throw invalid_argument("the distance is negtive");
        }
        if (distance == 0)
        {
            return source;
        }
        else if (distance >= source.distance(target))
        {
            return target;
        }
        else
        {
            double dx = target.x - source.x;
            double dy = target.y - source.y;
            double d = sqrt(dx * dx + dy * dy);
            double m1 = dx / d * distance;
            double m2 = dy / d * distance;
            Point result(source.x + m1, source.y + m2);

            return result;
        }
    }
    string Point::convert_ToString()
    {
        return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
    }

};
