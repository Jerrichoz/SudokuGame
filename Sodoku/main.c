#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

int main()
{
    //Load Window Settings
    consolewindowsettings();

    //Loopvariable starting in MainMenu
    int loopvar = 1;

    //Testarray erstellen

//    int TestGame[9][9];
    struct SodokuField testgame[9][9];
    int i = 0;
    int j = 0;
//    int Number1;
//    int Number2;

//    changeColour(3);
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//    printf("Test1");
//    changeColour(7);

    //Füllen des Arrays
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            testgame[i][j].Number = 0;
            testgame[i][j].Color = LIGHTGREEN;
            testgame[i][j].Editable = 1;
            if(i == 4 && j == 4)
            {
                testgame[i][j].Selected = 1;
            }
            else
            {
                testgame[i][j].Selected = 0;
            }

        }
    }

    testgame[2][2].Number = 8;
    testgame[2][2].Color = WHITE;
    testgame[2][2].Editable = 0;

    testgame[6][0].Number = 2;
    testgame[6][0].Color = WHITE;
    testgame[6][0].Editable = 0;


//    SetField(1,1,TestGame,1);
//    SetField(3,1,TestGame,3);
//    SetField(5,1,TestGame,7);
//    SetField(7,1,TestGame,5);
//    SetField(0,2,TestGame,5);
//    SetField(1,2,TestGame,4);
//    SetField(7,2,TestGame,7);
//    SetField(8,2,TestGame,6);
    printf("Test3\n");

//    scanf("%i", &Number1);
//    scanf("%i", &Number2);

//    printf("%i\n",GetField(Number1,Number2,TestGame));
    LoadMatchfieldFromFile(testgame,"C:\\Users\\Jan\\Desktop\\Sodoku\\matchfields.txt");

    //Gameloops
    //GenerateField(testgame);
    gameloop(loopvar, testgame);
    //cursorloop(testgame);
    printf("Spiel ist beendet!");

    return 0;
}

int gameloop(int loopvar, SF GameFields[9][9])
{
    int boolexit = 0;
    char path[260];
    while (boolexit != 1)
    {
        switch(loopvar)
        {
        case(0):
            printf("Error. Unknown loop.");
        case(1):
            loopvar = menuLoop();
            break;
        case(2):
            //loopvar = cursorloop(GameFields);
            loopvar = randomGameLoop();
            break;
        case(3):
            loopvar = ChooserLoop(path);
            LoadMatchfieldFromFile(GameFields,path);
            break;
        case(4):
            return 0;
            break;
        case(5):
            break;
        }
    }
    return 0;
}

