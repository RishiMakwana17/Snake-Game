#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "playerSettings.h"
#include "fileIO.h"
#include "LinkedList.h"
#include "terminal.h"
#include "snakeSettings.h"

void printMaze(int row, int col, char** maze);
void border (char** maze, int row, int col);

#endif
