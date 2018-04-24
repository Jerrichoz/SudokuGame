#include "header.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int GenerateChooserList(char NameList[100][512], int NumberOfListMember,int ChooserPosition)
{
    int i = 0;
    int tempcolor = getColour();
    system("cls");

    for(i = 0; i < NumberOfListMember; i++)
    {
        if(i == ChooserPosition)
        {
            setColour(RED);
        }
        printf("%s\n", NameList[i]);
        setColour(tempcolor);
    }
    return 0;
}

int ChooserLoop(char MatchName[],char path[])
{
    int ChooserPosition = 0;
    char NameList[100][512];
    int NumberOfListMember;

    GetDirectoryList(NameList,path,&NumberOfListMember);
    //generateMenu(menuPosition);

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
                movemenuPosition(&ChooserPosition, c,NumberOfListMember);
                break;
            //Enter
            case(13):
                strcpy(MatchName, NameList[ChooserPosition]);
                return 2;
                break;
            case(27):
                return 1;
                break;
            }
            GenerateChooserList(NameList,NumberOfListMember,ChooserPosition);

        }
    }
    return 0;
}


