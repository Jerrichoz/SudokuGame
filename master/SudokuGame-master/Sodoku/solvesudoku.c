#include <windows.h>
#include <stdio.h>
#include "header.h"

int checkFilledGrid(SF GameFields[9][9])
{
    int i = 0;
    int j = 0;

    int true = 1;
    int false = 0;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            int number = 0;
            number = GameFields[j][i].Number;

            //int numberArray[9] = {1,2,3,4,5,6,7,8,9};

            //Zeile
            if(number != GameFields[j][i].Number)
            {
                printf("\n\nDer Wert ist noch nicht vorhanden!\n\n");
                return true;
            }
            else
            {
                printf("\n\nDer Wert ist bereits vorhanden!\n\n");
                return false;
            }
            //Spalte
            if(number != GameFields[j][i].Number)
            {
                printf("\n\nDer Wert ist noch nicht vorhanden!\n\n");
                return true;
            }
            else
            {
                printf("\n\nDer Wert ist bereits vorhanden!\n\n");
                return false;
            }
            //Block
            if(number != GameFields[j][i].Block)
            {
                printf("\n\nDer Wert ist noch nicht vorhanden!\n\n");
                return true;
            }
            else
            {
                printf("\n\nDer Wert ist bereits vorhanden!\n\n");
                return false;
            }
        }
    }
}
