#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int loadGameFromFile(char MatchName[512], SF MatchField[9][9],char path[1024],int *passedTimeInSeconds)
{
    int i,j,k,returnvalue;
    char temp;
    char numberString[1024];
    FILE *savegamefile;

    returnvalue = ChooserLoop(MatchName,path,0);
    strcat(path,MatchName);
    savegamefile = fopen(path,"r");

        for(i = 0; i <= 8; i++)
        {
            for(j = 0; j <= 8; j++)
            {
                MatchField[i][j].Number = fgetc(savegamefile)-48;
                //reading the following three chars from the file
                MatchField[i][j].Block = fgetc(savegamefile)-48;
                MatchField[i][j].Editable = fgetc(savegamefile)-48;
                MatchField[i][j].Selected = 0;
            }
        }
    k = 0;
    while((temp = fgetc(savegamefile))!=EOF)
    {
        numberString[k] = temp;
        k++;
    }

    *passedTimeInSeconds = atoi(numberString);
    fclose(savegamefile);
    return returnvalue;
}
