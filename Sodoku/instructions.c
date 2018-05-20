#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>
//In this File are all Funtions, that display instructions and the Time/matchname of the current game.

/*
This function prints the instructions for the current situation as a footer.
The parameter footer indicates the current status of the Program. The statuses are explained in the Header.h.
*/
int printInstructions(int footer)
{
    switch(footer)
    {
    case(GAME):
        moveInstructionGame();
        gameInstruction();
        escInstruction();
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
//This function prints the footer for menus
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
//This function prints the instructions for the cursor
int moveInstructionGame()
{
    printf("\nINSTRUCTIONS\n");
    FOOTERBORDER
    printf("MOVEMENT:\n");
    printf("UPARROW for UP, DOWNARROW for DOWN, LEFTARROW for LEFT and RIGHTARROW for RIGHT\n\n");
    return 0;
}
//This function prints the key-instructions for the cursorloop
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
//This function prints the instruction how to return to the menu
int escInstruction()
{
    printf("\nPress ESC to return to the Main Menu!\n");
    return 0;
}

/*
This function prints the Name of the File, which the game is based on or Random if it is generated.
This function prints the Time that the user spend with the current game.
*/
int printNameAndTime(char matchName[512],int passedTimeInSeconds)
{
    int hours,minutes,seconds;
    //define passed seconds
    seconds = passedTimeInSeconds%60;
    passedTimeInSeconds = passedTimeInSeconds - seconds;
    //one Minute has 60 seconds
    passedTimeInSeconds = passedTimeInSeconds/60;
    //define passed minutes
    minutes = passedTimeInSeconds%60;
    passedTimeInSeconds = passedTimeInSeconds - minutes;
    //one hour has 60 minutes
    passedTimeInSeconds = passedTimeInSeconds/60;
    //define hours
    hours = passedTimeInSeconds;
    printf("%s - TIME:   %i:%i:%i\n",matchName,hours,minutes,seconds);
    return 0;
}
