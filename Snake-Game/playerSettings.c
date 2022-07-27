#include "playerSettings.h"

LinkedList* userPositioning(LinkedList* movement, int playerPosition[2], int enemy[2], char command, char** maze)
{
    int userMovement[2];
    int newEnemyPosition[2];
    int* data = (int*)malloc(sizeof(int)*5);
         
    int rowPositioning = playerPosition[0] - enemy[0]; /*difference between players row and the enemy row*/
    int columnPositioning = playerPosition[1] - enemy[1]; /*different between players column and enemy column*/
             
    data = (void*)data;    
    playerMovement(userMovement, playerPosition, command); /*provides settings for the user to move around*/
    snakeSettings(command, newEnemyPosition, enemy, rowPositioning, columnPositioning); /*settings of the snake*/
 
       
   if(maze[newEnemyPosition[0]][newEnemyPosition[1]] == ' ' || maze[newEnemyPosition[0]][newEnemyPosition[1]] == 'v' || maze[newEnemyPosition[0]][newEnemyPosition[1]] == '^' || maze[newEnemyPosition[0]][newEnemyPosition[1]] == '<' || maze[newEnemyPosition[0]][newEnemyPosition[1]] == '>') /*Snake can proceed forward if any of these symbols are in front of it, this ensures that the snake wont go through the goal or walls*/
    {
       enemy[0] = newEnemyPosition[0];
       enemy[1] = newEnemyPosition[1];
    }
    
    if((maze[userMovement[0]][userMovement[1]] == 'x') || (maze[userMovement[0]][userMovement[1]] == ' ')) /*The user can proceed forward if any of these symbols are in front of it, similar to the snake, it's to ensure that the player doesnt go through the walls*/
    {
        playerPosition[0] = userMovement[0]; 
        playerPosition[1] = userMovement[1];
    }   
    
    data[0]= playerPosition[0]; /*Stores the current row of the player*/
    data[1]= playerPosition[1]; /*Stores the current column of the player*/
    data[2] = enemy[0]; /*Stores the current row of the snake*/
    data[3] = enemy[1]; /*Stores the current column of the snake*/
    data[4] = command;  /*Stores the command that the user enters*/
    
    insertFirst(movement, data); /*Stores in the linked list*/
    return movement;
}

void symbolIteration(LinkedList* moves, char command, char** maze)
{
    int* coordinates;
    int playerCommand;
    coordinates = (int*)moves->head->data; /*stores the head of list in coordinates*/
    playerCommand = coordinates[4]; 
    maze[coordinates[2]][coordinates[3]] = '~'; /*put the snake on the maze*/
    
    if(playerCommand == 'a') /*If the user enters any one of these letters (a,w,d,s), then the output will be one of the arrow symbols that is assigned to the specific direction that it is facing*/
    {
         maze[coordinates[0]][coordinates[1]] = '<';
    }
    else if (playerCommand == 'w')
    {
        maze[coordinates[0]][coordinates[1]] = '^';
    }
    else if(playerCommand == 'd')
    {
        maze[coordinates[0]][coordinates[1]] = '>';
    }
    else if(playerCommand == 's')
    {
        maze[coordinates[0]][coordinates[1]] = 'v';
    }
    system("clear");   /*Clears the screen for the next iteration*/
}

void playerMovement(int* storeMovement, int position[2], int user)
{
    if(user == 'w')  /*if the user enters w, player coordinates go up*/
    {   
        storeMovement[0] = position[0]-1; 
        storeMovement[1] = position[1];
    }
    else if(user == 'd') /*if the user enters d, the player coordinates go right*/
    {
        storeMovement[0] = position[0];
        storeMovement[1] = position[1]+1;
    }
    else if(user == 'a') /*if the user enters a,the player coordinates go left*/
    {
        storeMovement[0] = position[0];
        storeMovement[1] = position[1]-1;
    }
    else if(user == 's') /*if the user enters s, the the player coordinates go down*/
    {
        storeMovement[0] = position[0]+1;
        storeMovement[1] = position[1];
    }
}

    
/*This function removes the previous moves made by the user and stores it in an array to be returned to the main*/
LinkedList* undoFeature(LinkedList* playerMovement, int player[2], int enemy[2],int finish[2], char** maze, int row, int col, char* inputFile)
{
    int* coordinates;
    removeFirst(playerMovement); /*Removes the last move made by the user*/
    coordinates = (int*)playerMovement->head->data; /*The start of the linked list is the previous second move made by the user before the last one was made stored in coordinates*/
        
    player[0] = coordinates[0]; /*store the previous data of the players row*/
    player[1] = coordinates[1]; /*store the previous data of the players column*/
    enemy[0] = coordinates[2]; /*store the previous data of the snakes row*/
    enemy[1] = coordinates[3]; /*store the previous data of the snakes column*/
        
        
    return playerMovement;
}



