#include <windows.h>
#include <stdio.h>
#include "header.h"

int checkFilledGrid(SF GameFields[9][9])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            int number = 0;
            number = GameFields[j][i].Number;

            int tempArray[10];

            int numberArray[9] = {1,2,3,4,5,6,7,8,9};

            tempArray[0] = number; // tempArray filled with rows and columns firstly

            if(tempArray[0] == numberArray[j])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}
