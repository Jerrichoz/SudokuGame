#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <conio.h>

int cursorloop(SF GameFields[9][9])
{

    // //Arraycoordinates to navigate
    //setting the current position
    int arrayx = 4;
    int arrayy = 4;
    GameFields[arrayx][arrayy].Selected = 1;

    //Variables for saving the last position
    int oldarrayx = 4;
    int oldarrayy = 4;

// First Generation of Field
    GenerateField(GameFields);

    //Quelle für Cursor https://www.computerbase.de/forum/showthread.php?t=202425
    //                  https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions

    //Loopexitvariable
    int boolexit = 0;
    while(boolexit != 1)
    {
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
                GameFields[oldarrayx][oldarrayy].Selected = 0;
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
                setNumber(GameFields, c, arrayx, arrayy);
                break;
            }
            //Set as Selected
            GameFields[arrayx][arrayy].Selected = 1;

            //Generate the field
            GenerateField(GameFields);
        }


    }
    return 0;
}

// Moves in a two-dimensional environement accordingly to the third parameter
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

int setNumber(SF GameFields[9][9],int number, int x, int y)
{
    if(GameFields[x][y].Editable == 1)
    {


        switch(number)
        {
        // Number: 0
        case(48):
            GameFields[x][y].Number = 0;
            break;
        // Number: 1
        case(49):
            GameFields[x][y].Number = 1;
            break;
        // Number: 2
        case(50):
            GameFields[x][y].Number = 2;
            break;
        // Number: 3
        case(51):
            GameFields[x][y].Number = 3;
            break;
        // Number: 4
        case(52):
            GameFields[x][y].Number = 4;
            break;
        // Number: 5
        case(53):
            GameFields[x][y].Number = 5;
            break;
        // Number: 6
        case(54):
            GameFields[x][y].Number = 6;
            break;
        // Number: 7
        case(55):
            GameFields[x][y].Number = 7;
            break;
        // Number: 8
        case(56):
            GameFields[x][y].Number = 8;
            break;
        // Number: 9
        case(57):
            GameFields[x][y].Number = 9;
            break;
        }
    }
    else
    {
        return 1;
    }
    return 1;
}
