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
            SetSodokuFieldColor(i,j, testgame, 10);
            SetSodokuFieldEditability(i,j, testgame, 1);
        }
    }
    printf("Test2");
    SetSodokuField(2,2,testgame,8);
    SetSodokuFieldColor(2,2, testgame, 15);
    SetSodokuFieldEditability(2,2, testgame, 0);
    printf("Farbe vom Feld: %i", GetSodokuFieldColor(2,2, testgame));
    SetSodokuField(6,0,testgame,2);
    SetSodokuFieldColor(6,0, testgame, 15);
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
    GenerateField(testgame);
    cursorloop(testgame);
    printf("Test4");

    return 0;
}
