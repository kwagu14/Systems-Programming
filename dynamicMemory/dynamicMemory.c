#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef UTILS_H
#define UTILS_H
#include "utils.h"
#endif

#ifndef DYNAMICMEMORY_H
#define DYNAMICMEMORY_H
#include "dynamicMemory.h"
#endif




int main(){  
	
	
	//file pointers
	FILE* input;
	FILE* output;
	
	//holds the current string array size
	int arraySize;
	
	//malloc an array of char pointers that has an initial length of 10
	char** stringsArray = (char**) malloc(10 * sizeof(char*)); 
	
	//malloc each string inside of the string array
	for(int i = 0; i<10; i++){
		//create a string that can hold 100 elements
		stringsArray[i] = (char*) malloc(101 * sizeof(char));
		//initialize each element to an empty string
	       	strcpy(stringsArray[i], "");
	}
	
	//open the input and output file
	input = fopen_errorChecked("TestInput.txt", "r");
	output = fopen_errorChecked("out.txt", "a");
	
	//read the strings into the strings array, growing it as needed
	stringsArray = readFile(input, stringsArray, &arraySize);
	
	//sort the array
	bubbleSort(stringsArray, arraySize); 

	//write the sorted strings to an output file
	writeFile(output, stringsArray, arraySize); 
	
	//after write, free the string array
	freeStringArray(stringsArray, arraySize);
	
	//close the files
	fclose(input);
	fclose(output);
	

	return 0; 

}



FILE* fopen_errorChecked(char* fileName, char* mode){
	
	FILE* fp = fopen(fileName, mode);
	
	if(fp == NULL){
		printf("An error occurred when attempting to open the output file. Exiting.");
		exit(1);
	}
	return fp;

}



//read file line by line; return size of array
char** readFile(FILE* input, char** stringArray, int* outputArrSize){

	//create a buffer for currentString	
	char* currentString = (char*) malloc(101 * sizeof(char));
	//counts how many strings have been processed
       	int stringsProcessed = 0;
       //previous array size	
	int prevSize = 0; 
	//current array size
	int currentStringArraySize = 10; 
	
	//whle we haven't reached the end of the file
	while(fgets(currentString, 100, input) != NULL){  

		//strip the newline character
		removeNewline(currentString); 	
		//resize the string array
		resizeString(currentString);  
		//copy the string into the strings array 
		strcpy(stringArray[stringsProcessed], currentString);
		//increment the number of strings proccessed            
                ++stringsProcessed;

		if(stringsProcessed >= currentStringArraySize){
                        //save the previous size
                        prevSize = currentStringArraySize;
                        currentStringArraySize += 10;
                        //resize the array
                        stringArray = (char**) realloc(stringArray, currentStringArraySize * sizeof(char*));
                        //malloc the new strings in the array
                        for(int i = prevSize; i < currentStringArraySize; i++){
                                stringArray[i] = (char*) malloc(101 * sizeof(char));
				strcpy(stringArray[i], "");
                        } 
                       
                }
	
	}
	*outputArrSize = currentStringArraySize;
	return stringArray;
}



int resizeString(char* str){
	
	int counter = 0;
       	char currentChar = str[0];	
	while(currentChar != '\0'){
		++counter; 
		currentChar = str[counter];
	}
	//account for the null terminator
	++counter; 
	//resize the string
	str = realloc(str, counter * sizeof(char));
       	//return the size	
	return counter; 

}



char** resizeStringArray(char** stringArray, int currentSize, int* outputSize){

	int counter = 0; 
	char* currentString = stringArray[0];
	while(counter < currentSize -1 && strcmp(currentString, "") != 0){
		++counter; 
		currentString = stringArray[counter];

	}
	stringArray = realloc(stringArray, counter * sizeof(char*)); 
	return stringArray; 

}



void writeFile(FILE* output, char** sortedStringArray, int size){
	
	//print each string to the output file
	for(int i = 0; i < size; i++){
		if(strcmp(sortedStringArray[i], "") == 0){
			break; //we reached the end of the occupied entries in the array
		}
		fprintf(output, "%s\n", sortedStringArray[i]);
	}

}


void freeStringArray(char** stringArray, int arraySize){
	
	//first free all of the strings
	for(int i = 0; i < arraySize; i++){
		free(stringArray[i]);
	}
	free(stringArray);
	

}
