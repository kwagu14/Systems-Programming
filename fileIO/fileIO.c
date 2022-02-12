#include "fileIO.h"



int main(){

	//open file
	//read line by line
	//switch statement for car, truck, or boat


	Vehicle v1 = convertToEnum("car");
	Vehicle v2 = convertToEnum("truck"); 
	Vehicle v3 = convertToEnum("boat"); 

	printf("car: %d\ttruck: %d\tboat: %d\n", v1, v2, v3);

	Car* car1 = createCar("Tesla", "Model S", 2021, "0qa948trldfjasdf8", 4, "trunk");
	Truck* truck1 = createTruck("Ford", "F-150 XLT", 2022, "aero8qwaejfalskdf", 2, 1.5);
	Boat* boat1 = createBoat("Yamaha", "190 FSH", 2016, "sdluaw43rjearfaod", "inboard");
	
	FILE* fp = fopen("out.txt", "a"); 
	printCarInfo(fp, car1); 
	printTruckInfo(fp, truck1); 
	printBoatInfo(fp, boat1); 
		

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



//converts vehicle type from string form to enum form so we can use in switch statement
Vehicle convertToEnum(char* str){

	Vehicle vehicleType;
	
	if(strcmp(str, "car") == 0){
		vehicleType = car; 
	}else if(strcmp(str, "truck") == 0){
		vehicleType = truck; 
	}else if(strcmp(str, "boat") == 0){
		vehicleType = boat;
	}else{
		printf("error: invalid vehicle type found in file. Allowed types: car, truck, boat. Exiting..\n");
	       	exit(1); 	
	}

	return vehicleType;

}


//print functions used for appending vehicle info @ end of file; file must be opened in append mode 
void printCarInfo(FILE* fp, Car* car){
	fprintf(fp, "%d %s %s\n", car->year, car->make, car->model); 
	fprintf(fp, "VIN: %s\n", car->VIN); 
	fprintf(fp, "Doors: %d\n", car->numDoors); 
	fprintf(fp, "Rear Configuration: %s\n\n", car->rearConfig); 
	
}


void printTruckInfo(FILE* fp, Truck* truck){
	fprintf(fp, "%d %s %s\n", truck->year, truck->make, truck->model); 
	fprintf(fp, "VIN: %s\n", truck->VIN); 
	fprintf(fp, "Doors: %d\n", truck->numDoors); 
	fprintf(fp, "Max Towing Capacity: %f\n\n", truck->towingCapacity); 
	
}

void printBoatInfo(FILE* fp, Boat* boat){
	fprintf(fp, "%d %s %s\n", boat->year, boat->make, boat->model); 
	fprintf(fp, "VIN: %s\n", boat->VIN); 
	fprintf(fp, "Motor: %s\n\n", boat->motorType);
	
}
