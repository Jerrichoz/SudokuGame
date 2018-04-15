#include <windows.h>
#include "header.h"
#include <stdio.h>
//Border-Constant
#define BORDER printf("+-------+-------+-------+\n")

int SetSodokuField(int xCoordinate, int yCoordinate, SF GameFields[9][9],int Number)
{
    (GameFields[xCoordinate][yCoordinate]).Number = Number;
    return 0;
}

int GetSodokuField(int xCoordinate, int yCoordinate, SF GameFields[9][9])
{
    return GameFields[xCoordinate][yCoordinate].Number;
}

int GenerateField(SF GameFields[9][9])
{
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
                //Farbe per Funktion setzen
                princoloredNR(GameFields[j][i].Number, GameFields[j][i].Color);

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
    return 0;
}
int LoadMatchfieldFromFile(SF NewMatchField[9][9],char Path[])
{
    int i,j,k;
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
            //Block for non-editable Fields (0 to 9)
            NewMatchField[j][k].Number = temp-48;
            if (((temp - 48) >= 1) && ((temp - 48) <= 9))
            {
                NewMatchField[j][k].Color = 15;
                NewMatchField[j][k].Editable = 0;
            }
            //Block for editable Fields
            else
            {
                NewMatchField[j][k].Color = 10;
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
        //Error output: File wasn't coorrect
        return 1;

    }
}

