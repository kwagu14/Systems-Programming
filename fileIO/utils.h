
#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

int removeEndingNewline(char string[]);

int grabInteger(FILE* inFile);

float grabFloat(FILE* inFile);

char* grabString(FILE* inFile, char* stringBuffer);
