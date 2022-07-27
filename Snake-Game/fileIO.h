#ifndef FILEIO
#define FILEIO
#include <stdlib.h>
#include <stdio.h>

char** fileIO(int* row, int* col, char* fileName, int player[2], int enemy[2], int finish[2]);
char** symbolAllocation(FILE* file, int metaAmount, int readData, char** map,int player[2], int enemy[2], int finish[2]);

#endif
