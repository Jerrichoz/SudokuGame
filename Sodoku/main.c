#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

int main()
{
    //Load Window Settings
    consolewindowsettings();

    //Initiliaze the game starting the gameloop
    gameloop();

    printf("Spiel ist beendet!");
    return 0;
}

//It's the MainLoop
int gameloop()
{
    SF gameFields[9][9];
    int loopvar = 1;
    int difficultyInRandomgame;
    int boolexit = 0;
    char pathForNewGames[1024];
    char pathForSaveGames[1024];
    int passedTimeInSeconds = 0.0;
    char matchName[512] = "";
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
            loopvar = cursorloop(gameFields,matchName,&passedTimeInSeconds);
            break;
        case(STRTGAME):
            loopvar = loadGameFromFile(matchName,gameFields,pathForNewGames,&passedTimeInSeconds);
            break;
        case(RNDGAME):
            loopvar = randomGameGen(gameFields, difficultyInRandomgame);
            break;
        case(RNDGAMEMENU):
            loopvar = randomGameLoop(&difficultyInRandomgame);
            break;
        case(LOADGAME):
            loopvar = loadGameFromFile(matchName,gameFields,pathForSaveGames,&passedTimeInSeconds);
            break;
        //EXIT GAME
        case(EXTGAME):
            return 0;
            break;
        }
    }
    return 0;
}

