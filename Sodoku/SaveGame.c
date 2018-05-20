#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <string.h>
//This file includes all functions that are specially needed for saving a game.

/*
This function saves a current game in a File.
The parameter "gameFields" is the current game.
The parameter "passedTimeInSeconds" is the Time that has passed while playing.
The return value is always 0.
*/
int saveGame(SF gameField[9][9], int passedTimeInSeconds)
{
    //Sources:
    //Bearbeiten von dateien:
    //http://www.c-howto.de/tutorial/dateiverarbeitung/oeffnen-schliessen/[20.05.2018}
    //Stringfunktionen
    //http://www.c-howto.de/tutorial/strings-zeichenketten/string-funktionen/strings-vergleichn/[17. Juli 2007]
    int i,j,escaped;//escaped is used as a boolean, which indicates whether the user pressed escape in the chooserLoop
    char temp1[512];//this variable is used to write the passedTimeInSeconds-parameter as a string into the file
    char path[1024] = "./savegames/";
    char input[512];//this variable is used as a input-buffer from the user
    char compString[512] = "New File";//this variable is used to compare the input string. Its initial Value is the Value for the New-File-Option.
    FILE *savegameFile;

    //choose a File, which will be overwritten OR the option "New File"
    escaped = chooserLoop(input,path,1);
    //if escape-key was pressed in chooserLoop
    if(escaped == 1)
    {
        return 0;
    }
    //if "New File" was chosen
    if(strcmp(input,compString) == 0)
    {
        system("cls");
        scanf("%s",input);
    }
    //modified path with the input of the user
    strcat(path,input);
    savegameFile = fopen(path,"w");
    //each Field is written in the File
    for(i = 0; i <= 8; i++)
    {
        for(j = 0; j <= 8; j++)
        {
            fputc((gameField[j][i].Number+48),savegameFile); //+48, because of cast into char (ASCII-Value of 0 to 9)
            fputc((gameField[j][i].Block+48),savegameFile);
            fputc((gameField[j][i].Editable+48),savegameFile);
            fputc((gameField[j][i].Hint+48),savegameFile);
            fputc((gameField[j][i].Error+48),savegameFile);
        }
    }
    //the passed time is written into the file
    itoa(passedTimeInSeconds,temp1,10);
    fprintf(savegameFile,temp1);
    fclose(savegameFile);
    return 0;
}

