#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>
//This function includes all Files that are needed to display and use the Menu for the random game generator.

/*
Name:
int randomGameLoop(SF GameFields[9][9], int *difficulty)
Parameters:
The difficulty level of the random Game as an integer pointer, so the value can be passed on.
Return Value:
The return value decides whether a random game is started, or returned to the main menu.
Function:
At first a function is called, responsible for the generation of the menu graphics.
A menu loop for the random game.
Like the other menu loops, this reacts as well to the UP and DOWN Arrow Keys.
And changes the color of the option selected.
The first switch case reacts to which button was entered and if
Enter is entered the next switch case decides which value of the
difficulty pointer will be returned, depending on the difficulty level.
*/
int randomGameLoop(int *difficulty)
{
    int menuPosition = 0;
    generateRandomGameMenu(menuPosition);

    int boolexit = 0;
    while(boolexit != 1)
    {
        // Only if a key is hit
        if(kbhit())
        {
            // get Value for the key, that has been hit
            char c = getch();
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
                    return RNDGAME;
                    break;
                //Medium random Game
                case(1):
                    *difficulty = MEDIUM;
                    return RNDGAME;
                    break;
                //Hard random Game
                case(2):
                    *difficulty = HARD;
                    return RNDGAME;
                    break;
                }
            //Exit to the Main Menu
            case(27):
                return MAINMENU;
                break;
            }
            generateRandomGameMenu(menuPosition);
        }

    }
    return 0;
}

/*
Name:
int generateRandomGameMenu(int position)
Parameters:
The position parameter tells on which graphic the cursor is right now, by changing the color of that graphic.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Clears the screen.
Calls all the graphic function needed for that menu
and the printInstructions function as well.
*/
int generateRandomGameMenu(int position)
{
    system("cls");
    menuRndGraphic(position);
    easyRndGraphic(position);
    mediumRndGraphic(position);
    hardRndGraphic(position);
    printInstructions(MENU);
    return 0;
}

/*
Name:
int menuRndGraphic()
Parameters:
None, because this graphic can't be selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int menuRndGraphic()
{
    int tempcolor;
    tempcolor = getColor();
    setColor(GREEN);
    printf("\t\tRRRRRR                       dd                       GGGG                            \n");
    printf("\t\tRR   RR   aa aa nn nnn       dd  oooo  mm mm mmmm    GG  GG   aa aa mm mm mmmm    eee \n");
    printf("\t\tRRRRRR   aa aaa nnn  nn  dddddd oo  oo mmm  mm  mm  GG       aa aaa mmm  mm  mm ee   e\n");
    printf("\t\tRR  RR  aa  aaa nn   nn dd   dd oo  oo mmm  mm  mm  GG   GG aa  aaa mmm  mm  mm eeeee \n");
    printf("\t\tRR   RR  aaa aa nn   nn  dddddd  oooo  mmm  mm  mm   GGGGGG  aaa aa mmm  mm  mm  eeeee\n");
    printf("\n\n");
    setColor(tempcolor);
    return 0;
}

/*
Name:
int easyRndGraphic(int selected)
Parameters:
Selected parameter marks this graphic as red when this option is selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int easyRndGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColor();
    if(selected == 0)
    {
        setColor(RED);
    }
    printf("\tEEEEEEE                      \n");
    printf("\tEE        aa aa  sss  yy   yy\n");
    printf("\tEEEEE    aa aaa s     yy   yy\n");
    printf("\tEE      aa  aaa  sss   yyyyyy\n");
    printf("\tEEEEEEE  aaa aa     s      yy\n");
    printf("\t                 sss   yyyyy \n");
    printf("\n\n");
    setColor(tempcolor);
    return 0;
}

/*
Name:
int mediumRndGraphic(int selected)
Parameters:
Selected parameter marks this graphic as red when this option is selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int mediumRndGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColor();
    if(selected == 1)
    {
        setColor(RED);
    }
    printf("\tMM    MM             dd iii                    \n");
    printf("\tMMM  MMM   eee       dd     uu   uu mm mm mmmm \n");
    printf("\tMM MM MM ee   e  dddddd iii uu   uu mmm  mm  mm\n");
    printf("\tMM    MM eeeee  dd   dd iii uu   uu mmm  mm  mm\n");
    printf("\tMM    MM  eeeee  dddddd iii  uuuu u mmm  mm  mm\n");
    printf("\n\n");
    setColor(tempcolor);
    return 0;
}

/*
Name:
int hardRndGraphic(int selected)
Parameters:
Selected parameter marks this graphic as red when this option is selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int hardRndGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColor();
    if(selected == 2)
    {
        setColor(RED);
    }
    printf("\tHH   HH                     dd\n");
    printf("\tHH   HH   aa aa rr rr       dd\n");
    printf("\tHHHHHHH  aa aaa rrr  r  dddddd\n");
    printf("\tHH   HH aa  aaa rr     dd   dd\n");
    printf("\tHH   HH  aaa aa rr      dddddd\n");
    printf("\n\n");
    setColor(tempcolor);
    return 0;

}
