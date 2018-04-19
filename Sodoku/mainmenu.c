#include <windows.h>
#include "header.h"
#include <stdio.h>

int genereateMenu()
{
printf("\n");
printf("\t\t\t\t\t\tMM    MM                       \n");
printf("\t\t\t\t\t\tMMM  MMM   eee  nn nnn  uu   uu\n");
printf("\t\t\t\t\t\tMM MM MM ee   e nnn  nn uu   uu\n");
printf("\t\t\t\t\t\tMM    MM eeeee  nn   nn uu   uu\n");
printf("\t\t\t\t\t\tMM    MM  eeeee nn   nn  uuuu u\n\n");

printf("\t\t\t\t\t #       ##  #           #       ##            \n");
printf("\t\t\t\t\t##      #   ###  ## ### ###     #    ## ### ###\n");
printf("\t\t\t\t\t #       #   #  # # #    #      # # # # ### ## \n");
printf("\t\t\t\t\t #        #  ## ### #    ##     # # ### # # ###\n");
printf("\t\t\t\t\t###  #  ##                       ##            \n\n");

printf("\t\t\t\t\t###      ##  #           #      ##            #              ##            \n");
printf("\t\t\t\t\t  #     #   ###  ## ### ###     # #  ## ##  ### ### ###     #    ## ### ###\n");
printf("\t\t\t\t\t###      #   #  # # #    #      ##  # # # # # # # # ###     # # # # ### ## \n");
printf("\t\t\t\t\t#         #  ## ### #    ##     # # ### # # ### ### # #     # # ### # # ###\n");
printf("\t\t\t\t\t###  #  ##                      # #                          ##            \n\n");

printf("\t\t\t\t\t###     #             #      ##             \n");
printf("\t\t\t\t\t  #     #   ###  ## ###     #    ## ### ### \n");
printf("\t\t\t\t\t ##     #   # # # # # #     # # # # ### ##  \n");
printf("\t\t\t\t\t  #     #   ### ### ###     # # ### # # ### \n");
printf("\t\t\t\t\t###  #  ###                  ##             \n\n");

printf("\t\t\t\t\t# #     ###      #   #  \n");
printf("\t\t\t\t\t# #     #   # #     ### \n");
printf("\t\t\t\t\t###     ##   #   #   #  \n");
printf("\t\t\t\t\t  #     #   # #  ##  ## \n");
printf("\t\t\t\t\t  #  #  ###             \n");




    int boolexit = 0;
    while(boolexit != 1)
    {


        if(kbhit()) // Nur wenn auch eine Taste gedrückt ist
        {
            char c = getch(); // Muss auf keine Eingabe warten, Taste ist bereits gedrückt
            switch(c)
            {
            case(50):
                break;
            }
        }
        return 0;
    }
}
