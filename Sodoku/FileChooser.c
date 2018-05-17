#include "header.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dirent.h>

int GenerateChooserList(char NameList[100][512], int NumberOfListMember,int ChooserPosition)
{
    int i = 0;
    int tempcolor = getColour();
    system("cls");
    printf("FILES:\n\n");
    for(i = 0; i < NumberOfListMember; i++)
    {
        if(i == ChooserPosition)
        {
            setColour(RED);
        }
        printf("%s\n", NameList[i]);
        setColour(tempcolor);
    }
    printInstructions(FILECHOOSER);
    return 0;
}

int ChooserLoop(char MatchName[],char path[], int CreateNewFile)
{
    int ChooserPosition = 0;
    char NameList[100][512];
    int NumberOfListMember;

    GetDirectoryList(NameList,path,&NumberOfListMember,CreateNewFile);

    GenerateChooserList(NameList,NumberOfListMember,ChooserPosition);

    while(1)
    {
        if(kbhit()) //Only if key is pressed
        {
            char c = getch(); // Muss auf keine Eingabe warten, Taste ist bereits gedrückt
            switch(c)
            {
            //Movement
            case(72):
            case(80):
                movemenuPosition(&ChooserPosition, c,NumberOfListMember-1);//-1, because the Position of the first Listmember is 0
                break;
            //Enter
            case(13):
                strcpy(MatchName, NameList[ChooserPosition]);
                return CURSORLOOP;
                break;
            //Escape
            case(27):
                return MAINMENU;
                break;
            }
            GenerateChooserList(NameList,NumberOfListMember,ChooserPosition);
        }
    }
    return 0;
}

int LoadMatchfieldFromFile(SF NewMatchField[9][9],char Path[])
{
    int j,k;
    //Temp is needed for reading the File. Each Char of the File is read separately
    char temp;

    //Source: http://www.c-howto.de/tutorial/dateiverarbeitung/oeffnen-schliessen/
    FILE *matchfield;

    //open File
    matchfield = fopen(Path,"r");
    //Check if File was found
    if (matchfield == NULL)
    {
        printf("Datei konnte nicht gefunden werden.\n");
    }
    else
    {
        //If File was found:
        j = 0;
        k = 0;
        printf("Die Datei konnte gefunden werden.\n");
        //reading of each Char
        while((temp = fgetc(matchfield))!=EOF)

        {
            //Saving the numerical sequenz into the array
            //Char '1' - 48 equals Integer 1. Same for the other Numbers form 0 to 9.
            NewMatchField[j][k].Number = temp-48;
            //Setting the property Block
            NewMatchField[j][k].Block = SetBlockForField(j,k);
            //Block for non-editable Fields (0 to 9)
            if (((temp - 48) >= 1) && ((temp - 48) <= 9))
            {
                NewMatchField[j][k].Editable = 0;
            }
            //Block for editable Fields
            else
            {
                NewMatchField[j][k].Editable = 1;
            }
            //Counting Variable
            if((j == 8) &&(k == 8))
            {
                //output if File was correct
                return 0;
            }
            else if(j == 8)
            {
                k++;
                j = -1;
            }
            j++;
        }


    }
    //Error output: File wasn't coorrect
    return 1;
}
int GetDirectoryList(char NameList[100][512], char path[],int *NumberOfListMember, int CreateNewFile)
{
    //Source: https://www.unixboard.de/threads/verzeichnis-auslesen-und-dateien-nummerieren-in-c.18416/
    int i;
    i = 0;
    //Directory struct - dirHandle??????????
    DIR *dirHandle;
    struct dirent * dirEntry;

    dirHandle = opendir(path);
    if (dirHandle) {
       while (0 != (dirEntry = readdir(dirHandle))) {
            //. and .. should not be displayed
            if(strcmp(dirEntry->d_name, ".")==0 ||
               strcmp(dirEntry->d_name, "..")==0)
               {
                   continue;
               }
            //printf("%d) %s\n", i, dirEntry->d_name);
            //copy the String in a list of strings
            strcpy(NameList[i],dirEntry->d_name);
            i ++;
       }
       closedir(dirHandle);
    if (CreateNewFile)
    {
        strcpy(NameList[i],"New File");
        i++;
    }
       //The Number of List Member is the last index+1 (because indices are sstarting at 0)

       *NumberOfListMember = i;
    }
    return 0;

}

