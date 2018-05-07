#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

int randomGameGen(SF NewMatchField[9][9])
{
    //int nrarray[8] = {1,2,3,4,5,6,7,8,9};


    return 0;
}


int generateRandomArray()
{
    int lottozahlen[9];
    int vergleich = 0;
    int boolean = 10;
    int i, j;

    //Erste For-Schleife für Array-Zuweisung
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
                if(vergleich == lottozahlen[j])
                {
                    //Doppelte Zahlausgabe zum Testen und Abbruch aus der For-Schleife
                    printf("\t Doppelte Zahl %i\n", vergleich );
                    boolean = 1;
                    break;
                }
            }
        }
        while(boolean == 1);

        lottozahlen[i] = vergleich;
        printf("Zahl %i ist: %i\n", i+1, lottozahlen[i] );

    }
}
