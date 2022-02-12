#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



//structs
typedef struct Car{

        char* make;
        char* model;
        int year;
        char* VIN;
        int numDoors;
        char* rearConfig;

} Car;



typedef struct Truck{

        char* make;
        char* model;
        int year;
        char* VIN;
        int numDoors;
        double towingCapacity;

} Truck;



typedef struct Boat{

        char* make;
        char* model;
        int year;
        char* VIN;
        char* motorType;

} Boat;



//constructors

Car* createCar(char* make, char* model, int year, char* VIN, int numDoors, char* rearConfig);

Truck* createTruck(char* make, char* model, int year, char* VIN, int numDoors, double towingCapacity);

Boat* createBoat(char* make, char* model, int year, char* VIN, char* motorType);


