#include <windows.h>
#include "header.h"
#include <stdio.h>

 int cursorloop(SF GameFields[9][9]){

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
            //Quelle für Cursor https://www.computerbase.de/forum/showthread.php?t=202425
            //                  https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions
            // Muss auf keine Eingabe warten, Taste ist bereits gedrückt
            char c = getch();
            switch(c)
            {
                //Uparrow
                case(72):
                oldarrayx = arrayx;
                oldarrayy = arrayy;
                arrayy -= 1;
                if(arrayy == -1)
                {
                    arrayy = 8;
                }
                break;

                //Downarrow
                case(80):
                oldarrayx = arrayx;
                oldarrayy = arrayy;
                arrayy += 1;
                if(arrayy == 9)
                {
                    arrayy = 0;
                }
                break;

                //Leftarrow
                case(75):
                oldarrayx = arrayx;
                oldarrayy = arrayy;
                arrayx -= 1;
                if(arrayx == -1)
                {
                    arrayx = 8;
                }
                break;

                //Rightarrow
                case(77):
                oldarrayx = arrayx;
                oldarrayy = arrayy;
                arrayx += 1;
                if(arrayx == 9)
                {
                    arrayx = 0;
                }
                break;
            }
                //temp
                int testedit = GameFields[arrayx][arrayy].Editable;

                ////Marking the number of the cursorposition in Red(4)

                //Saving old overallcolor
                tempcolor = getColour();

                //Restoring the old colorvalue of the previos number
                printf("Gamefield Old X=%i und Y=%i und Colorvalue=%i\n", oldarrayx, oldarrayy, GameFields[oldarrayx][oldarrayy].Color);
                GameFields[oldarrayx][oldarrayy].Color = previousnumbercolor;

                //Saving the colorvalue of the number, before changing it
                previousnumbercolor = GameFields[arrayx][arrayy].Color;

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
