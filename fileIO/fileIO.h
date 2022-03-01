#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



//structs; not necessary for program but added for extendability
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


typedef enum Vehicle {car, truck, boat} Vehicle;


//deallocators
void freeCar(Car* car); 

void freeTruck(Truck* truck); 

void freeBoat(Boat* boat);


//constructors

Car* createCar(char* make, char* model, int year, char* VIN, int numDoors, char* rearConfig);

Truck* createTruck(char* make, char* model, int year, char* VIN, int numDoors, double towingCapacity);

Boat* createBoat(char* make, char* model, int year, char* VIN, char* motorType);


//functions
Vehicle convertToEnum(char* str);

void printCarInfo(FILE* fp, Car* car); 

void printTruckInfo(FILE* fp, Truck* truck); 

void printBoatInfo(FILE* fp, Boat* boat); 

void writeFile(FILE* input, FILE* output); 
