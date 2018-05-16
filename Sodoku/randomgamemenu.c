#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

// need to implement exit from the random menu

/*
Name:
int randomGameLoop(SF GameFields[9][9], int *difficulty)
Parameters:
The Gamefield-Struct.
The difficulty level of the random Game as an integer pointer, so the value can be passed on.
Return Value:

Function:
Calls all the function needed to generate the sodoku-field:
Generates an empty Sodoku field with the right properties.
A random array which will be needed in the first 3 diagonal blocks,
that can be filled without using backtracking, because they are independent.
After that the solver generates the rest of the numbers with the backtracking method.
Before setting the editability, the numbers according to the difficulty are removed.
*/
int randomGameLoop(SF GameFields[9][9], int *difficulty)
{
    int menuPosition = 0;
    generateRandomGameMenu(menuPosition);

    int boolexit = 0;
    while(boolexit != 1)
    {


        if(kbhit()) // Nur wenn auch eine Taste gedrückt ist
        {
            char c = getch(); // Muss auf keine Eingabe warten, Taste ist bereits gedrückt
            switch(c)
            {
            //Movement
            case(72):
            case(80):
                movemenuPosition(&menuPosition, c, 2);
                break;
            //Enter
            case(13):
                switch(menuPosition)
                {
                //Easy random Game
                case(0):
                    *difficulty = EASY;
                    return 4;
                    break;
                //Medium random Game
                case(1):
                    *difficulty = MEDIUM;
                    return 4;
                    break;
                //Hard random Game
                case(2):
                    *difficulty = HARD;
                    return 4;
                    break;
                //Exit Game
                case(27):

                    break;
                }
            }
            generateRandomGameMenu(menuPosition);

        }

    }
    return 0;
}

int generateRandomGameMenu(int position)
{
    system("cls");
    menuRndGraphic(position);
    easyRndGraphic(position);
    mediumRndGraphic(position);
    hardRndGraphic(position);
    return 0;
}
int menuRndGraphic()
{
    int tempcolor;
    tempcolor = getColour();
    setColour(GREEN);
    printf("\t\tRRRRRR                       dd                       GGGG                            \n");
    printf("\t\tRR   RR   aa aa nn nnn       dd  oooo  mm mm mmmm    GG  GG   aa aa mm mm mmmm    eee \n");
    printf("\t\tRRRRRR   aa aaa nnn  nn  dddddd oo  oo mmm  mm  mm  GG       aa aaa mmm  mm  mm ee   e\n");
    printf("\t\tRR  RR  aa  aaa nn   nn dd   dd oo  oo mmm  mm  mm  GG   GG aa  aaa mmm  mm  mm eeeee \n");
    printf("\t\tRR   RR  aaa aa nn   nn  dddddd  oooo  mmm  mm  mm   GGGGGG  aaa aa mmm  mm  mm  eeeee\n");
    printf("\n\n");
    setColour(tempcolor);
    return 0;
}

int easyRndGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColour();
    if(selected == 0)
    {
        setColour(RED);
    }
    printf("\tEEEEEEE                      \n");
    printf("\tEE        aa aa  sss  yy   yy\n");
    printf("\tEEEEE    aa aaa s     yy   yy\n");
    printf("\tEE      aa  aaa  sss   yyyyyy\n");
    printf("\tEEEEEEE  aaa aa     s      yy\n");
    printf("\t                 sss   yyyyy \n");
    printf("\n\n");
    setColour(tempcolor);
    return 1;
}

int mediumRndGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColour();
    if(selected == 1)
    {
        setColour(RED);
    }
    printf("\tMM    MM             dd iii                    \n");
    printf("\tMMM  MMM   eee       dd     uu   uu mm mm mmmm \n");
    printf("\tMM MM MM ee   e  dddddd iii uu   uu mmm  mm  mm\n");
    printf("\tMM    MM eeeee  dd   dd iii uu   uu mmm  mm  mm\n");
    printf("\tMM    MM  eeeee  dddddd iii  uuuu u mmm  mm  mm\n");
    printf("\n\n");
    setColour(tempcolor);
    return 1;
}

int hardRndGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColour();
    if(selected == 2)
    {
        setColour(RED);
    }
    printf("\tHH   HH                     dd\n");
    printf("\tHH   HH   aa aa rr rr       dd\n");
    printf("\tHHHHHHH  aa aaa rrr  r  dddddd\n");
    printf("\tHH   HH aa  aaa rr     dd   dd\n");
    printf("\tHH   HH  aaa aa rr      dddddd\n");
    printf("\n\n");
    setColour(tempcolor);
    return 1;

}
