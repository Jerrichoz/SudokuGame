#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>
#include <time.h>

/*
Name:
int randomGameGen(SF NewMatchField[9][9], int difficulty)
Parameters:
The Gamefield-Struct, the difficulty level of the random Game as an int
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Calls all the function needed to generate the sodoku-field:
Generates an empty Sodoku field with the right properties.
A random array which will be needed in the first 3 diagonal blocks,
that can be filled without using backtracking, because they are independent.
After that the solver generates the rest of the numbers with the backtracking method.
Before setting the editability, the numbers according to the difficulty are removed.
*/
int randomGameGen(SF NewMatchField[9][9], int difficulty)
{
    generateRandomArray();
    genEmptySodoku(NewMatchField);
    genThreeIndependentBlocks(NewMatchField);
    sodokuSolver(NewMatchField);
    numberRemover(NewMatchField, difficulty);
    setSodokuEditabilty(NewMatchField);
    return CURSORLOOP;
}

/*
Name:
int hintSolver(SF NewMatchField[9][9])
Parameters:
The Gamefield-Struct
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
First doubleloop saves all numbers in the backup property of the struct.
After that the sodoku is solved completely.
Second doubleloop saves all numbers in the hint property
and restores through the backup property the sodoku as it was before.
*/
int hintSolver(SF NewMatchField[9][9])
{
    int i,j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            NewMatchField[i][j].Backup = NewMatchField[i][j].Number;
        }
    }
    sodokuSolver(NewMatchField);
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            NewMatchField[i][j].Hint = NewMatchField[i][j].Number;
            NewMatchField[i][j].Number = NewMatchField[i][j].Backup;
        }
    }
    return 0;
}

/*
Name:
int sodokuSolver(SF NewMatchField[9][9])
Parameters:
The Gamefield-Struct
Return Value:
The return decides when the the function is finished, because it calls itself in the own function.
So when a zero is returned, backtracking starts and the function won't stopped until a 1 is returned.
All the self-calls of the function are closed as well.
TL;DR:
Backtracking.
Function:
At first it is checked if there is another numbers which isn't set yet.
When this happens a 1 gets returned and sodoku is solved.
After that a for-loop goes through the numbers 1-9.
The placement of the number is checked by checkRowsAndColumnsAndBlock.
If the number is valid, it is safed in that spot.
After that the selfcall happens in a if-condition and if true(1),
the function itself returns a 1 as well. That's basically all there is to backtracking.
So when the last number isn't valid the if-condition isn't triggered.
After the number is getting reset and the backtrack starts, reseting all the self-called functions before.
Source:
https://www.geeksforgeeks.org/backtracking-set-7-suduku/
*/

int sodokuSolver(SF NewMatchField[9][9])
{
    // //Variables
    //row, column and number are initiliazed
    int row = 0;
    int column = 0;
    int num = 1;

    //if no unassigned number exists, the puzzle is solvedZero returns a 0 for zero problems, no further use.
    //row and column are given as a pointerparameters, so they can be used later
    if(!findUnassigned(NewMatchField, &row, &column))
    {
        //Success
        return 1;
    }
    for(num = 1; num <=  9; num++)
    {
        //if number is valid continue
        if(checkRowsAndColumnsAndBlock(NewMatchField, num, row, column, NewMatchField[row][column].Block))
        {
            //So far no problems, save the number
            NewMatchField[row][column].Number = num;

            if(sodokuSolver(NewMatchField))
            {
                //Success
                return 1;
            }
            //If a problem occurs
            NewMatchField[row][column].Number = 0;

        }
    }
    //Backtrack!
    return 0;
}

/*
Name:
int genEmptySodoku(SF NewMatchField[9][9])
Parameters:
The Gamefield-Struct
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Straight forward, going through the whole struct with 2 for-loops.
Setting all properties that are needed.
*/
int genEmptySodoku(SF NewMatchField[9][9])
{
    // //Variables
    //i,j loopvars
    int i, j;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            NewMatchField[i][j].Block = SetBlockForField(i,j);
            NewMatchField[i][j].Number = 0;
            NewMatchField[i][j].Editable = 1;
            NewMatchField[i][j].Error = 0;
            NewMatchField[i][j].Selected = 0;
            NewMatchField[i][j].Hint = 0;
            NewMatchField[i][j].Backup = 0;
        }
    }
    return 0;
}

/*
Name:
int setSodokuEditabilty(SF NewMatchField[9][9])
Parameters:
The Gamefield-Struct
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Just a double for-loop for setting the editability of all non-zeros to 0
and to 1 if the number is a 0.
*/
int setSodokuEditabilty(SF NewMatchField[9][9])
{
    // //Variables
    //just 2 variables for the loops to go through every number in the struct
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

/*
Name:
int genThreeIndependentBlocks(SF NewMatchField[9][9])
Parameters:
The Gamefield-Struct
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Just a double for-loop for going through every number in the struct.
If it's one of the diagonal blocks, one the random arrays is inserted.
TL;DR:
Generates 3 independent blocks. A smarter solution to start the solver.
*/
int genThreeIndependentBlocks(SF NewMatchField[9][9])
{
    // //Variables
    //i and j standard loopvars for going through the whole struct
    //k, l, m are getting increased when set. Going through the array that way
    int i,j,k,l,m;
    k = 0;
    l = 0;
    m = 0;
    //Generating all 9 numbers for 3 independent/diagonal blocks
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

/*
Name:
int findUnassigned(SF NewMatchField[9][9], int *row, int *column)
Parameters:
The Gamefield-Struct.
Row and column as pointers, so they can be value of the vars can be used afterwards.
Return Value:
If 0 is returned, there is no further number which isn't set.
A 1 as return, means that a non-set number is found.
And the location is returned through the pointers.
Function:
Just a double for-loop for going through every number in the struct.
If the number is a zero, function stops and the location of the number is returned.
*/
int findUnassigned(SF NewMatchField[9][9], int *row, int *column)
{
    for(*row = 0; *row<9; *row+= 1)
    {
        for(*column = 0; *column<9; *column+= 1)
        {
            if(NewMatchField[*row][*column].Number == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

/*
Name:
int checkRowsAndColumnsAndBlock(SF NewMatchField[9][9],int testnumber, int row, int column, int block)
Parameters:
The Gamefield-Struct.
The testnumber, which is going to be tested on validity
The row,column and the block of the number.
Return Value:
If 0 is returned, the number isn't valid
A 1 as return, means that the function didn't stop beforehand.
So everything was tested and the number is valid.
Function:
First, the row, which the number is in, is checked.
If the number with the same value, already exists, function stops and returns a 0.
Secondly, the column, which the number is in, is checked.
If the number with the same value, already exists, function stops and returns a 0.
At last, the block, which the number is in, is checked.
If the number with the same value, already exists, function stops and returns a 0.
If function is completed without being returned with a 0, the number is valid.
*/
int checkRowsAndColumnsAndBlock(SF NewMatchField[9][9],int testnumber, int row, int column, int block)
{
    // //Variables
    //Standard loopvars
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
                    //Number in this block already
                    return 0;
                }
            }
        }
    }
    //If nothing gets returned beforehand, the number is valid!
    return 1;
}

/*
Name:
int generateRandomArray()
Parameters:
None
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Generates a 2-dimensional array with the random numbers(1-9) three times.
Just 3 arrays with random sodoku numbers.
Of course, just every number just once in a sodoku.
Source:
Lottozahlen-Projekt(in Moodle)
*/
int generateRandomArray()
{
    // //Variables
    //i,j,k for the loops
    int i, j, k;
    //boolean as while exit and the generated numbers are saved in compare
    int compare = 0;
    int boolean = 0;


    srand(time(NULL));

    //First for-loop, so that the whole process is repeated 3 times
    for(k = 0; k < 3; k++)
    {

        //Second loop for the array creation
        for(i = 0; i < 9; i++)
        {
            //Do-while loop checks if the numbers occurs more than once
            do
            {

                boolean = 0;

                compare = rand()%9 + 1;

                //Third loop, for checking every existing element
                for(j = 0; j < i; j++)
                {
                    if(compare == rndarray[j][k])
                    {
                        boolean = 1;
                        break;
                    }
                }
            }
            while(boolean == 1);
            //If it doesn't break before, the number is valid and safed.
            rndarray[j][k] = compare;
        }
    }
    return 0;
}

/*
Name:
int numberRemover(SF NewMatchField[9][9], int difficulty)
Parameters:
The Gamefield-Struct, the difficulty level of the random Game as an int.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Pretty simple, a random row and column is choosen.
Afterwards the number is set to 0 and the difficulty is decreased by 1.
So the difficulty-parameter defines the amount of numbers which are removed.
Creating a more difficult Sodoku, with a higher integer value.
*/
int numberRemover(SF NewMatchField[9][9], int difficulty)
{
    // //Variables
    //row and column as integers
    int rownumber;
    int columnnumber;
    //the seed for random generator
    srand(time(NULL));

    do
    {

        rownumber = rand()%9;
        columnnumber = rand()%9;
        if(NewMatchField[rownumber][columnnumber].Number != 0)
        {
            NewMatchField[rownumber][columnnumber].Number = 0;
            difficulty--;
        }

    }
    while(difficulty != 0);


    return 0;
}

/*
Name:
int checkIfSolved(SF GameFields[9][9])
Parameters:
The Gamefield-Struct.
Return Value:
NOTSOLVED is returned if the checksum doesn't add up in one of categories.
Sodoku isn't solved.
SOLVED is returned if the checksum was validated in every category.
Sodoku is solved.
The return values are defines, because to return a 3 and a 4 is confusing.
In that way the meaning of the return values is obvious.
Function:
Row and column are pretty similar.
Each row/column adds the whole row/column up and if the result isn't equal to the checksum,
the functions stops and a NOTSOLVED is returned.
Blocks are basically the same. Just one additional loop, that goes through every existing block.
*/
int checkIfSolved(SF GameFields[9][9])
{
    //Variables
    //Loopvarsa
    int i,j;
    //The addition of every column/row/box has to add up to the checksum
    int checksum = 1+2+3+4+5+6+7+8+9;
    int blocknumber, sum;

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
