
#include <windows.h>
#include "header.h"
#include <stdio.h>
 int cursorloop(SF GameFields[9][9]){

    //Arraycoordinates to navigate
    int arrayx = 4;
    int arrayy = 4;
    int tempcolor;
    int oldarrayx = 4;
    int oldarrayy = 4;
    int previousnumbercolor = 50;

    int boolexit = 0;
    while(boolexit != 1)
    {
        if(kbhit()) // Nur wenn auch eine Taste gedrückt ist
        {
            //Quelle für Cursor https://www.computerbase.de/forum/showthread.php?t=202425
            //                  https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions
            char c = getch(); // Muss auf keine Eingabe warten, Taste ist bereits gedrückt
            //printf("%i",c);
            switch(c)
            {
                //Uparrow
                case(72):
                oldarrayy = arrayy;
                arrayy -= 1;
                if(arrayy == -1)
                {
                    arrayy = 8;
                }
                break;

                //Downarrow
                case(80):
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
                arrayx -= 1;
                if(arrayx == -1)
                {
                    arrayx = 8;
                }
                break;

                //Rightarrow
                case(77):
                oldarrayx = arrayx;
                arrayx += 1;
                if(arrayx == 9)
                {
                    arrayx = 0;
                }
                break;
            }

                //Marking the number of the cursor in Red(4)
                tempcolor = getColour();

                if(previousnumbercolor != 50)
                {
                    GameFields[oldarrayx][oldarrayy].Color = previousnumbercolor;
                }
                previousnumbercolor = GameFields[arrayx][arrayy].Color;
                GameFields[arrayx][arrayy].Color = 4;

                setColour(tempcolor);
                system("cls");
                GenerateField(GameFields);
        }
    }
 }
