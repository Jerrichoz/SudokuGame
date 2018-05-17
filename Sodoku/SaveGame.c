#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <string.h>

int saveGame(SF MatchField[9][9], int passedTimeInSeconds)
{
    //Sources:
    //http://www.c-howto.de/tutorial/dateiverarbeitung/oeffnen-schliessen/
    //http://www.c-howto.de/tutorial/strings-zeichenketten/string-funktionen/strings-vergleichn/
    int i,j,escaped;
    char temp1[512];
    char path[1024] = "./savegames/";
    char input[512];//Input from User
    char compstring[512] = "New File";//to check if read string was not empty

    //Savegamename ist gesetzt
    FILE *savegamefile;

    escaped = ChooserLoop(input,path,1);
    if(escaped == 1)
    {
        return 0;
    }
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
        }
    }
    itoa(passedTimeInSeconds,temp1,10);
    fprintf(savegamefile,temp1);
    fclose(savegamefile);
    return 0;
}

