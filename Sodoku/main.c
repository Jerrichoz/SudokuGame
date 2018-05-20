#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>
//This is the main-File.
int main()
{
    //Load Window Settings
    consolewindowsettings();

    //Initiliaze the game starting the gameloop
    gameloop();

    printf("Spiel ist beendet!");
    return 0;
}
/*
This function is the most important loop. It connects all parts of the Program and hands over needed parameter.
*/
int gameloop()
{
    //Initialization of the Gameconstruct
    SF gameFields[9][9];
    //indicates the status of the programm. It starts with the MAINMENU
    int loopvar = MAINMENU;
    //indicates the difficulty in Randomgame
    int difficultyInRandomgame;
    int boolexit = 0;
    //indicates where the file for a new game is
    char pathForNewGames[1024];
    //indicates where the file for a saved game is
    char pathForSaveGames[1024];
    //indicates the time that passed while playing a game
    int passedTimeInSeconds = 0;
    //indicates the name of the match. The Name is Random if it is generated or the name of the File which the game is based on
    char matchName[512] = "";
    while (boolexit != 1)
    {
        //refresh of the paths - needed because arrays are used as call by reference parameter
        strcpy(pathForSaveGames,"./savegames/");
        strcpy(pathForNewGames,"./matchfields/");
        switch(loopvar)
        {
        case(0):
            printf("Error. Unknown loop.");
        //The Statuses for the game:
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
            strcpy(matchName,"Random");
            passedTimeInSeconds = 0;
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
            boolexit = 1;
            break;
        }
    }
    return 0;
}

