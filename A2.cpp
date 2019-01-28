#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

int main(int argc, const char *argv[])
{
    int size = 0;
    int sum = 0;
    int nrCounter = 0;
    int arraySize = 0;
    double average = 0;
    double *array = new double[1]; //börjar med en plats och ökar med platser i while-loopen

    std::ifstream myFile;

    myFile.open(argv[1]); 

    if(!myFile.is_open()) //om filen inte går att öppna, visa fel-meddelande och avsluta programmet
    {
        std::cout << "ERROR! The file could not open!" << '\n';
        system ("PAUSE");
    }    

    while(myFile >> array[nrCounter]) //spara myFile-innehållet i arrayen
    {
        sum += array[nrCounter];

        nrCounter++;

        arraySize += 2;

        double *secondArray = new double[arraySize];
                
        for(int i = 0; i < nrCounter; i++)
            secondArray[i] = array[i];

        delete[] array; 
        array = nullptr;

        array = secondArray; //array pekar på secondArray
    }

    size = nrCounter / 2;
    
    double *xCoord = new double[size]; //fel meddelande, varför????
    double *yCoord = new double[size]; //fel meddelande, varför????
    int xSize = 0;
    int ySize = 0;

    for(int i = 0; i < nrCounter; i++) //sätter dit x- och y-koordinater i varsinn array
    {
        if(i % 2 == 0)
        {
            xCoord[xSize] = array[i];
            xSize++;
        }    
        else
        {
            yCoord[ySize] = array[i];
            ySize++;  
        }   
    }

    //objekt
    if(nrCounter == 2)
    {
        Point pointShape(xCoord, yCoord, nrCounter);
        std::cout << "The area is: " << pointShape.area() << '\n';
    }
    if(nrCounter == 4)
    {
        Line lineShape(xCoord, yCoord, nrCounter);
        std::cout << "The area is: " << lineShape.area() << '\n';
    }
    if(nrCounter == 6)
    {
        Triangle triangleShape(xCoord, yCoord, nrCounter);
        std::cout << "The area is: " << triangleShape.area() << '\n';
    }
    if(nrCounter > 6)
    {
        Polygon polygonShape(xCoord, yCoord, nrCounter);
        std::cout << "The area is: " << polygonShape.area() << '\n';
    }
    
    delete[] xCoord, yCoord; 
    xCoord, yCoord = nullptr;

    system ("PAUSE");
    
    return 0;
}

