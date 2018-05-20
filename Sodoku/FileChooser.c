#include "header.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dirent.h>
//In this file are all functions that are associated with choosing a File or displaying it for the User.

/*
The function displays a chooserlist in the menu.
The parameter "nameList" is a list of the options that are given.
The parameter "numberOfListMemeber" shows the number of elements of the list.
The parameter "chooserPosition" returns the position on which the cursor currently is at.
The returnvalue is always zero.
*/
int generateChooserList(char nameList[100][512], int numberOfListMember,int chooserPosition)
{
    int i = 0;
    //memorize the color
    int tempcolor = getColor();
    system("cls");
    //Layout
    printf("FILES:\n\n");
    for(i = 0; i < numberOfListMember; i++)
    {
        if(i == chooserPosition)
        {
            //Mark the option, that the cursor is at
            setColor(RED);
        }
        printf("%s\n", nameList[i]);
        setColor(tempcolor);
    }
    //print the footer
    printInstructions(FILECHOOSER);
    return 0;
}
/*
The chooserLoop is the loop, in which the user can select a File from a directory.
The parameter "matchName" is the name of the File, that is chosen. This parameter is used in other function (call by value).
The parameter "path" is a string that indicates the path to the directory from which the user can choose a File from.
The parameter "createNewFile" is used as a boolean and indicates if the function should be able to create a new File in the directory.
The return value indicates the next step (loop) in the program (see gameLoop).
*/
int chooserLoop(char matchName[],char path[], int createNewFile)
{
    int chooserPosition = 0;
    char nameList[100][512];
    int numberOfListMember;

    //gets the List from the path
    getDirectoryList(nameList,path,&numberOfListMember,createNewFile);
    //initial display of the directory list
    generateChooserList(nameList,numberOfListMember,chooserPosition);


    while(1)
    {
        if(kbhit()) //Only if key is pressed
        {
            char c = getch();
            switch(c)
            {
            //Movement-keys
            case(72):
            case(80):
                movemenuPosition(&chooserPosition, c,numberOfListMember-1);//-1, because the Position of the first Listmember is 0
                break;
            //Enter-key
            case(13):
                strcpy(matchName, nameList[chooserPosition]);
                return CURSORLOOP;
                break;
            //Escape-key
            case(27):
                return MAINMENU;//it could also be the cursor loop, that depends on how this function is used.
                break;
            }
            generateChooserList(nameList,numberOfListMember,chooserPosition);
        }
    }
}
/*
This function build a list of strings. The list represents the files from a directory.
The parameter "nameList" is used as a return value. This parameter is the list Strings.
The parameter "path" indicates the directory from which the List is build of.
The parameter "numberOfListMember" is used as a return value. It indicates the number of elements of the list.
The maximum number of elements of the List is 99. The last index is reserved for the String "New File".
The parameter "createNewFile" indicates if the String "New File" is added at the bottom of the List.
The return Value is always 0.
*/
int getDirectoryList(char nameList[100][512], char path[],int *numberOfListMember, int createNewFile)
{
    //reading of a directory
    //Source: https://www.unixboard.de/threads/verzeichnis-auslesen-und-dateien-nummerieren-in-c.18416/[17. Juli 2007]
    int i;
    i = 0;
    DIR *dirHandle;
    //from "dirent.h"
    struct dirent * dirEntry;
    //open directory
    dirHandle = opendir(path);
    //if directory is found/is not empty
    if (dirHandle)
    {
        //while there is a next file in the directory or i < 99 (i starts with 0 and is iterated by 1)
        while ((0 != (dirEntry = readdir(dirHandle)))&&(i != 99))
        {
            //"." and ".." should not be displayed
            if(strcmp(dirEntry->d_name, ".")==0 ||
                    strcmp(dirEntry->d_name, "..")==0)
            {
                continue;
            }
            //name is copied in the list
            strcpy(nameList[i],dirEntry->d_name);
            i ++;
        }
        closedir(dirHandle);
        //check if the string "New File" should be added at the bottom of the List
        if (createNewFile)
        {
            strcpy(nameList[i],"New File");
            i++;
        }
        //the number of members of the list is equal to the number of iterations in the while loop
        // + 1 if createNewFile
        *numberOfListMember = i;
    }
    return 0;

}

