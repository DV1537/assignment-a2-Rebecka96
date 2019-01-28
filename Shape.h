#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>

struct Position{
    double xCoord;
    double yCoord;
};

class Shape
{
    protected:
        int n;
        double *xCoord;
        double *yCoord;
        int defaultArea = -1; //arean för point, line och konkav
    public:
        virtual std::string getType() = 0;
        virtual double area() = 0;
        virtual double circumreference();
        virtual Position position() = 0;
        virtual bool isConvex();
        virtual double distance(Shape *s);
};

#endif