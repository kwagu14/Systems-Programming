#include "fileIO.h"



int main(){

	Car* car1 = createCar("Tesla", "Model S", 2021, "0qa948trldfjasdf8", 4, "trunk"); 
	printf("[car]\n\t%s\n\t%s\n\t%d\n\t%s\n\t%d\n\t%s\n", car1->make, car1->model, car1->year, car1->VIN, car1->numDoors, car1->rearConfig);
	Truck* truck1 = createTruck("Ford", "F-150 XLT", 2022, "aero8qwaejfalskdf", 2, 1.5);
        printf("[truck]\n\t%s\n\t%s\n\t%d\n\t%s\n\t%d\n\t%f\n", truck1->make, truck1->model, truck1->year, truck1->VIN, truck1->numDoors, truck1->towingCapacity);
	Boat* boat1 = createBoat("Yamaha", "190 FSH", 2016, "sdluaw43rjearfaod", "inboard");
        printf("[boat]\n\t%s\n\t%s\n\t%d\n\t%s\n\t%s\n", boat1->make, boat1->model, boat1->year, boat1->VIN, boat1->motorType);	
	return 0;
}




//constructors
Car* createCar(char* make, char* model, int year, char* VIN, int numDoors, char* rearConfig){

	Car* newCar = (Car *) malloc(sizeof(Car));
	newCar -> make = (char *) malloc(50 * sizeof(char));
	newCar -> model = (char *) malloc(50 * sizeof(char));
	newCar -> VIN = (char *) malloc(50 * sizeof(char));
	newCar -> rearConfig = (char *) malloc(50 * sizeof(char)); 	

	strcpy(newCar -> make, make);
	strcpy(newCar -> model, model); 
	strcpy(newCar -> VIN, VIN);
       	strcpy(newCar -> rearConfig, rearConfig); 	
	newCar -> year = year; 
	newCar -> numDoors = numDoors; 

}




Truck* createTruck(char* make, char* model, int year, char* VIN, int numDoors, double towingCapacity){

	Truck* newTruck = (Truck *) malloc(sizeof(Truck));
	newTruck -> make = (char *) malloc(50 * sizeof(char));
	newTruck -> model = (char *) malloc(50 * sizeof(char));
	newTruck -> VIN = (char *) malloc(50 * sizeof(char)); 	

	strcpy(newTruck -> make, make);
	strcpy(newTruck -> model, model); 
	strcpy(newTruck -> VIN, VIN); 	
	newTruck -> year = year; 
	newTruck -> numDoors = numDoors;
       	newTruck -> towingCapacity = towingCapacity;

}



Boat* createBoat(char* make, char* model, int year, char* VIN, char* motorType){
	
	Boat* newBoat = (Boat *) malloc(sizeof(Boat));
	newBoat -> make = (char *) malloc(50 * sizeof(char));
	newBoat -> model = (char *) malloc(50 * sizeof(char));
	newBoat -> VIN = (char *) malloc(50 * sizeof(char));
	newBoat -> motorType = (char *) malloc(50 * sizeof(char)); 	

	strcpy(newBoat -> make, make);
	strcpy(newBoat -> model, model); 
	strcpy(newBoat -> VIN, VIN);
       	strcpy(newBoat -> motorType, motorType); 	
	newBoat -> year = year; 



}
