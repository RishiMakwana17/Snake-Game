#include "fileIO.h"

char** fileIO(int* row, int* col, char* fileName, int player[2], int enemy[2], int finish[2])
{   
    int i, j;
    int metaAmount, map_row, map_col, readData;
    FILE* file = NULL;
    char** map;
    char** mapSymbols = NULL;
    
    file = fopen(fileName, "r"); /*Opens the file*/

    if(file == NULL) /*Checks to see if the file contains data*/
    {
        perror("Error, file could not be opened!"); 
        fclose(file);/*Closes file if empty*/
    }
    else if(ferror(file)) /*checks to see if error in the file*/
    {
        perror("Error in the file!");
        fclose(file); /*Closes the file if error has occured*/
    }
    else
    {   
        readData = fscanf(file, "%d %d %d", &metaAmount, &map_row, &map_col);  /*Reads the first line and stores the object amount, rows and columns*/

        *col = map_col; /*Assign contents in map_row and map_col to variables row and column for later use in main*/
        *row = map_row;

        map = (char**)malloc(sizeof(char*) * map_row); /*Memory allocation for the map*/
        for (i = 0;i < map_row;i++)
        {
            map[i] = (char*)malloc(sizeof(char) * map_col);
        }
        
        for(i = 0; i < map_row; i++)
        {
            for(j = 0;j < map_col; j++)
            {
                map[i][j] = ' '; /*Assigns empty spaces throughout the map, prior to allocating objects*/
            }
        }
    
        mapSymbols = symbolAllocation(file, metaAmount, readData, map, player, enemy, finish); 
    
        fclose(file); /*Closes file*/
    
    }
    file = NULL;
    
    return mapSymbols;
 }   

/*This method allocates a symbol to each number e.g. 0 is ^, 1 is ~*/
char** symbolAllocation(FILE* file, int metaAmount, int readData, char** map, int player[2], int enemy[2], int finish[2])
{  
    int row, col, character, i;
    for(i = 0;i < metaAmount; i++)  /* Iterate through data to get map array index*/
    {
        readData = fscanf(file, "%d %d %d", &row, &col, &character); /*Assign the following lines in the text file (rows, columns, objects) to a variable*/
        if(character == 0) /*If the character is 0, then assign that to the player - ^*/
        {
            map[row][col] = '^';
            player[0] = row;
            player[1] = col;
        }
        else if(character == 1) /*If the character is 1, then assign that to the snake - ~*/
        {
            map[row][col] = '~';
            enemy[0] = row;
            enemy[1] = col;
        }
        else if(character == 2) /*If the character is 2, then assign that to the finish - x*/
        {
            map[row][col] = 'x';
            finish[0] = row;
            finish[1] = col;
        }
        else if(character == 3) /*If the character is 3, then assign that to the walls - o*/
        {
            map[row][col] = 'o';
        }
    }
    return map; /*Return the map now that the symbols have been allocated and set*/
}

