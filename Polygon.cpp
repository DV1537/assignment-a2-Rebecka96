#include <iostream>
#include <string>
#include "Polygon.h"
#include <cmath>

Polygon::Polygon(double *xCoord, double *yCoord, int nrCounter)
{
    this-> xCoord = new double [nrCounter / 2];
    this-> yCoord = new double [nrCounter / 2];
    this-> nrCounter = nrCounter;

    for(int i = 0; i < nrCounter / 2; i++)
    {
        this-> xCoord[i] = xCoord[i];
        this-> yCoord[i] = yCoord[i];
    }
}

std::string Polygon::getType() //{return "Polygon"};
{
    return "Polygon";
}

double Polygon::area()
{   
    double area;
    int j = (nrCounter / 2) - 1;

    for(int i = 0; i < nrCounter / 2; i++)
    {
        area += (xCoord[j] + xCoord[i] * yCoord[j] + yCoord[i]);
        j = i;
        //std::cout << xCoord[j] << '\n' << xCoord[i] << '\n' << yCoord[j] << '\n' << yCoord[i] << '\n';
    }

    area = abs(area / 2);
    return area;
}

double Polygon::circumference()
{
    double circumference = 0.0, circumX, circumY;

    for(int i = 0; i < nrCounter; i++)
    {
        circumX = xCoord[(i + 1) % nrCounter] - xCoord[i];
        circumY = yCoord[(i + 1) % nrCounter] - yCoord[i];
        circumference += sqrt(circumX * circumX + circumY * circumY);
    }

    return circumference;
}

Position Polygon::position()
{
    Position temp;

    for(int i = 0; i < nrCounter / 2; i++)
    {
        temp.xCoord += xCoord[i];
        temp.yCoord += yCoord[i];
    }

    temp.xCoord /= (nrCounter / 2);
    temp.yCoord /= (nrCounter / 2);

    return temp;
}

bool Polygon::isConvex()
{
    if((nrCounter / 2) < 4)
        return true;
    bool notTrue = false;

    int n = nrCounter / 2;

    for(int i = 0; i < n; i++)
    {
        double dx1 = xCoord[(i + 2) % n] - xCoord[(i + 1) % n];
        double dy1 = yCoord[(i + 2) % n] - yCoord[(i + 1) % n];
        double dx2 = xCoord[i] - xCoord[(i + 1) % n];
        double dy2 = yCoord[i] - yCoord[(i + 1) % n];
        double product = dx1 * dy2 - dy1 * dx2;

        if(i == 0)
            notTrue = product > 0;
        else if(notTrue != (product > 0))
            return defaultArea;
    }

    return true;
}