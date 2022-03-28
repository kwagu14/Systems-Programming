#ifndef UTILS_H
#define UTILS_H
#include "utils.h"
#endif

//remove the newline character at the end of the input
int removeEndingNewline(char string[]){
	string[strcspn(string, "\n")] = '\0';
	int newSize = strlen(string);
	return newSize; 
}


//get an integer from the input file
int grabInteger(FILE* inFile){

	char strBuffer[50];
	fgets(strBuffer, 50, inFile);
	removeEndingNewline(strBuffer);
       	int integerValue = atoi(strBuffer);
	return integerValue; 	

}


float grabFloat(FILE* inFile){

	char strBuffer[50];
        fgets(strBuffer, 50, inFile);
        removeEndingNewline(strBuffer);
	float floatValue = atof(strBuffer);
        return floatValue; 

}


char* grabString(FILE* inFile, char* stringBuffer){

        fgets(stringBuffer, 50, inFile);
        removeEndingNewline(stringBuffer);
	return stringBuffer;

}
