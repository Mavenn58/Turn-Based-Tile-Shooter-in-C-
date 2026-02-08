/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
Ching,Nicolas Miguel T. - 12205702 - S23C
******************************************************************************/

/*   
    Description:      This program is designed to execute a turn based tile shooter game.
    Programmed by:    Nicolas Miguel T. Ching   S23C
    Last modified:    December, 2, 2022
    Version:          Version 7.0
    Acknowledgements: W3Schools.com 
*/

/*Preprocessor Directives*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Function Implementation*/

/*The function displayStartMenu is used to display the starting menu of the game. Function has no parameters needed because it only
utilizes the use of printf function.
@return: returns nothing since it's a void function*/

void displayStartMenu()
{
    printf("-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x-=x=-=x=\n"
    "           Turn Based Tile Shooter Game\n           By: Nicolas Miguel T. Ching\n"
    "           Press [1] to START\n           Press [2] to STOP\n"
    "------------------------------------------------\n");
}

/*The function printBoard displays the game board as well as the initial position of the enemy.
@param rStart is the variable for rows for game board
@param cStart is the variable for columns for game board
@param nEnemy1,2,3 are variables for the enemies
@param nEnemy1r,2r,3r are variables for enemy position in rows
Pre-Condition: 
@return: returns nothing since it's a void function*/

void printBoard(int rStart, int cStart, int nEnemy1, int nEnemy1r, int nEnemy2, int nEnemy2r, int nEnemy3, int nEnemy3r)
{
    printf("---------\n");
    for (rStart=0; rStart < 5; rStart++){ // The loop prints rows of the game board. 
        for (cStart=0; cStart<4; cStart++){ // Nested for loop prints each column of the game board.
            if ((nEnemy1r-1 == rStart && nEnemy1-1 == cStart)||(nEnemy2r-1 == rStart && nEnemy2-1==cStart)||(nEnemy3r-1 == rStart && nEnemy3-1==cStart)){
                printf("|X");
            }
            else{
                printf("| ");
            }
        }
        printf("|\n");
    }
    printf("---------\n");
}

/*The function printPlayer displays the game board as well as the initial position of the player.
@param nPlayer is the player's variable
@param pRStart are the rows for the player board
@param pCStart are the columns for the player board
Pre-Condition: all parameter values are non negative
@return: returns nothing since it's a void function*/

void printPlayer(int nPlayer, int pRStart, int pCStart)
{
    printf("---------\n");
    for (pRStart=0; pRStart<1; pRStart++){// loop for player board row
        for(pCStart=0; pCStart<4; pCStart++){// loop for player board columns
            if (nPlayer -1 == pCStart){
                printf("|P");
            }
            else{
                printf("| ");
            }
        }
        printf("|\n");
    }
    printf("---------\n");
}

/*The function shootEnemy checks the value of enemies and player in column. Responsible for attacking the enemies if player position is equal to the 
enemies position. Pointers are used to pass values of variables.
@param *nEnemy1,2,3 are variables for the enemies
@param *nEnemy1r,2r,3r are variables for enemy position in rows
@param nPlayer is the player and its position
@param nScore is the score obtained by the user when the player shoots an enemy
@param nTempE is the temporary position of Enemy
@param nFinalE is the final position of the Enemy
Pre-Condition: all parameters are non negative values
@return: returns nothing since it's a void function*/

void shootEnemy(int *nEnemy1, int *nEnemy2, int *nEnemy3, int *nEnemy1r, int *nEnemy2r, int *nEnemy3r, int nPlayer, int *nScore, int nTempE, int nFinalE)
{
    if(*nEnemy1 == nPlayer)// checks the value of column enemies and player
    {
        nTempE = *nEnemy1r;
        nFinalE = 1;
    } 
    if(*nEnemy2 == nPlayer && *nEnemy2r > nTempE)
    {
        nTempE = *nEnemy2r;
        nFinalE = 2;
    } 
    if(*nEnemy3 == nPlayer && *nEnemy3r > nTempE)
    {
        nTempE = *nEnemy3r;
        nFinalE = 3;
    } 
    switch(nFinalE)
    {
        case 1: *nEnemy1 = 1;
                *nEnemy1r = 1;*nScore+=10; break;
        case 2: *nEnemy2 = 1;
                *nEnemy2r = 1;*nScore+=10; break;
        case 3: *nEnemy3 = 1;
                *nEnemy3r = 1;*nScore+=10; break;
    }
}

/*The function moveEnemy serves as the function for enemy movements.
@param *nEnemy is the position of each enemies
@param *nEnemyr is the position of each enemy in rows
Pre-Condition: nEnemy and nEnemyr are non negative values. nEnemy must be greater than 0 and less than on equal to 4.
@return: returns nothing since it's a void function*/

void moveEnemy(int *nEnemy, int *nEnemyr)
{
    int nRand = rand()%3;//generates random values
    switch(nRand)
    {
        case 0: if(*nEnemy != 1)*nEnemy -=1; break;// enemy moves to the right
        case 1: if(*nEnemy !=4)*nEnemy +=1; break;// enemy moves to the left
        case 2: *nEnemyr +=1; break;// enemy moves to next row
    }
}

/*The function moveAllEnemies moves all enemies once when executed.
@param nEnemy1 variable for the first enemy
@param nEnemy1r the position of the first enemy in rows
@param nEnemy2 variable for the second enemy
@param nEnemy2r the position of the second enemy in rows
@param nEnemy3 variable for the third enemy
@param nEnemy3r the position of the third enemy in rows
Pre-Condition: all parameters are non negative values. 
@return: returns nothing since it's a void function*/

void moveAllEnemies(int *nEnemy1,int *nEnemy2, int *nEnemy3, int *nEnemy1r,int *nEnemy2r,int *nEnemy3r)
{
    moveEnemy(nEnemy1, nEnemy1r);//enemy positions
    moveEnemy(nEnemy2, nEnemy2r);
    moveEnemy(nEnemy3, nEnemy3r);
}

int main()
{
    int rStart =0 , cStart=0 , nEnemy1=0 , nEnemy1r=0, nEnemy2=0, nEnemy2r=0, nEnemy3=0, nEnemy3r=0,nScore = 0;
    int nPlayer =1, pRStart=0, pCStart=0, nChoice=0,nTempE=0, nFinalE=0;
    nEnemy1 = 1, nEnemy1r = 1;/*Coordinates of the enemy position*/
    nEnemy2 = 2, nEnemy2r = 1;
    nEnemy3 = 3, nEnemy3r = 1;
    nScore = 0;
    srand(time(NULL));// srand generates random non negative values and uses time function
    displayStartMenu();// prints start menu
    scanf("%d", &rStart);// scan value for rStart
    switch(rStart)
    {
        case 1: while(nEnemy1r !=6 && nEnemy2r != 6 && nEnemy3r != 6 && nScore <= 100)
        { 
        printBoard(rStart, cStart,nEnemy1, nEnemy1r, nEnemy2, nEnemy2r, nEnemy3, nEnemy3r);// prints game board and enemy positions
        printPlayer(nPlayer,pRStart,pCStart);// prints player position
        printf(" Score: %03d\n Actions: \n 1- Move Right\n 2- Move Left\n 3- Fire Laser\n Input Action: ",nScore);// prints choices and score
        while(nChoice == 0)
        {
        scanf("%d",&nChoice);// scan value for nChoice or player choice
        switch(nChoice)
            {
                case 1: if(nPlayer != 4)
                {
                   nPlayer+=1; 
                }
                else
                {
                    printf("Invalid Input!!\n");// executes when user's input is invalid
                    nChoice =0;
                } break;
                case 2: if(nPlayer != 1)
                {
                   nPlayer-=1; 
                }
                else
                {
                    printf("Invalid Input!!\n");// executes when user's input is invalid
                    nChoice = 0;
                } break;
                case 3:  shootEnemy(&nEnemy1,&nEnemy2,&nEnemy3,&nEnemy1r,&nEnemy2r,&nEnemy3r,nPlayer,&nScore, nTempE, nFinalE); break;
            }
        }
        nChoice = 0;
        moveAllEnemies(&nEnemy1,&nEnemy2,  &nEnemy3,  &nEnemy1r, &nEnemy2r, &nEnemy3r);
        } break;
        case 2: printf("Program Ended"); break; // ends the program
    }
    if(nEnemy1r == 6 || nEnemy2r == 6 || nEnemy3r == 6)
    {
        printf("You Lose, Game Over!!!");// execute when player loses
    }
    else
    {
        printf("Victory!!!");// execute when player reached 100 points and player wins
    }
    return 0; 
}