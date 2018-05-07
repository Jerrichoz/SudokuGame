#include <windows.h>
#include "header.h"
#include <stdio.h>

//Quelle http://www.cplusplus.com/forum/beginner/54360/
/*
The different colour codes are

0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY/Standard
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
*/

//Source https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions

//Gets and Sets the color
int setColour(int colour)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);

return 0;
}

int getColour()
{

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        return csbi.wAttributes;
    }
    return 0;

}


int printcoloredNR (int number, int color)
{
    int tempcolor = getColour();
    setColour(color);
    printf(" %i", number);
    setColour(tempcolor);

    return 0;
}

