/*
A SodokuField is a struct, which represents a Sodoku Field.
A SodokuField has a Number and several properties:
    Editable - shows, if the field is editable (1=True 0=False)
    Color - represents the color as an Integer.
    The function SetConsoleTextAttribute from <windows.h> defines which number belongs to the color.
If The Number is 0, then the Field is treated as Empty
*/
//The struct is defined as SF
typedef struct SodokuField
{
    int Number;
    int Editable;
    int Color;
    int Selected;
    int Block;
} SF;

// This function is in main --> needs to be changed
int gameloop(int loopvar, SF GameFields[9][9]);




// // function.c -Start //rename the file
/*
The Function displays the matchfield of the Current Game.
The Parameter is a 2-dimensional Array of SodokuFields, which is the Base of the Current Game.
COMMENT NEED MAX
*/
int GenerateField(SF GameFields[9][9]);

/*
This Function loads one matchfield File. The matchfield is loaded into the parameter NewMatchField.
The second Parameter is a the Path for the File, which should be read out.
*/
int LoadMatchfieldFromFile(SF NewMatchField[9][9],char Path[]);

//The parameter decides which instructions should be printed; GAME = 1 and  MENU = 2
int printInstructions(int menuorgame);

/*This Function looks in the path (parameter path) and writes all the Files in the directory into a List (parameter NameList).
In the parameter NumberOfListMember will be written, how many Files are found in the directory.
weder path noch NomberOfListMember funktionieren
COMMENT NEED JAN
*/
int GetDirectoryList(char NameList[100][512], char path[],int *NumberOfListMember);

/*
COMMENT NEED JAN
*/
int SetBlockForField(int xCoordinate, int yCoordinate);

// // function.c -End




// // Colour.c -Start

//Sets the textcolor, the parameter decides the color, defines for the colors are below
int setColour(int colour);
//Get the textcolor
int getColour();
/*
Prints the number in the colornumber, which is given through the parameters.
The previous color will still be set afterwards.
*/
int printcoloredNR(int number, int color);

// // Colour.c -End




// // Cursormovement.c -Start
/*
COMMENTS NEED MAX- the ingame loop
*/
int cursorloop(SF GameFields[9][9]);

/*
Moves in the array through keypads (Uparrow, Downarrow, Leftarrow, Rightarrow)
*/
int movearrow(int *x,int *y,int direction);

/*
Gots called in cursorloop and basiclly set the number in the field, which is currently selected.
Necessary parameters, is the matchfield array struct, the number to set in and the coordinates to set it in.
*/
int setNumber(SF GameFields[9][9],int number, int x, int y);

// // Cursormovement.c -End




// // mainmenu.c -Start

/*
The loop of the menu, enables to switch between the menu options
*/
int menuLoop();

/*
Generates the menu graphics and the logic
*/
int generateMenu(int position);

/*
Enables the movement in the mainmenu
*/
int movemenuPosition(int *x, int direction, int maxMenuLength);

/*Each Graphic Function loads a graphic for the menu.
The parameter selected, decides if the current graphic is selected and
changes the color accordingly.
*/
int menuGraphic();
int startGameGraphic(int selected);
int startRandomGameGraphic(int selected);
int loadGameGraphic(int selected);
int exitGraphic(int selected);

// // mainmenu.c -End




// // windowsettings.c -Start

// Sets the appropriate Console Window Settings
int consolewindowsettings();

// // windowsettings.c -End




// // FileChooser.c -Start

/*
COMMENTS NEED JAN
*/
int GenerateChooserList(char NameList[100][512], int NumberOfListMember,int ChooserPosition);

/*
COMMENTS NEED JAN
*/
int ChooserLoop(char path[]);
// // FileChooser.c -End




// // randomgamemenu.c -Start

/*
generates the random game menu loop
*/
int randomGameLoop();

/*
Builds the random game menu
*/
int generateRandomGameMenu(int position);

/*
Random Game Menu Graphics
*/
int menuRndGraphic();
int easyRndGraphic(int selected);
int mediumRndGraphic(int selected);
int hardRndGraphic(int selected);

// // randomgamemenu.c -End



// // randomgameGenerator.c -Start
//Array
int rndarray[9][3];
int randomGameGen(SF NewMatchField[9][9]);

int genEmptySodoku(SF NewMatchField[9][9]);
int genThreeIndependentBlocks(SF NewMatchField[9][9]);
int checkRowsAndColumnsAndBlock(SF NewMatchField[9][9],int testnumber, int row, int column, int block);
// Generates a random array with the numbers 0-9, so filling blocks becomes very easy
int generateRandomArray();
// // randomgameGenerator.c -End


// // Constants
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




