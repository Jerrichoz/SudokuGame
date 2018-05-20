#include <windows.h>
#include "header.h"
#include <stdio.h>
/*
In this File are all functions, that are associated with color-displaying
*/
//Farbdarstellung in der Konsole
//Source http://www.cplusplus.com/forum/beginner/54360/[20.05.2018]
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
//Colors for windows console output
//Source https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions[20.05.2018]
/*
Sets the textcolor, the parameter decides the color.
*/
int setColor(int color)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

return 0;
}
/*
Gets the textcolor
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

