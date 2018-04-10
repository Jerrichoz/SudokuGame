#include <windows.h>
#include "header.h"
#include <stdio.h>

int changeColour(SF GameFields[9][9], int colour)
{
    const changethiscolour SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),;


        switch(colour)
        {
            //BLACK
            case(0):
            changethiscolour, 0);


            //BLUE
            case(1):
            changethiscolour, 1);


            //GREEN
            case(2):
            changethiscolour, 2);


            //CYAN
            case(3):
            changethiscolour, 3);


            //RED
            case(4):
            changethiscolour, 4);


            //MAGENTA
            case(5):
            changethiscolour, 5);


            //BROWN
            case(6):
            changethiscolour, 6);


            //LIGHTGRAY
            case(7):
            changethiscolour, 7);


            //DARKGRAY
            case(8):
            changethiscolour, 8);


            //LIGHTBLUE
            case(9):
            changethiscolour, 9);


            //LIGHTGREEN
            case(10):
            changethiscolour, 10);


            //LIGHTCYAN
            case(11):
            changethiscolour, 11);


            //LIGHTRED
            case(12):
            changethiscolour, 12);


            //LIGHTMAGENTA
            case(13):
            changethiscolour, 13);


            //YELLOW
            case(14):
            changethiscolour, 14);


            //WHITE
            case(15):
            changethiscolour, 15);

        }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    printf(" %i",GameFields[j][i]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


}

