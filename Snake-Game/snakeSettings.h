#ifndef UNDOFEATURE
#define UNDOFEATURE
#include "LinkedList.h"
#include "fileIO.h"
#include "playerSettings.h"

void snakeSettings(int user, int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning);
void userUp(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning);
void userRight(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning);
void userLeft(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning);
void userDown(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning);

#endif
