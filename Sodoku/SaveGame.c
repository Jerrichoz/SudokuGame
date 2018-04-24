#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <time.h>

int saveGame(char MatchField[9][9],char GameName[512])
{
    char SaveGameName[1024];

    char temp1[512];
    char temp2[512];
    char path[1024] = "./savegames";
    strcpy(temp2,GameName);
    //set String "SaveGameName"
    strcpy(temp2, strtok(temp2,"."));
    //Source: http://www.c-howto.de/tutorial/zeitfunktionen/
    time_t now;
	now = time(0);
    //Save DateTime to temp1
    strcpy(temp1,ctime(&now));
    //Concartinate temp1 to temp2 and save it in SaveGameName
    strcpy(SaveGameName, strcat(temp2,temp1));
    //Savegamename ist gesetzt
    FILE *savegamefile;

    //
    strcat(path)
    strcpy(path,
    strcat(SaveGameName, ".txt");

    savegamefile = fopen("./test","w");


    fclose(savegamefile);
    return 0;
}

