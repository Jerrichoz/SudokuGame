#include <windows.h>
#include "header.h"

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


