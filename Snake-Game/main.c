#include "main.h"

int main(int argc, char* argv[])
{
    char* inputFile;
    int* player;
    int* enemy;
    int* finish;
    int row;
    int col, i;
    char** maze;
    char user;     
        
    disableBuffer();
    if(argc != 2) /*If the parameters arent 2, an error message will print to inform the player*/
    {
        printf("Please enter correct parameters!\n");
    }
    else if(argc == 2) /*Checks the parameters to ensure they're correct*/
    {   
        LinkedList* playerMovement = makeList(); /*Creates the linked list*/
        player =(int*)malloc(sizeof(int)*2); /*Allocates memory to arrays*/
        finish =(int*)malloc(sizeof(int)*2);
        enemy =(int*)malloc(sizeof(int)*2);

        inputFile = argv[1];
        maze = fileIO(&row, &col, inputFile, player, enemy, finish);

        do /*Loop through the program to determine if the player has either been eaten by the snake or reached the finish*/
        {
            border(maze,row,col); /*Prints the border for the maze*/
            printMaze(row, col, maze); /*Prints the maze*/
            /*userInput(playerMovement, player, enemy, finish, maze, row, col, inputFile); Takes the users input - a, w, s, d*/
    
            scanf(" %c", &user); /*Takes the user input*/
            if(user == 'a' || user == 'w' || user == 's' || user == 'd')
            {
                userPositioning(playerMovement, player, enemy, user, maze); /*By using the keys (a,w,s,d), it allows the player(^) to move around the map with the s
ake attempting to intercept the player reaching the goal*/
                symbolIteration(playerMovement, user, maze); /*This function prints out the symbols (<,v,^,>) for each time the user makes a move*/
            }
            else if(user == 'u')
            {
                if(playerMovement->size == 1) /*If the player is one move away from the finish, the head of the list will be removed and it will print the original maze*/
                {
                    removeFirst(playerMovement);
                    maze = fileIO(&row, &col, inputFile, player, enemy, finish);
                }
                else if(playerMovement->size == 0) /*prints the original maze*/
                {
                    maze = fileIO(&row, &col, inputFile, player, enemy, finish);
                }
                else  /*If the user has made more than one move, display the previous steps they took*/
                {
                    playerMovement = undoFeature(playerMovement, player, enemy, finish, maze, row, col, inputFile); /*Provides the undo feature that allows the user to view previous steps*/
                    symbolIteration(playerMovement, user, maze); /*This function prints out the symbols (<,v,^,>) for each time the user makes a move*/
                }
            }
            else
            {   
                if(playerMovement->size >= 1)
                {
                    printf("Please enter a valid command!\n");
                    symbolIteration(playerMovement, user, maze); /*This function prints out the symbols (<,v,^,>) for each time the user makes a move*/
                }
                else if(playerMovement->size == 0)
                {   
                    printf("Please enter a valid command!\n");
                    maze = fileIO(&row, &col, inputFile, player, enemy, finish);
                }
            }
        
            system("clear");           
        
        }while((player[0] != finish[0] || player[1] != finish[1]) && (enemy[0] != player[0] || enemy[1] != player[1]));
        
        enableBuffer();
        
        if(player[0] == finish[0] && player[1] == finish[1]) /*If the players (^) coordinates are the same as the finish (x), then a winners message will display*/
        {
            printMaze(row, col, maze);
            printf("Congratulations! You have Won!\n");
        }
        else if(enemy[0] == player[0] && enemy[1] == player[1]) /*If the coordinates of the player(^) is the same as the snake(~) then, losers message is displayed*/ 
        {
            printMaze(row, col, maze);
            printf("Oh no! You have been bitten by the snake!\n");
        }
    
        for(i = 0; i < row; i++)
        {
            free(maze[i]);
        }
        /*Free*/
        free(maze);
        free(player);
        free(finish);
        free(enemy);
        freeLinkedList(playerMovement, &freeNode);
        
        inputFile = NULL;
        maze = NULL;
        enemy = NULL;
        player = NULL;
        playerMovement = NULL;
    }
    return 0;
}


void printMaze(int row, int col, char** maze)
{
    int i,j;
    for(i = 0; i < row; i++)
    {
        for( j =0; j < col; j++)
        {
            printf("%c", maze[i][j]); /*Prints the maze*/
            while(maze[i][j]== 'v' || maze[i][j]== '<' || maze[i][j]== '>' || maze[i][j]== '^' || maze[i][j] == '~')
            {
                maze[i][j] = ' '; /*While loop removes previous moves made by the user, else it will print every step they've taken*/
            }
        }
        printf("\n");
    }
}


void border (char** maze, int row, int col)
{
/* This function creates a border around the map to ensure the user can't go out of the map*/
    int i,j;
    for(i = 0; i < row;i++)
    {
        for(j = 0; j < col;j++)
        {
            if(((i == row - 1) && (j == 0)) || ((i == 0) && (j == 0)))
            {
                maze[i][j] = '#'; /*edge on left hand side*/
            }
            else if(((i == 0) && (j == col - 1)) || ((i == row - 1) & (j == col - 1)))
            {
                maze[i][j] = '#'; /*edge on right hand sides*/
            }
            else if((((i == row - 1)) && (j > 0 && col - 1)) || ((i == 0) && (j > 0 && j < col - 1)))
            {
                maze[i][j] = '-'; /*upper and lower border*/
            }
            else if(((i > 0 && i < row - 1) && (j == 0)) || ((i > 0 && i < row - 1) && (j == col - 1)))
            {
                maze[i][j] = '|'; /*left and right border*/
            }
        }
    }
}

