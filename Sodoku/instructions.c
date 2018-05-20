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
    case(FILECHOOSER):
        moveInstructionMenu();
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
    setColor(RED);
    printf("Press ENTER if your destination is marked as RED!\n");
    setColor(WHITE);
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
    setColor(BLUE);
    printf("BLUE are the numbers, that have to be assigned by you. These are editable.\n");
    setColor(RED);
    printf("RED is the color of your cursor, when you are on editable number.\n");
    setColor(GREEN);
    printf("GREEN is the color of your cursor, when you are on a non-editable number.\n");
    setColor(WHITE);
    return 0;
}

int escInstruction()
{
    printf("\nPress ESC to return to the Main Menu!\n");
    return 0;
}

int printNameAndTime(char matchName[512],int passedTimeInSeconds)
{
    int hours,minutes,seconds;
    printf("%i",passedTimeInSeconds);//431Seconds 424 Secodns angezeigt

    seconds = passedTimeInSeconds%60;
    passedTimeInSeconds = passedTimeInSeconds - seconds;
    passedTimeInSeconds = passedTimeInSeconds/60;
    minutes = passedTimeInSeconds%60;
    passedTimeInSeconds = passedTimeInSeconds - minutes;
    passedTimeInSeconds = passedTimeInSeconds/60;
    hours = passedTimeInSeconds;
    printf("%s - TIME:   %i:%i:%i\n",matchName,hours,minutes,seconds);
    return 0;
}
