/*
A SudokuField is a struct, which represents a Sudoku Field.
A SudokuField has a Number and several properties:
    Editable - shows, if the field is editable (1=True 0=False)
    Color - represents the color as an Integer.
    The function SetConsoleTextAttribute from <windows.h> defines which number belongs to the color.
If The Number is 0, then the Field is treated as Empty
*/
//The struct is defined as SF
typedef struct SudokuField
{
    int Number;
    int Editable;
    int Color;
    int Selected;
    int Block;
    int Error;
    int Hint;
    int Backup;
} SF;

// //main.c -Start
int gameloop();
// //main.c -End

// // Colour.c -Start
int setColor(int color);
int getColor();
int printColoredNR(int number, int color);
// // Colour.c -End

// // Cursormovement.c -Start
int cursorloop(SF gameFields[9][9],char gameName[512],int *passedTimeInS);
int movearrow(int *x,int *y,int direction);
int setNumber(SF gameFields[9][9],int number, int x, int y);
int generateField(SF gameFields[9][9], int instruction, int passedTimeInSeconds, char matchName[512]);
// // Cursormovement.c -End

// // mainmenu.c -Start
int menuLoop();
int generateMenu(int position);
int movemenuPosition(int *x, int direction, int maxMenuLength);
int menuGraphic();
int startGameGraphic(int selected);
int startRandomGameGraphic(int selected);
int loadGameGraphic(int selected);
int exitGraphic(int selected);
// // mainmenu.c -End

// // windowsettings.c -Start
int consolewindowsettings();
// // windowsettings.c -End

// // FileChooser.c -Start
int generateChooserList(char nameList[100][512], int numberOfListMember,int chooserPosition);
int chooserLoop(char matchName[],char path[], int createNewFile);
int getDirectoryList(char nameList[100][512], char path[], int *numberOfListMember, int createNewFile);
// // FileChooser.c -End

// // randomgamemenu.c -Start
int randomGameLoop(int *difficulty);
int generateRandomGameMenu(int position);
int menuRndGraphic();
int easyRndGraphic(int selected);
int mediumRndGraphic(int selected);
int hardRndGraphic(int selected);
// // randomgamemenu.c -End

// // randomgameGenerator.c -Start
int rndarray[9][3];
int randomGameGen(SF newGameField[9][9], int difficulty);
int sodokuSolver(SF newGameField[9][9]);
int findUnassigned(SF newGameField[9][9], int *row, int *column);
int numberRemover(SF newGameField[9][9], int difficulty);
int setSodokuEditabilty(SF newGameField[9][9]);
int checkIfSolved(SF gameFields[9][9]);
int genEmptySodoku(SF newGameField[9][9]);
int genThreeIndependentBlocks(SF newGameField[9][9]);
int checkRowsAndColumnsAndBlock(SF newGameField[9][9],int testnumber, int row, int column, int block);
int generateRandomArray();
int setBlockForField(int xCoordinate, int yCoordinate);
// // randomgameGenerator.c -End

// // instruction.c -Start
int printInstructions(int footer);
int moveInstructionGame();
int moveInstructionMenu();
int gameInstruction();
int escInstruction();
int printNameAndTime(char matchName[512],int passedTimeInSeconds);
// // instruction.c -End

// // SaveGame.c -Start
int saveGame(SF gameField[9][9],int passedTimeInSeconds);
// // SaveGame.c -End

// // LoadGame.c -Start
int loadGameFromFile(char matchName[512], SF gameField[9][9], char path[1024], int *passedTimeInSeconds);
// // LoadGame.c -End

// // Constants -Start
// Colors
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

//  Diffuculty Levels
#define HARD 50
#define MEDIUM 40
#define EASY 30

// Instruction Menu
#define GAME 1
#define MENU 2
#define SOLVED 3
#define NOTSOLVED 4
#define MNMENU 5
#define FILECHOOSER 6

// Loops
#define MAINMENU 1
#define CURSORLOOP 2
#define STRTGAME 3
#define RNDGAME 4
#define RNDGAMEMENU 5
#define EXTGAME 6
#define LOADGAME 7

//Border-Constant
#define BORDER printf("+-------+-------+-------+\n")
#define FOOTERBORDER printf("-------------------------------------------------------------\n");
// // Constants -End

