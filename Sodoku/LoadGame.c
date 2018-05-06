#include "header.h"
#include <stdio.h>
#include <string.h>
int loadSaveGameFromFile(char MatchName[], SF MatchField[9][9])
{
    int i,j;
    char path[1024] = "./savegames/";

    char temp;
    FILE *savegamefile;

    ChooserLoop(MatchName,path);
    strcat(path,MatchName);
    savegamefile = fopen(path,"r");
    while((temp = fgetc(savegamefile))!= EOF)
    {
        for(i = 0; i <= 8; i++)
        {
            for(j = 0; j <= 8; j++)
            {
                MatchField[i][j].Number = temp-48;
                //reading the following three chars from the file
                MatchField[i][j].Block = fgetc(savegamefile)-48;
                MatchField[i][j].Editable = fgetc(savegamefile)-48;
                MatchField[i][j].Selected = fgetc(savegamefile)-48;
            }
        }
    }
    savegamefile = fclose(savegamefile);
}
