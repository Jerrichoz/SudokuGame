#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//This file includes all functions that are specially needed for loading a game.
/*
This function loads a Sudoku-game from a File. The game can be a new game or a saved game.
The parameter "matchName" is used as a return value. It indicates the name of the chosen file, that the game is based on.
The parameter "gameField" is the current game.
The parameter "path" indicates the directory from which the file should be load from.
The parameter "passedTimeInSeconds" indicates the passed Time, that is read out of the file.
The return value indicates the next step (loop).
*/
int loadGameFromFile(char matchName[512], SF gameField[9][9],char path[1024],int *passedTimeInSeconds)
{
    int i,j,k,returnValue;//returnValue is used as a buffer-variable for the final return
    char temp;//temp will be used to read the passed Time from the File.
    char numberString[1024];//this variable is used for building the number "passedTimeInSeconds" as a String.
    FILE *savegameFile;

    //initialize gameField, so a complete new game will be started
    genEmptySodoku(gameField);

    //the chooserLoop indicates the returnValue. The retunrValue could be CURSORLOOP or MAINMENU (both are constants (numbers))
    //File, that should be read from will be chosen
    returnValue = chooserLoop(matchName,path,0);
    if(returnValue == MAINMENU)
    {
        return MAINMENU;
    }
    strcat(path,matchName);
    savegameFile = fopen(path,"r");

    for(i = 0; i <= 8; i++)
    {
        for(j = 0; j <= 8; j++)
        {
            //The properties of the gameFields is read out in the same order, as they were saved.
            //New Files, that are added, must have the properties written in this order for each Field.
            gameField[i][j].Number = fgetc(savegameFile)-48;
            gameField[i][j].Block = fgetc(savegameFile)-48;
            gameField[i][j].Editable = fgetc(savegameFile)-48;
            gameField[i][j].Hint = fgetc(savegameFile)-48;
            gameField[i][j].Error = fgetc(savegameFile)-48;
            gameField[i][j].Selected = 0;
        }
    }
    //reading of the passedTimeInSeconds
    k = 0;
    //read the characters into a string
    while((temp = fgetc(savegameFile))!=EOF)
    {
        numberString[k] = temp;
        k++;
    }
    //cast from string to integer
    *passedTimeInSeconds = atoi(numberString);
    fclose(savegameFile);
    return returnValue;
}
