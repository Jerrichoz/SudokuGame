#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

int saveGame(SF MatchField[9][9],char GameName[512])
{
    //Sources:
    //http://www.c-howto.de/tutorial/dateiverarbeitung/oeffnen-schliessen/
    //http://www.c-howto.de/tutorial/strings-zeichenketten/string-funktionen/strings-vergleichn/
    char SaveGameName[1024];
    int i,j;
    char temp1[512];
    char temp2[512];
    char path[1024] = "./savegames/";
    char input[512];//Input from User
    char compstring[512] = "New Savegame";//to check if read string was not empty
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

    ChooserLoop(input,path);
    if(strcmp(input,compstring) == 0)
    {
        strcpy(compstring,"");
        system("cls");
        scanf("%s",input);
    }
    strcat(path,input);
    savegamefile = fopen(path,"w");
    for(i = 0; i <= 8; i++)
    {
        for(j = 0; j <= 8; j++)
        {
            fputc((MatchField[j][i].Number+48),savegamefile); //+48, because of cast into char (ASCII-Value of 0 tp 9)
            fputc((MatchField[j][i].Block+48),savegamefile);
            fputc((MatchField[j][i].Editable+48),savegamefile);
            fputc((MatchField[j][i].Selected+48),savegamefile);
        }
    }
    fclose(savegamefile);
    return 0;
}

