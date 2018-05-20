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
/*
Sets the textcolor, the parameter decides the color, defines for the colors are below
*/
int setColor(int color)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

return 0;
}
/*
Get the textcolor
*/
int getColor()
{

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        return csbi.wAttributes;
    }
    return 0;

}

/*
Prints the number in the colornumber, which is given through the parameters.
The previous color will still be set afterwards.
*/
int printColoredNR (int number, int color)
{
    int tempColor = getColor();
    setColor(color);
    printf(" %i", number);
    setColor(tempColor);

    return 0;
}

