#include "snakeSettings.h"

void snakeSettings(int user, int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning)
{
    if(user == 'w')
    {
        userUp(newEnemyPosition, enemy, rowPositioning, columnPositioning);
    }
    else if(user == 'd')
    {
        userRight(newEnemyPosition, enemy, rowPositioning, columnPositioning);    
    }
    else if(user == 'a')
    {
       userLeft(newEnemyPosition, enemy, rowPositioning, columnPositioning);
    }
    else if(user == 's')
    {
        userDown(newEnemyPosition, enemy, rowPositioning, columnPositioning);
    }
}

void userUp(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning)
{
    if(rowPositioning > 2) /*If the distance between the rows is greater than two, while the player is below the enemy*/
    {
        newEnemyPosition[0] = enemy[0] + 1; /*snake goes down*/
        newEnemyPosition[1] = enemy[1];
    }
    else if(rowPositioning < 2 && rowPositioning > 0) /*player is below enemy*/
    {
        if(columnPositioning < 0) /*if player is to the left, go left*/
        {
            newEnemyPosition[0] = enemy[0];
            newEnemyPosition[1] = enemy[1]-1;
        }
        else if(columnPositioning > 0) /*if player is to the right, go right*/
        {
            newEnemyPosition[0] = enemy[0];
            newEnemyPosition[1] = enemy[1]+1;
        }
    }
    else if(rowPositioning < 0) /*player is above enemy*/
    {
        if(columnPositioning < 0) /*if the player is above the enemy and to the left, the enemy should go left*/
        {
            newEnemyPosition[0] = enemy[0];
            newEnemyPosition[1] = enemy[1]-1;
        }
        else if(columnPositioning > 0) /*if the player is above the enemy and to the right, the enemy should go right*/
        {
            newEnemyPosition[0] = enemy[0];
            newEnemyPosition[1] = enemy[1]+1;
        }
    }
    else if(rowPositioning == 0) /*if the player and enemy are on the same row*/
    {
        if(columnPositioning > 0) /*if player is to the left, go left*/
        {
            newEnemyPosition[0] = enemy[0]-1;
            newEnemyPosition[1] = enemy[1];
        }
        else if(columnPositioning < 0) /*if player is to the right, go right*/
        {
            newEnemyPosition[0] = enemy[0]-1;
            newEnemyPosition[1] = enemy[1];
        }
    }
    if(columnPositioning == 0) /*if they are on the same column line*/
    {
        if(rowPositioning > 1) /*if the player is below the enemy, enemy should go down*/
        {
            newEnemyPosition[0] = enemy[0]+1; 
            newEnemyPosition[1] = enemy[1];
        }
        else if(rowPositioning < 1) /*If the player is above the enemy, go up*/ 
        {
            newEnemyPosition[0] = enemy[0]-1;
            newEnemyPosition[1] = enemy[1];
        }
        else if(rowPositioning == 1) /*if the difference between the rows is only one, then the enemy will remain in the same space*/
        {
            newEnemyPosition[0] = enemy[0];
            newEnemyPosition[1] = enemy[1];
        }
    }
}

void userRight(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning)
{
   if(rowPositioning > 0) /*player is below enemy*/
   {
      if(columnPositioning < 0) /*if player is to the left of the enemy, go down*/
       {
           newEnemyPosition[0] = enemy[0]+1;
           newEnemyPosition[1] = enemy[1];
       }   
       else if(columnPositioning > 0) /*if player is to the right of the enemy, go right*/
       {
           newEnemyPosition[0] = enemy[0];
           newEnemyPosition[1] = enemy[1]+1;
       }   
   }   
   else if(rowPositioning < 0) /*player is above enemy*/
   {
       if(columnPositioning < 0) /*if player is to the left of the enemy, go down*/
       {
           newEnemyPosition[0] = enemy[0]-1;
           newEnemyPosition[1] = enemy[1];
       }   
       else if(columnPositioning > 0) /*if player is to the right of the enemy, go down*/
       {
           newEnemyPosition[0] = enemy[0]-1;
           newEnemyPosition[1] = enemy[1];
       }   
       
   }   
   else if(rowPositioning == 0 && columnPositioning > 1) /*if the enemy and player are on the same line, and the player is right of the enemy, enemy goes right*/
   {
       newEnemyPosition[0] = enemy[0];
       newEnemyPosition[1] = enemy[1]+1;
   }   
   else if(rowPositioning == 0 && columnPositioning < 1) /*if the enemy and player are on the same line, and the player is right of the enemy, enemy goes left*/
   {
       newEnemyPosition[0] = enemy[0];
       newEnemyPosition[1] = enemy[1]-1;
   }   
   else if(rowPositioning == 0 && columnPositioning == 1) /*if enemy and player are on the same line, and the player is one column away, stay still*/
   {
       newEnemyPosition[0] = enemy[0];
       newEnemyPosition[1] = enemy[1];
   }   
}

void userLeft(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning)
{
   if(rowPositioning > 0) /* if player is below the enemy*/
   {
       if(columnPositioning < 0) /*player is to the left of the enemy*/
       {
           newEnemyPosition[0] = enemy[0];
           newEnemyPosition[1] = enemy[1]-1;
       }   
       else if(columnPositioning > 0) /*if player is to the right of enemy*/
       {
           newEnemyPosition[0] = enemy[0]+1;
           newEnemyPosition[1] = enemy[1];
       }   
       
   }   
   else if(rowPositioning < 0) /*player is above the enemy, enemy goes right*/
   {
       if(columnPositioning < 0) /*if the player is to the left of the enemy, the enemy will also go left*/
       {
           newEnemyPosition[0] = enemy[0]-1;
           newEnemyPosition[1] = enemy[1];
       }
       else if(columnPositioning > 0)
       {
           newEnemyPosition[0] = enemy[0]-1;
           newEnemyPosition[1] = enemy[1];
       }
   }
   else if(rowPositioning == 0 && columnPositioning < 1) /*if the player and enemy on the same row, and columns between them have difference of one & if the player is to the left, enemy left*/
   {
       newEnemyPosition[0] = enemy[0];
       newEnemyPosition[1] = enemy[1]-1;
   }
   else if(rowPositioning == 0 && columnPositioning > 1) /*if the player and enemy on the same row, and columns between them have difference of one & if the player is right, enemy right*/
   {
       newEnemyPosition[0] = enemy[0];
       newEnemyPosition[1] = enemy[1]+1;
   }
   else if(rowPositioning == 0 && columnPositioning == 1) /*If the player and the enemy are on the same row, but different columns, then the enemy will remain still*/
   {
       newEnemyPosition[0] = enemy[0];
       newEnemyPosition[1] = enemy[1];
   }
}

void userDown(int newEnemyPosition[2], int enemy[2], int rowPositioning, int columnPositioning)
{
   if(rowPositioning > 2) /*player two rows below the enemy*/
   {
       newEnemyPosition[0] = enemy[0] + 1; /*enemy goes down*/
       newEnemyPosition[1] = enemy[1];
   }
   else if(rowPositioning < 2 && rowPositioning > 0) /*If the player is two rows above the enemy and greater than 0 rows below the enemy*/
   {
       if(columnPositioning < 0) /*if player is to the left, go left*/
       {
           newEnemyPosition[0] = enemy[0];
           newEnemyPosition[1] = enemy[1]-1;
       }
       else if(columnPositioning > 0) /*if player is to the right, go right*/
       {
           newEnemyPosition[0] = enemy[0];
           newEnemyPosition[1] = enemy[1]+1;
       }
   }
   else if(rowPositioning < 0) /*player is above the enemy*/
   {
       if(columnPositioning < 0) /*If player is to the left, go left*/
       {
           newEnemyPosition[0] = enemy[0];
           newEnemyPosition[1] = enemy[1]-1;
       }
       else if(columnPositioning > 0) /*If player is to the right, go right*/
       {
           newEnemyPosition[0] = enemy[0];
           newEnemyPosition[1] = enemy[1]+1;
       }
   }
   else if(columnPositioning == 0) /*If the player and enemy are on the same column*/
   {
       if(rowPositioning > 1) /*If player is more than one row below enemy*/
       {
           newEnemyPosition[0] = enemy[0]+1;
           newEnemyPosition[1] = enemy[1];
       }
       else if(rowPositioning < 1) /*If player is more than one row above enemy*/
       {
           newEnemyPosition[0] = enemy[0]-1;
           newEnemyPosition[1] = enemy[1];
       }
       else if(rowPositioning == 1) /*If the player is one distance away from the enemy*/
       {
           newEnemyPosition[0] = enemy[0];
           newEnemyPosition[1] = enemy[1];
       }
   }
}  
