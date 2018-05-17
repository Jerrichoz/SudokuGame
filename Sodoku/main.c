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
    char pathForNewGames[1024];
    char pathForSaveGames[1024];
    int passedTimeInSeconds = 0.0;
    char GameName[512] = "";
    while (boolexit != 1)
    {
        strcpy(pathForSaveGames,"./savegames/");
        strcpy(pathForNewGames,"./matchfields/");
        switch(loopvar)
        {
        case(0):
            printf("Error. Unknown loop.");
        //MainMenu - Starting Point, switching into the MenuLoop
        case(MAINMENU):
            loopvar = menuLoop();
            break;
        case(CURSORLOOP):
            loopvar = cursorloop(GameFields,GameName,&passedTimeInSeconds);
            break;
        case(STRTGAME):
            loopvar = loadGameFromFile(GameName,GameFields,pathForNewGames,&passedTimeInSeconds);
            break;
        case(RNDGAME):
            loopvar = randomGameGen(GameFields, difficultyinrandomgame);
            break;
        case(RNDGAMEMENU):
            loopvar = randomGameLoop(GameFields, &difficultyinrandomgame);
            break;
        case(LOADGAME):
            loopvar = loadGameFromFile(GameName,GameFields,pathForSaveGames,&passedTimeInSeconds);
            break;
        //EXIT GAME
        case(EXTGAME):
            return 0;
            break;
        }
    }
    return 0;
}

