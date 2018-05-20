#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>


int cursorloop(SF gameFields[9][9],char matchName[512],int *passedTimeInSeconds)
{
    time_t startTime;
    time_t endTime;
	time(&startTime);
	startTime = startTime - *passedTimeInSeconds;

    int instructionmenu = GAME;
    // //Arraycoordinates to navigate
    //setting the current position
    int arrayx = 4;
    int arrayy = 4;
    gameFields[arrayx][arrayy].Selected = 1;

    //Variables for saving the last position
    int oldarrayx = 4;
    int oldarrayy = 4;

    int row,column;
// First Generation of Field
    generateField(gameFields, instructionmenu,*passedTimeInSeconds,matchName);

    //Quelle für Cursor https://www.computerbase.de/forum/showthread.php?t=202425
    //                  https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions

    //Loopexitvariable
    int boolexit = 0;
    while(boolexit != 1)
    {
        instructionmenu = GAME;
        // Nur wenn auch eine Taste gedrückt ist
        if(kbhit())
        {
            //Saving the current position
            oldarrayx = arrayx;
            oldarrayy = arrayy;

            // Muss auf keine Eingabe warten, Taste ist bereits gedrückt
            char c = getch();
            switch(c)
            {
            //Movement
            case(72):
            case(80):
            case(75):
            case(77):
                movearrow(&arrayx, &arrayy, c);
                gameFields[oldarrayx][oldarrayy].Selected = 0;
                break;
            //Numbers
            case(48):
            case(49):
            case(50):
            case(51):
            case(52):
            case(53):
            case(54):
            case(55):
            case(56):
            case(57):
                setNumber(gameFields, c, arrayx, arrayy);
                break;
            // //Functions
            //Escape esc
            case(27):
                gameFields[arrayx][arrayy].Selected = 0;
                return 1;
                break;
            //Check c
            case(99):
                instructionmenu = checkIfSolved(gameFields);
                break;
            //Hint h
            case(104):
                if(findUnassigned(gameFields, &row, &column))
                {
                gameFields[row][column].Number = gameFields[row][column].Hint;
                }
                break;
            //s-key pressed
            case(115):
                time(&endTime);
                saveGame(gameFields,(endTime - startTime));
                break;
            }

            //Set as Selected
            gameFields[arrayx][arrayy].Selected = 1;

            //Generate the field
            time(&endTime);
            generateField(gameFields, instructionmenu,(endTime - startTime),matchName);



        }

    }
    return 0;
}
/*
Moves in the array through keypads (Uparrow, Downarrow, Leftarrow, Rightarrow)
*/
int movearrow(int *x, int *y, int direction)
{
    switch(direction)
    {
    //Uparrow
    case(72):
        *y -= 1;
        if(*y == -1)
        {
            *y = 8;
        }

        break;
    //Downarrow
    case(80):
        *y += 1;
        if(*y == 9)
        {
            *y = 0;
        }
        break;
    //Leftarrow
    case(75):
        *x -= 1;
        if(*x == -1)
        {
            *x = 8;
        }
        break;
    //Rightarrow
    case(77):
        *x += 1;
        if(*x == 9)
        {
            *x = 0;
        }
        break;
    }
    return 1;
}
/*
The Function displays the matchfield of the Current Game.
The Parameter is a 2-dimensional Array of SodokuFields, which is the Base of the Current Game.
COMMENT NEED MAX
*/
int generateField(SF gameFields[9][9], int instruction, int passedTimeInSeconds, char matchName[512])
{
    //Clear Screen
    system("cls");

    int i = 0;
    int j = 0;
    //Top border of the Grid
    BORDER;
    //2 Loops, for generating the Field based of the Array GameFields.

    //Loop for the columns
    for(i = 0; i <= 8; i++)
    {
        printf("|");
        //Loop for the rows
        for(j = 0; j <= 8; j++)
        {

            //Setting the Color
            //The cursor is marked as RED and YELLOW on a not-editable number it is
            //the other editable numbers are marked as GREEN and non-editable as WHITE
            if(gameFields[j][i].Selected == 1 && gameFields[j][i].Editable == 1)
            {
                gameFields[j][i].Color = RED;
            }
            else if(gameFields[j][i].Selected == 1 && gameFields[j][i].Editable == 0)
            {
                gameFields[j][i].Color = GREEN;
            }
            else if(gameFields[j][i].Editable == 0)
            {
                gameFields[j][i].Color = WHITE;
            }
            else
            {
                gameFields[j][i].Color = CYAN;
            }

            //Debug
            if(gameFields[j][i].Error == 1)
            {
                gameFields[j][i].Color = MAGENTA;
            }
            printColoredNR(gameFields[j][i].Number, gameFields[j][i].Color);

            //Formating for Layout
            if((j==2)||(j==5))
            {
                printf(" |");
            }
        }
        //2 Central Borders
        printf(" |\n");
        if((i==2)||(i==5))
        {
            BORDER;
        }
    }
    //Lower Border
    BORDER;

    //Print Instructions
    printInstructions(instruction);
    printNameAndTime(matchName,passedTimeInSeconds);
    return 0;
}
/*
Gots called in cursorloop and basiclly set the number in the field, which is currently selected.
Necessary parameters, is the matchfield array struct, the number to set in and the coordinates to set it in.
*/
int setNumber(SF gameFields[9][9],int number, int x, int y)
{
    if(gameFields[x][y].Editable == 1)
    {


        switch(number)
        {
        // Number: 0
        case(48):
            gameFields[x][y].Number = 0;
            break;
        // Number: 1
        case(49):
            gameFields[x][y].Number = 1;
            break;
        // Number: 2
        case(50):
            gameFields[x][y].Number = 2;
            break;
        // Number: 3
        case(51):
            gameFields[x][y].Number = 3;
            break;
        // Number: 4
        case(52):
            gameFields[x][y].Number = 4;
            break;
        // Number: 5
        case(53):
            gameFields[x][y].Number = 5;
            break;
        // Number: 6
        case(54):
            gameFields[x][y].Number = 6;
            break;
        // Number: 7
        case(55):
            gameFields[x][y].Number = 7;
            break;
        // Number: 8
        case(56):
            gameFields[x][y].Number = 8;
            break;
        // Number: 9
        case(57):
            gameFields[x][y].Number = 9;
            break;
        }
    }
    return 1;
}
