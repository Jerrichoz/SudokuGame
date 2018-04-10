#include <windows.h>
#include "header.h"
 int cursorloop(){

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
                //printf("Uparrow\n");

                break;

                //Downarrow
                case(80): printf("Downarrow\n");break;

                //Leftarrow
                case(75): printf("Leftarrow\n");break;

                //Rightarrow
                case(77):

                    break;

            }
        }
    }
 }
