#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

int printInstructions(int footer)
{
    switch(footer)
    {
    case(GAME):
        moveInstructionGame();
        gameInstruction();
        break;
    case(MNMENU):
        moveInstructionMenu();
        break;
    case(MENU):
        moveInstructionMenu();
        escInstruction();
        break;
    case(SOLVED):
        printf("\n\n\n\n");
        printf("CONGRATULATIONS!\n");
        printf("The Sodoku is solved!\n");
        break;
    case(NOTSOLVED):
        printf("\n\n\n\n");
        printf("SORRY!\n");
        printf("The Sodoku is not solved quite yet!\n");
        break;
    }
    return 0;
}

int moveInstructionMenu()
{
    printf("\nINSTRUCTIONS\n");
    FOOTERBORDER
    printf("MOVEMENT:\n");
    printf("UPARROW for UP, DOWNARROW for DOWN\n\n");
    setColour(RED);
    printf("Press ENTER if your destination is marked as RED!\n");
    setColour(WHITE);
    return 0;
}

int moveInstructionGame()
{
    printf("\nINSTRUCTIONS\n");
    FOOTERBORDER
    printf("MOVEMENT:\n");
    printf("UPARROW for UP, DOWNARROW for DOWN, LEFTARROW for LEFT and RIGHTARROW for RIGHT\n\n");
    return 0;
}

int gameInstruction()
{
    printf("NUMBERS:\n");
    printf("0-9 are the only viable Options for a number in this Sodoku!\n\n");
    printf("OPTIONS:\n");
    printf("SAVING with F5 and go back\n");
    printf("Check with c!\n");
    printf("Hint with H");
    printf("\n\n\n\n");
    printf("COLOR EXPLANATION:\n");
    printf("WHITE are the first numbers that were given to solve the Puzzle. Therefore they aren't editable.\n");
    setColour(BLUE);
    printf("BLUE are the numbers, that have to be assigned by you. These are editable.\n");
    setColour(RED);
    printf("RED is the color of your cursor, when you are on editable number.\n");
    setColour(GREEN);
    printf("GREEN is the color of your cursor, when you are on a non-editable number.\n");
    setColour(WHITE);
    return 0;
}

int escInstruction()
{
    printf("\nPress ESC to return to the Main Menu!\n");
    return 0;
}
