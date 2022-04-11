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



void bubbleSort(char** array, int arraySize){

	for(int i = 0; i < arraySize; i++){
		for(int j = i + 1; j < arraySize; j++){ 
			if(*array[j] == '\0'){
				break; 
			}else if(strcmp(array[i], array[j]) > 0){
				//otherwise swap the element as normal
				swap(array[i], array[j]); 
			}
		}
	
	}

}




void swap(char *elm1, char *elm2){

	//figure out what size to make temp
	int sizeElm1 = strlen(elm1); 
	
	//create a temporary array to store one of the strings
	char* temp = malloc(sizeElm1 * sizeof(char)); 
	initializeCharArray(temp, sizeElm1);
	//use strcpy to copy the strings into their respective places
	strcpy(temp, elm1);
	strcpy(elm1, elm2);
	strcpy(elm2, temp);

}




int removeNewline(char* string){
	string[strcspn(string, "\n")] = '\0';
	int newSize = strlen(string);
	return newSize; 
}




void initializeStringArray(char** array, int start, int end){
	//assume end is the last index of the overall array; 
	for(int i = start; i <= end; i++){
		array[i] = NULL; 
	}

}




void initializeCharArray(char* array, int arrSize){
 	
	for(int i = 0; i < arrSize - 1; i++){
		array[i] = 0;
	}
	array[arrSize - 1] = '\0'; 

}



void printStringArray(char** array, int currentSize){

	for(int i = 0; i < currentSize; i++){
		printf("%s\t", array[i]); //otherwise print the array element
		printf("\n");
	}

	printf("------------------------------------------\n"); //print divider
}

