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

            int numberArray[9] = {1,2,3,4,5,6,7,8,9};

            //Zeile
            if(number == GameFields[j][0].Number)
            {
                printf("Der Wert ist bereits vorhanden!");
                return true;
            }
            else
            {
                printf("Der Wert ist noch nicht vorhanden!");
                return false;
            }
            //Spalte
            if(number == GameFields[0][i].Number)
            {
                printf("Der Wert ist bereits vorhanden!");
                return true;
            }
            else
            {
                printf("Der Wert ist noch nicht vorhanden!");
                return false;
            }
            //Block
            if(number == GameFields[j][i].Block)
            {
                printf("Der Wert ist bereits vorhanden!");
                return true;
            }
            else
            {
                printf("Der Wert ist noch nicht vorhanden!");
                return false;
            }
        }
    }
}
