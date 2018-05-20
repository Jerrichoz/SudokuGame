#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <conio.h>

/*
Name:
int menuLoop()
Parameters:
None
Return Value:
The return value decides which loop is going to be entered as next
or if the game is canceled.
The return values are DEFINES for a better reading.
The values of the defines can be looked up at the bottom of the header-file.
Function:
The main menu graphics are loaded through generateMenu.
Basically it is an endless loop, because boolexit isn't going to be set as 1.
So exiting this loop only is possible through the returns.
The switch case in the switch case is triggered when a key is hit and enter is pressed.
Only then, depending of the option selected, the function stops and returns a value that
decides the next operation.
Moving in the menu is enabled through movemenuPosition.
It's called when the UP or the DOWN-arrow is pressed.
Depending on the direction, the next option selected is marked with the color red.
After a valid key was pressed the menu is generated again to show where the new cursor is at.
*/
int menuLoop()
{
    int menuPosition = 0;
    generateMenu(menuPosition);

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
                movemenuPosition(&menuPosition, c, 3);
                break;
            //Enter
            case(13):
                switch(menuPosition)
                {
                    //Start Game
                case(0):
                    return STRTGAME;
                    break;
                    //Start random Game
                case(1):
                    return RNDGAMEMENU;
                    break;
                    //Load Game
                case(2):
                    return LOADGAME;
                    break;
                    //Exit Game
                case(3):
                    return EXTGAME;
                    break;
                }
            }
            generateMenu(menuPosition);

        }

    }
    return 0;
}

/*
Name:
int generateMenu(int position)
Parameters:
Postion parameter decides which graphic is going to be marked as red
and therefore will be representing the position of the cursor.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
Clears the screen.
Calls all the graphic function needed for the main menu.
At last the printInstructions is called, helping the user
with a guideline how to navigate.
*/
int generateMenu(int position)
{
    system("cls");
    menuGraphic();
    startGameGraphic(position);
    startRandomGameGraphic(position);
    loadGameGraphic(position);
    exitGraphic(position);
    printInstructions(MNMENU);
    return 0;
}

/*
Name:
int movemenuPosition(int *x, int direction, int maxMenuLength)
Parameters:
The position is a pointer, representing the postion of the cursor.
Direction is the ascii-value of which key was hit, UP or DOWN arrow.
The maxMenuLength tells us the amoun of different postions of the menu,
so we can't go out of bound with our cursor.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A switch case, which alters the postions depending on the direction.
If a boundry is hit, the position is restored to the first or last option.
0 Up is decreasing in value
1
2 Down is increasing in value
*/
int movemenuPosition(int *position, int direction, int maxMenuLength)
{
    switch(direction)
    {
    //Uparrow
    case(72):
        *position -= 1;
        if(*position == -1)
        {
            *position = maxMenuLength;
        }
        break;
    //Downarrow
    case(80):
        *position += 1;
        if(*position == maxMenuLength + 1)
        {
            *position = 0;
        }
        break;
    }
    return 0;
}

/*
Name:
int menuGraphic()
Parameters:
None, because it can't be selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic.
*/
int menuGraphic()
{
    int tempcolor;
    tempcolor = getColor();
    setColor(GREEN);
    printf("\n");
    printf("\t\t\t\t\t\tMM    MM                       \n");
    printf("\t\t\t\t\t\tMMM  MMM   eee  nn nnn  uu   uu\n");
    printf("\t\t\t\t\t\tMM MM MM ee   e nnn  nn uu   uu\n");
    printf("\t\t\t\t\t\tMM    MM eeeee  nn   nn uu   uu\n");
    printf("\t\t\t\t\t\tMM    MM  eeeee nn   nn  uuuu u\n\n");
    setColor(tempcolor);
    return 0;
}

/*
Name:
int startGameGraphic(int selected)
Parameters:
Selected parameter marks this graphic as red when this option is selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int startGameGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColor();
    if(selected == 0)
    {
        setColor(RED);
    }
    printf("\t\t\t\t\t #       ##  #           #       ##            \n");
    printf("\t\t\t\t\t##      #   ###  ## ### ###     #    ## ### ###\n");
    printf("\t\t\t\t\t #       #   #  # # #    #      # # # # ### ## \n");
    printf("\t\t\t\t\t #        #  ## ### #    ##     # # ### # # ###\n");
    printf("\t\t\t\t\t###  #  ##                       ##            \n\n");
    setColor(tempcolor);
    return 1;
}

/*
Name:
int startRandomGameGraphic(int selected)
Parameters:
Selected parameter marks this graphic as red when this option is selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int startRandomGameGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColor();
    if(selected == 1)
    {
        setColor(RED);
    }
    printf("\t\t\t\t\t###      ##  #           #      ##            #              ##            \n");
    printf("\t\t\t\t\t  #     #   ###  ## ### ###     # #  ## ##  ### ### ###     #    ## ### ###\n");
    printf("\t\t\t\t\t###      #   #  # # #    #      ##  # # # # # # # # ###     # # # # ### ## \n");
    printf("\t\t\t\t\t#         #  ## ### #    ##     # # ### # # ### ### # #     # # ### # # ###\n");
    printf("\t\t\t\t\t###  #  ##                      # #                          ##            \n\n");
    setColor(tempcolor);
    return 0;
}

/*
Name:
int loadGameGraphic(int selected)
Parameters:
Selected parameter marks this graphic as red when this option is selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int loadGameGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColor();
    if(selected == 2)
    {
        setColor(RED);
    }
    printf("\t\t\t\t\t###     #             #      ##             \n");
    printf("\t\t\t\t\t  #     #   ###  ## ###     #    ## ### ### \n");
    printf("\t\t\t\t\t ##     #   # # # # # #     # # # # ### ##  \n");
    printf("\t\t\t\t\t  #     #   ### ### ###     # # ### # # ### \n");
    printf("\t\t\t\t\t###  #  ###                  ##             \n\n");
    setColor(tempcolor);
    return 0;
}

/*
Name:
int exitGraphic(int selected)
Parameters:
Selected parameter marks this graphic as red when this option is selected.
Return Value:
Zero returns a 0 for zero problems, no further use.
Function:
A bunch of printf's for the graphic
and if selected the color is red.
*/
int exitGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColor();
    if(selected == 3)
    {
        setColor(RED);
    }
    printf("\t\t\t\t\t# #     ###      #   #  \n");
    printf("\t\t\t\t\t# #     #   # #     ### \n");
    printf("\t\t\t\t\t###     ##   #   #   #  \n");
    printf("\t\t\t\t\t  #     #   # #  ##  ## \n");
    printf("\t\t\t\t\t  #  #  ###             \n");
    setColor(tempcolor);
    return 0;
}
