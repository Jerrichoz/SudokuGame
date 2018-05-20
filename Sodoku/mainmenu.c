#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <conio.h>

/*
The loop of the menu, enables to switch between the menu options
*/
int menuLoop()
{
    int menuPosition = 0;
    generateMenu(menuPosition);

    int boolexit = 0;
    while(boolexit != 1)
    {


        if(kbhit()) // Only if a key is hit
        {
            char c = getch(); // get Value for the key, that has been hit
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
Generates the menu graphics and the logic
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
Enables the movement in the mainmenu
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
    return 1;
}
/*
Each Graphic Function loads a graphic for the menu.
The parameter selected, decides if the current graphic is selected and
changes the color accordingly.
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
    return 1;
}

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
    return 1;
}

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
    return 1;
}

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
    return 1;
}
