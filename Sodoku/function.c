#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <dirent.h>

//Border-Constant
#define BORDER printf("+-------+-------+-------+\n")

int GenerateField(SF GameFields[9][9], int instruction)
{
    //Clear Screen
    system("cls");

    int i = 0;
    int j = 0;
    //Top border of the Grid
    BORDER;
    //2 Loops, for generating the Field based of the Array GameFields.

    //Loop for the columns
    for(i = 0; i <= 8; i++)
    {
        printf("|");
        //Loop for the rows
        for(j = 0; j <= 8; j++)
        {
            //"." Should be displayed instead of 0
//            if (GameFields[j][i].Number == 0)
//            {
//                printf(" .");
//            }
//            else
//            {
            //Setting the Color
            //The cursor is marked as RED and YELLOW on a not-editable number it is
            //the other editable numbers are marked as GREEN and non-editable as WHITE
            if(GameFields[j][i].Selected == 1 && GameFields[j][i].Editable == 1)
            {
                GameFields[j][i].Color = RED;
            }
            else if(GameFields[j][i].Selected == 1 && GameFields[j][i].Editable == 0)
            {
                GameFields[j][i].Color = GREEN;
            }
            else if(GameFields[j][i].Editable == 0)
            {
                GameFields[j][i].Color = WHITE;
            }
            else
            {
                GameFields[j][i].Color = CYAN;
            }

            //Debug
            if(GameFields[j][i].Error == 1)
            {
                GameFields[j][i].Color = MAGENTA;
            }
            printcoloredNR(GameFields[j][i].Number, GameFields[j][i].Color);

//            }
            //Formating for Layout
            if((j==2)||(j==5))
            {
                printf(" |");
            }
        }
        //2 Central Borders
        printf(" |\n");
        if((i==2)||(i==5))
        {
            BORDER;
        }
    }
    //Lower Border
    BORDER;

    //Print Instructions
    printInstructions(instruction);

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

int printInstructions(int menuorgame)
{

    //Print Game Instructions
    if(menuorgame == 1)
    {

        printf("\n\n\n\n");
        printf("COLOR EXPLANATION:\n");
        printf("WHITE are the first numbers that were given to solve the Puzzle. Therefore they aren't editable.\n");
        setColour(BLUE);
        printf("BLUE are the numbers, that have to be assigned by you. These are editable.\n");
        setColour(RED);
        printf("RED is the color of your cursor, when you are on editable number.\n");
        setColour(GREEN);
        printf("GREEN is the color of your cursor, when you are on a non-editable number.\n");
        setColour(WHITE);
        printf("\nINSTRUCTIONS\n");
        printf("-------------------------------------------------------------\n");
        printf("SELECTION:\n");
        printf("UPARROW for UP, DOWNARROW for DOWN, LEFTARROW for LEFT and RIGHTARROW for RIGHT\n\n");
        printf("NUMBERS:\n");
        printf("0-9 are the only viable Options for a number in this Sodoku!\n\n");
        printf("OPTIONS:\n");
        printf("SAVING with F5 and go back\n");
        printf("Check with c!");
        printf("Hint with H");
    }
    else if(menuorgame == 3)
    {
        printf("\n\n\n\n");
        printf("CONGRATULATIONS!\n");
        printf("The Sodoku is solved!\n");
    }
    else if(menuorgame == 4)
    {
        printf("\n\n\n\n");
        printf("SORRY!\n");
        printf("The Sodoku is not solved quite yet!\n");
    }
    return 0;
}

int GetDirectoryList(char NameList[100][512], char path[],int *NumberOfListMember)
{
    //Source: https://www.unixboard.de/threads/verzeichnis-auslesen-und-dateien-nummerieren-in-c.18416/
    int i;
    i = 0;
    //Directory struct - dirHandle??????????
    DIR *dirHandle;
    struct dirent * dirEntry;

    dirHandle = opendir("./matchfields");
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
       //The Number of List Member is the last index+1 (because indices are sstarting at 0)

       *NumberOfListMember = i;
    }
    return 0;

}


int SetBlockForField(int xCoordinate, int yCoordinate)
{
    //First three columns (zero to three)
    if((xCoordinate >= 0) && (xCoordinate <= 2))
    {
        if((yCoordinate >= 0) && (yCoordinate <= 2))
        {
            return 1;
        }
        if((yCoordinate >= 3) && (yCoordinate <= 5))
        {
            return 2;
        }
        if((yCoordinate >= 6) && (yCoordinate <= 8))
        {
            return 3;
        }
    }
    //columns three to five
    if((xCoordinate >= 3) && (xCoordinate <= 5))
    {
        if((yCoordinate >= 0) && (yCoordinate <= 2))
        {
            return 4;
        }
        if((yCoordinate >=3) && (yCoordinate <= 5))
        {
            return 5;
        }
        if((yCoordinate >= 6) && (yCoordinate <= 8))
        {
            return 6;
        }
    }
    //columns six to eight
    if((xCoordinate >= 6) && (xCoordinate <= 8))
    {
        if((yCoordinate >= 0) && (yCoordinate <= 2))
        {
            return 7;
        }
        if((yCoordinate >= 3) && (yCoordinate <= 5))
        {
            return 8;
        }
        if((yCoordinate >= 6) && (yCoordinate <= 8))
        {
            return 9;
        }
    }
    return 0;
}


