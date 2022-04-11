 #ifndef STDIO_H
 #define STDIO_H
 #include <stdio.h>
 #endif



FILE* fopen_errorChecked(char* fileName, char* mode);

char** readFile(FILE* input, char** stringArray, int* outputArrSize);

int resizeString(char* str);

void writeFile(FILE* output, char** sortedStringArray, int size);

void freeStringArray(char** stringArray, int arraySize);
