#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

int main()
{
    //Load Window Settings
    consolewindowsettings();

    //Loopvariable starting in MainMenu
    int loopvar = 1;

    //first struct definition
    struct SodokuField gamefield[9][9];

    LoadMatchfieldFromFile(gamefield,"C:\\Users\\Jan\\Desktop\\Sodoku\\matchfields.txt");

    //Initiliaze the game starting the gameloop
    gameloop(loopvar, gamefield);

    printf("Spiel ist beendet!");
    return 0;
}

//It's the MainLoop
int gameloop(int loopvar, SF GameFields[9][9])
{
    int difficultyinrandomgame;
    int boolexit = 0;
    char path[260];
    while (boolexit != 1)
    {
        switch(loopvar)
        {
        case(0):
            printf("Error. Unknown loop.");
        //MainMenu - Starting Point, switching into the MenuLoop
        case(MAINMENU):
            loopvar = menuLoop();
            break;
        case(CURSORLOOP):
            loopvar = cursorloop(GameFields);
            break;
        case(STRTGAME):
            loopvar = ChooserLoop(path);
            LoadMatchfieldFromFile(GameFields,path);
            break;
        case(RNDGAME):
            loopvar = randomGameGen(GameFields, difficultyinrandomgame);
            break;
        case(RNDGAMEMENU):
            loopvar = randomGameLoop(GameFields, &difficultyinrandomgame);
            break;
        //EXIT GAME
        case(EXTGAME):
            return 0;
            break;
        }
    }
    return 0;
}

