#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

int randomGameGen(SF NewMatchField[9][9])
{
    //Variables
    //Loop Vars
    int i,j,k,l,m;
    k = 0;
    l = 0;
    m = 0;

    //Setting the Blocks ---auslagern
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            NewMatchField[i][j].Block = SetBlockForField(i,j);
        }
    }

    //Generating all 9 numbers for 3 independent blocks
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(NewMatchField[i][j].Block == 1)
            {
                NewMatchField[i][j].Number = rndarray[k][0];
                k++;
            }
            else if(NewMatchField[i][j].Block == 5)
            {
                NewMatchField[i][j].Number = rndarray[l][1];
                l++;
            }
            else if(NewMatchField[i][j].Block == 9)
            {
                NewMatchField[i][j].Number = rndarray[m][2];
                m++;
            }
        }
    }
    printf("Test");
    cursorloop(NewMatchField);

    return 0;
}


//Quelle Lottozahlen-Projekt(in Moodle)
int generateRandomArray()
{

    int vergleich = 0;
    int boolean = 0;
    int i, j,k;

    //Erste For-Schleife für Array-Zuweisung
    for(k = 0; k < 3; k++)
    {


        for(i = 0; i < 9; i++)
        {
            //Erste Do zur Überprüfung ob zahl doppelt vorhanden ist
            do
            {

                boolean = 0;

                vergleich = rand()%9 + 1;

                //Zweite for um jedes vorhandene element zu überprüfen
                for(j = 0; j < i; j++)
                {
                    if(vergleich == rndarray[j][k])
                    {
                        boolean = 1;
                        break;
                    }
                }
            }
            while(boolean == 1);

            rndarray[j][k] = vergleich;
            //printf("Zahl %i ist: %i\n", i+1, rndarray[j][k] );



        }
    }
    return 0;
}
