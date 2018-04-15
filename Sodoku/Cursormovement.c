#include <windows.h>
#include "header.h"
#include <stdio.h>

int cursorloop(SF GameFields[9][9])
{

    ////Arraycoordinates to navigate
    //the current position
    int arrayx = 4;
    int arrayy = 4;

    //the last position
    int oldarrayx = 4;
    int oldarrayy = 4;



    //Colorvariables tempcolor for mainsettings and previousnumbercolor for the color property of the struct array
    int tempcolor;
    int previousnumbercolor = GameFields[arrayx][arrayy].Color;

    //Loopexitvariable
    int boolexit = 0;

    while(boolexit != 1)
    {
        if(kbhit()) // Nur wenn auch eine Taste gedrückt ist
        {
            oldarrayx = arrayx;
            oldarrayy = arrayy;
            //Quelle für Cursor https://www.computerbase.de/forum/showthread.php?t=202425
            //                  https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions
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
                //Restoring the old colorvalue of the previous number
                GameFields[oldarrayx][oldarrayy].Color = previousnumbercolor;
                //Saving the colorvalue of the number, before changing it
                previousnumbercolor = GameFields[arrayx][arrayy].Color;
                break;
            }

            //temp
            int testedit = GameFields[arrayx][arrayy].Editable;

            ////Marking the number of the cursorposition in Red(4)

            //Saving old overallcolor
            tempcolor = getColour();


            printf("Gamefield Old X=%i und Y=%i und Colorvalue=%i\n", oldarrayx, oldarrayy, GameFields[oldarrayx][oldarrayy].Color);





            //The cursor is marked as RED and on a not-editable number it is YELLOW
            if(GameFields[arrayx][arrayy].Editable == 1)
            {
                GameFields[arrayx][arrayy].Color = 4;
            }
            else
            {
                testedit = 0;
                GameFields[arrayx][arrayy].Color = 14;
            }
            //Setting the old overallcolor back; clearing the screen and regenerating the field
            setColour(tempcolor);
            system("cls");
            GenerateField(GameFields);

            //DELETE Testing
            printf("Gamefield Old X=%i und Y=%i und Colorvalue=%i\n", oldarrayx, oldarrayy,GameFields[oldarrayx][oldarrayy].Color);
            printf("Gamefield New X=%i und Y=%i und Colorvalue=%i\n", arrayx, arrayy, GameFields[arrayx][arrayy].Color);
            printf("This field is %i editable", testedit);
            printf("\nPreviousnumbercolor: %i", previousnumbercolor);
        }
    }
    return 0;
}

// Gets and Set the editability of the arraynumber
int SetSodokuFieldEditability(int xCoordinate, int yCoordinate, SF GameFields[9][9],int editable)
{
    (GameFields[xCoordinate][yCoordinate]).Editable = editable;
    return 0;
}

int GetSodokuFieldEditability(int xCoordinate, int yCoordinate, SF GameFields[9][9])
{
    return (GameFields[xCoordinate][yCoordinate]).Editable;
}

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
    return 0;
}
