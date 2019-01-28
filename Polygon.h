#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
#include <string>
#include "Shape.h"

class Polygon : public Shape
{
    private:
        int nrCounter;
    public:
        std::string getType();
        double area();
        double circumference();
        Position position();
        bool isConvex();
        Polygon(double xCoord[], double yCoord[], int nrCounter);
};

#endif