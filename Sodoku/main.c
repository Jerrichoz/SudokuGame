#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

int main()
{

    printf("Hallo Farbe ist Nr.%i", getColour());

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
            SetSodokuField(i,j,testgame,0);
            SetSodokuFieldColor(i,j, testgame, LIGHTGREEN);
            SetSodokuFieldEditability(i,j, testgame, 1);
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

    SetSodokuField(2,2,testgame,8);
    SetSodokuFieldColor(2,2, testgame, WHITE);
    SetSodokuFieldEditability(2,2, testgame, 0);

    SetSodokuField(6,0,testgame,2);
    SetSodokuFieldColor(6,0, testgame, WHITE);
    SetSodokuFieldEditability(6,0, testgame, 0);
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
    GenerateField(testgame);
    menuLoop();
    cursorloop(testgame);
    printf("Test4");

    return 0;
}
