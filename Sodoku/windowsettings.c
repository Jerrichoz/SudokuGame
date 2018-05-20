#include <windows.h>
#include "header.h"
#include <stdio.h>

/*
Name:
int consolewindowsettings()
Parameters:
None
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Just sets the window settings of the console to a appropriate size
Sourece:
https://forum.chip.de/discussion/1560510/console-size-veraendern
https://docs.microsoft.com/en-us/windows/console/setconsolewindowinfo
*/
int consolewindowsettings()
{

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD scb = {121,51};
    SetConsoleScreenBufferSize(hCon, scb);


    SMALL_RECT rect = {0,0,120,50};
    SetConsoleWindowInfo(hCon, TRUE, &rect);

    return 0;
}
