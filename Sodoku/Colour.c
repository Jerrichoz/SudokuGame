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

// Gets and Set the color-attribute of the array
int SetSodokuFieldColor(int xCoordinate, int yCoordinate, SF GameFields[9][9],int Color)
{
    (GameFields[xCoordinate][yCoordinate]).Color = Color;
    return 0;
}

int GetSodokuFieldColor(int xCoordinate, int yCoordinate, SF GameFields[9][9])
{
    return GameFields[xCoordinate][yCoordinate].Color;
}

//Prints the number in the colornumber, which is given through the parameters. The configured color will still be set afterwards.
int princoloredNR (int number, int color)
{
    int tempcolor = getColour();
    setColour(color);
    printf(" %i", number);
    setColour(tempcolor);
}

