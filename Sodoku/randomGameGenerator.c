#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>
#include <time.h>



int randomGameGen(SF NewMatchField[9][9])
{



    genEmptySodoku(NewMatchField);
    genThreeIndependentBlocks(NewMatchField);
    sodokuSolver(NewMatchField);
    //cursorloop(NewMatchField);
    return 0;
}

//Source:
//https://www.geeksforgeeks.org/backtracking-set-7-suduku/
int sodokuSolver(SF NewMatchField[9][9])
{
    int row = 0;
    int column = 0;
    int num = 1;
    printf("In Solver");


    if(findUnassigned(NewMatchField, &row, &column) == 1)
    {
        //Success
        return 1;
    }

    for(num = 1; num <=  9; num++)
    {
        if(checkRowsAndColumnsAndBlock(NewMatchField, num, row, column, NewMatchField[row][column].Block) == 1)
        {
            //So far no problems, save the number
            NewMatchField[row][column].Number = num;

            if(sodokuSolver(NewMatchField)== 1)
            {
                //Success
                return 1;
            }
            //If a problem occurs
            NewMatchField[row][column].Number = 0;
        }
    }
    printf("Backtrack!!");
    return 0;
}

int genEmptySodoku(SF NewMatchField[9][9])
{
    int i, j;
    //Setting the Blocks and all numbers to zero---auslagern
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            NewMatchField[i][j].Block = SetBlockForField(i,j);
            NewMatchField[i][j].Number = 0;
            NewMatchField[i][j].Editable = 1;

        }
    }
    return 0;
}

int genThreeIndependentBlocks(SF NewMatchField[9][9])
{
    int i,j,k,l,m;
    k = 0;
    l = 0;
    m = 0;

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
    return 0;
}


int findUnassigned(SF NewMatchField[9][9], int *row, int *column)
{
    for(*row=0; *row<9; *row++)
    {
        for(*column=0; *column<9; *column++)
        {
            if(NewMatchField[*row][*column].Number == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int checkRowsAndColumnsAndBlock(SF NewMatchField[9][9],int testnumber, int row, int column, int block)
{
    int i,j,k,l;

    for(i=0; i<9; i++)
    {

        if(testnumber == NewMatchField[i][column].Number)
        {
            //newnumber is alrdy in a row or a column
            return 0;
        }
    }

    for(j=0; j<9; j++)
    {
        if(testnumber == NewMatchField[row][j].Number)
        {
            //newnumber is alrdy in a row or a column
            return 0;
        }
    }
    for(k=0; k<9; k++)
    {
        for(l=0; l<9; l++)
        {
            if(NewMatchField[k][l].Block == block)
            {

                if(testnumber != NewMatchField[k][l].Number)
                {
                    //printf("Testnumer: %i  MatchfieldNumber: %i",testnumber, NewMatchField[k][l].Number);
                    //Number in this block allrdy
                    return 1;
                }
                else
                {
                    //printf("Success");
                    //Success
                    return 0;
                }
            }
        }
    }
    return 3;

}

//Quelle Lottozahlen-Projekt(in Moodle)
int generateRandomArray()
{

    int vergleich = 0;
    int boolean = 0;
    int i, j,k;

    srand(time(NULL));

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
