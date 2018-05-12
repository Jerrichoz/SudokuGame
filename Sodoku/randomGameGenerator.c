#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>
#include <time.h>



int randomGameGen(SF NewMatchField[9][9], int difficulty)
{


    generateRandomArray();
    genEmptySodoku(NewMatchField);
    genThreeIndependentBlocks(NewMatchField);
    sodokuSolver(NewMatchField);
    numberRemover(NewMatchField, difficulty);
    setSodokuEditabilty(NewMatchField);
    return 0;
}

//Source:
//https://www.geeksforgeeks.org/backtracking-set-7-suduku/
int sodokuSolver(SF NewMatchField[9][9])
{
    int row = 0;
    int column = 0;
    int num = 1;


    if(findUnassigned(NewMatchField, &row, &column))
    {
        //Success
        //printf("Solved!");
        return 1;
    }
    //printf("Row: %i, Column: %i, Number: %i", column, row, num);
    for(num = 1; num <=  9; num++)
    {
        if(checkRowsAndColumnsAndBlock(NewMatchField, num, row, column, NewMatchField[row][column].Block))
        {
            //So far no problems, save the number
            NewMatchField[row][column].Number = num;
            //printf("Row: %i, Column: %i, Number: %i", column, row, num);
            if(sodokuSolver(NewMatchField))
            {
                //Success
                //printf("Solved!");
                return 1;
            }
            //If a problem occurs, backtrack
            NewMatchField[row][column].Number = 0;
        }
    }
    //Backtrack!
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
            NewMatchField[i][j].Error = 0;

        }
    }
    return 0;
}

int setSodokuEditabilty(SF NewMatchField[9][9])
{
    int i,j;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(NewMatchField[i][j].Number != 0)
            {
                NewMatchField[i][j].Editable = 0;
            }
            else
            {
                NewMatchField[i][j].Editable = 1;
            }
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
    for(*row = 0; *row<9; *row+= 1)
    {
        for(*column = 0; *column<9; *column+= 1)
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

    //First, columns are checked
    for(i=0; i<9; i++)
    {

        if(testnumber == NewMatchField[i][column].Number)
        {
            //testnumber is already in a column
            return 0;
        }
    }
    //Secondly, rows are checked
    for(j=0; j<9; j++)
    {
        if(testnumber == NewMatchField[row][j].Number)
        {
            //testnumber is already in a row
            return 0;
        }
    }
    //At last, the inner box is checked
    for(k=0; k<9; k++)
    {
        for(l=0; l<9; l++)
        {
            if(block == NewMatchField[k][l].Block)
            {

                if(testnumber == NewMatchField[k][l].Number)
                {
                    //printf("Testnumer: %i  MatchfieldNumber: %i",testnumber, NewMatchField[k][l].Number);
                    //Number in this block allrdy
                    return 0;
                }
            }
        }
    }
    //If nothing gets returned beforehand, the number is valid!
    return 1;

}

//Source Lottozahlen-Projekt(in Moodle)
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

int numberRemover(SF NewMatchField[9][9], int difficulty)
{
    int rownumber;
    int columnnumber;
    srand(time(NULL));

    do
    {

        rownumber = rand()%9;
        columnnumber = rand()%9;
        if(NewMatchField[rownumber][columnnumber].Number != 0)
        {
            NewMatchField[rownumber][columnnumber].Hint = NewMatchField[rownumber][columnnumber].Number;
            NewMatchField[rownumber][columnnumber].Number = 0;
            difficulty--;
        }

    }
    while(difficulty != 0);


    return 0;
}

int checkIfSolved(SF GameFields[9][9])
{
    int i,j,sum;
    int checksum = 1+2+3+4+5+6+7+8+9;
    int blocknumber;

    //Columns
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            sum += GameFields[i][j].Number;
            if(j == 8)
            {
                if(sum != checksum)
                {
                    GameFields[i][j].Number = sum;
                    return NOTSOLVED;
                }
                else
                {
                    sum = 0;
                }
            }
        }
    }
    //Rows
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            sum += GameFields[j][i].Number;
            if(j == 8)
            {
                if(sum != checksum)
                {
                    GameFields[j][i].Number = sum;
                    return NOTSOLVED;
                }
                else
                {
                    sum = 0;
                }
            }
        }
    }
    //Blocks
    for(blocknumber = 1; blocknumber < 10; blocknumber=blocknumber + 1)
    {
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                if(GameFields[i][j].Block == blocknumber)
                {
                    sum += GameFields[i][j].Number;

                }
            }
            if((i == 8) && (j == 9))
            {
                if(sum != checksum)
                {
                    GameFields[i][j].Number = sum;
                    return NOTSOLVED;
                }
                else
                {
                    sum = 0;
                }
            }

        }
    }
//Sodoku is solved!
return SOLVED;
}
