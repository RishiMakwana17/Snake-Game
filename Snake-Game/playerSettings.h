#ifndef PLAYERMOVEMENT
#define PLAYERMOVEMENT

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "snakeSettings.h"

LinkedList* userPositioning(LinkedList* moves, int playerPosition[2], int enemy[2], char command, char** maze);
void symbolIteration(LinkedList* moves, char command, char** maze);
void playerMovement(int* storeMovement, int position[2], int user);
LinkedList* undoFeature(LinkedList* playerMovement, int player[2], int enemy[2],int finish[2], char** maze, int row, int col, char* inputFile);

#endif
