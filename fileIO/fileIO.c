#include "fileIO.h"



int main(){
	
	FILE* input; 
	FILE* output; 

	//open the input and output file
	input = fopen("TestInput.txt", "r"); 
	if(input == NULL){
		printf("An error occurred when attempting to open the input file. Exiting."); 
		exit(1);
	}
	output = fopen("out.txt", "a");
	if(output == NULL){
		printf("An error occurred when attempting to open the output file. Exiting."); 
		exit(1);
	}
	//format and write contents into output
       	writeFile(input, output); 

	//close the two files
	fclose(input); 
	fclose(output);	
		

	return 0;
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


void writeFile(FILE* input, FILE* output){
	
	char vehicleStr[50];
	while(fgets(vehicleStr, 50, input) != NULL && strcmp(vehicleStr, "\n") != 0){
		
		//strip newline character
		vehicleStr[strcspn(vehicleStr, "\n")] = '\0'; 
		Vehicle vehicleType = convertToEnum(vehicleStr); 	

		switch(vehicleType){
			case 0:{
				char makeBuf[50]; char modelBuf[50]; char yearBuf[50];
				char numDoorsBuf[50]; char VINBuf[50]; char rearConfigBuf[50];
				
				//grab the values
				fgets(makeBuf, 50, input);
				fgets(modelBuf, 50, input); 
				fgets(yearBuf, 50, input);
				fgets(VINBuf, 50, input); 
				fgets(numDoorsBuf, 50, input);
				fgets(rearConfigBuf, 50, input);
				
				//strip the newline chars off the strings so they're formatted correctly
				makeBuf[strcspn(makeBuf, "\n")] = '\0';
				modelBuf[strcspn(modelBuf, "\n")] = '\0';
				VINBuf[strcspn(VINBuf, "\n")] = '\0';
				rearConfigBuf[strcspn(rearConfigBuf, "\n")] = '\0';

				//these don't need to have newline stripped, but they need to be converted to int
		       		int year = atoi(yearBuf);
				int numDoors = atoi(numDoorsBuf); 

				Car* car = createCar(makeBuf, modelBuf, year, VINBuf, numDoors, rearConfigBuf);
				printCarInfo(output, car);
				freeCar(car);
			}		
				break; 
			case 1:{
				char makeBuf[50]; char modelBuf[50]; char yearBuf[50];
				char numDoorsBuf[50]; char VINBuf[50]; char towingCapacityBuf[50];
				
				//grab the values
				fgets(makeBuf, 50, input);
				fgets(modelBuf, 50, input); 
				fgets(yearBuf, 50, input);
				fgets(VINBuf, 50, input); 
				fgets(numDoorsBuf, 50, input);
				fgets(towingCapacityBuf, 50, input);
				
				//strip the newline chars off the strings so they're formatted correctly
				makeBuf[strcspn(makeBuf, "\n")] = '\0';
				modelBuf[strcspn(modelBuf, "\n")] = '\0';
				VINBuf[strcspn(VINBuf, "\n")] = '\0';
		
				//these don't need to have newline stripped, but they need to be converted to int
		       		int year = atoi(yearBuf);
				int numDoors = atoi(numDoorsBuf);
				double towingCapacity = atof(towingCapacityBuf); 

				Truck* truck = createTruck(makeBuf, modelBuf, year, VINBuf, numDoors, towingCapacity);
				printTruckInfo(output, truck);
				freeTruck(truck);
			}		
				break; 
			case 2:{
				char makeBuf[50]; char modelBuf[50]; char yearBuf[50];
				char VINBuf[50]; char motorBuf[50];
				
				//grab the values
				fgets(makeBuf, 50, input);
				fgets(modelBuf, 50, input); 
				fgets(yearBuf, 50, input);
				fgets(VINBuf, 50, input); 
				fgets(motorBuf, 50, input);
				
				//strip the newline chars off the strings so they're formatted correctly
				makeBuf[strcspn(makeBuf, "\n")] = '\0';
				modelBuf[strcspn(modelBuf, "\n")] = '\0';
				VINBuf[strcspn(VINBuf, "\n")] = '\0';
				motorBuf[strcspn(motorBuf, "\n")] = '\0';
				//these don't need to have newline stripped, but they need to be converted to int
		       		int year = atoi(yearBuf);

				Boat* boat = createBoat(makeBuf, modelBuf, year, VINBuf, motorBuf);
				printBoatInfo(output, boat);
				freeBoat(boat);
			}		
				break; 
			default: 
				printf("Error: could not extract a valid type from the read operation\n"); 
				break; 
			
		}
	}

}



//STRUCT CREATORS AND DEALLOCATORS
//(not necessary for assignment, but these were kept anyawy in case program is extended to use data structures instead of files in the future)

//deallocators for the structs
void freeCar(Car* car){
	//deallocate the string arrays
	free(car -> make);
	free(car -> model);
	free(car -> VIN);
	free(car -> rearConfig);
	//deallocate the struct
	free(car);
}

void freeTruck(Truck* truck){
	free(truck -> make);
	free(truck -> model);
	free(truck -> VIN); 
	free(truck);
}

void freeBoat(Boat* boat){
	free(boat -> make);
	free(boat -> model); 
	free(boat -> VIN); 
	free(boat -> motorType); 
	free(boat); 
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
	return newCar;

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
	return newTruck;
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

	return newBoat;

}

