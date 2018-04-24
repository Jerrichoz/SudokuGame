#include <windows.h>
#include "header.h"
#include <stdio.h>
#include <conio.h>


int menuLoop()
{
    int menuPosition = 0;
    generateMenu(menuPosition);

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
                movemenuPosition(&menuPosition, c, 3);
                break;
            //Enter
            case(13):
                switch(menuPosition)
                {
                    //Start Game
                case(0):
                    return 3;
                    break;
                    //Start random Game
                case(1):
                    return 2;
                    break;
                    //Load Game
                case(2):
                    break;
                    //Exit Game
                case(3):
                    return 4;
                    break;
                }
            }
            generateMenu(menuPosition);

        }

    }
    return 0;
}

int generateMenu(int position)
{
    system("cls");
    menuGraphic();
    startGameGraphic(position);
    startRandomGameGraphic(position);
    loadGameGraphic(position);
    exitGraphic(position);
    return 0;
}

int movemenuPosition(int *x, int direction, int maxMenuLength)
{
    switch(direction)
    {
    //Uparrow
    case(72):
        *x -= 1;
        if(*x == -1)
        {
            *x = maxMenuLength;
        }
        break;
    //Downarrow
    case(80):
        *x += 1;
        if(*x == maxMenuLength + 1)
        {
            *x = 0;
        }
        break;
    }
    return 1;
}

int menuGraphic()
{
    int tempcolor;
    tempcolor = getColour();
    setColour(LIGHTMAGENTA);
    printf("\n");
    printf("\t\t\t\t\t\tMM    MM                       \n");
    printf("\t\t\t\t\t\tMMM  MMM   eee  nn nnn  uu   uu\n");
    printf("\t\t\t\t\t\tMM MM MM ee   e nnn  nn uu   uu\n");
    printf("\t\t\t\t\t\tMM    MM eeeee  nn   nn uu   uu\n");
    printf("\t\t\t\t\t\tMM    MM  eeeee nn   nn  uuuu u\n\n");
    setColour(tempcolor);
    return 1;
}

int startGameGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColour();
    if(selected == 0)
    {
        setColour(RED);
    }
    printf("\t\t\t\t\t #       ##  #           #       ##            \n");
    printf("\t\t\t\t\t##      #   ###  ## ### ###     #    ## ### ###\n");
    printf("\t\t\t\t\t #       #   #  # # #    #      # # # # ### ## \n");
    printf("\t\t\t\t\t #        #  ## ### #    ##     # # ### # # ###\n");
    printf("\t\t\t\t\t###  #  ##                       ##            \n\n");
    setColour(tempcolor);
    return 1;
}

int startRandomGameGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColour();
    if(selected == 1)
    {
        setColour(RED);
    }
    printf("\t\t\t\t\t###      ##  #           #      ##            #              ##            \n");
    printf("\t\t\t\t\t  #     #   ###  ## ### ###     # #  ## ##  ### ### ###     #    ## ### ###\n");
    printf("\t\t\t\t\t###      #   #  # # #    #      ##  # # # # # # # # ###     # # # # ### ## \n");
    printf("\t\t\t\t\t#         #  ## ### #    ##     # # ### # # ### ### # #     # # ### # # ###\n");
    printf("\t\t\t\t\t###  #  ##                      # #                          ##            \n\n");
    setColour(tempcolor);
    return 1;
}

int loadGameGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColour();
    if(selected == 2)
    {
        setColour(RED);
    }
    printf("\t\t\t\t\t###     #             #      ##             \n");
    printf("\t\t\t\t\t  #     #   ###  ## ###     #    ## ### ### \n");
    printf("\t\t\t\t\t ##     #   # # # # # #     # # # # ### ##  \n");
    printf("\t\t\t\t\t  #     #   ### ### ###     # # ### # # ### \n");
    printf("\t\t\t\t\t###  #  ###                  ##             \n\n");
    setColour(tempcolor);
    return 1;
}

int exitGraphic(int selected)
{
    int tempcolor;
    tempcolor = getColour();
    if(selected == 3)
    {
        setColour(RED);
    }
    printf("\t\t\t\t\t# #     ###      #   #  \n");
    printf("\t\t\t\t\t# #     #   # #     ### \n");
    printf("\t\t\t\t\t###     ##   #   #   #  \n");
    printf("\t\t\t\t\t  #     #   # #  ##  ## \n");
    printf("\t\t\t\t\t  #  #  ###             \n");
    setColour(tempcolor);
    return 1;
}
