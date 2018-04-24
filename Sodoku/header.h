/*
A SodokuField is a struct, which represents a Sodoku Field.
A SodokuField has a Number and several properties:
    Editable - shows, if the field is editable (1=True 0=False)
    Color - represents the color as an Integer. The function SetConsoleTextAttribute from <windows.h> defines which number belongs to the color.
If The Number is 0, then the Field is treated as Empty
*/
//The struct is defined as SF



typedef struct SodokuField
{
    int Number;
    int Editable;
    int Color;
    int Selected;
} SF;


/*
The function SetSodokuField has 2 Integerparameter. These parameters define the X-Coordinate and the Y-Coordinate (0/0 is Top Left and 8/8 is bottom right).
The third parameter is a 2-dimensional Array of SodokuFields. The Third Parameter is the Value, that the SodokuField on the coordinates X/Y gets.
*/
int SetSodokuField(int xCoordinate, int yCoordinate, SF GameFields[9][9],int Number);
/*
The function GetSodokuField has 2 Integerparameter. These parameters define the X-Coordinate and the Y-Coordinate (0/0 is Top Left and 8/8 is bottom right).
The third parameter is a 2-dimensional Array of SodokuFields. The return-value is the Number of the SodokuField on the coordinates X/Y.
*/
int GetSodokuField(int xCoordinate, int yCoordinate, SF GameFields[9][9]);
/*
The Function displays the matchfield of the Current Game. The Parameter is a 2-dimensional Array of SodokuFields, which is the Base of the Current Game.
*/
int GenerateField(SF GameFields[9][9]);
int cursorloop(SF GameFields[9][9]);
/*
This Function loads one matchfield File. The matchfield is loaded into the parameter NewMatchField. The second Parameter is a the Path for the File, which should be read out.
*/
int LoadMatchfieldFromFile(SF NewMatchField[9][9],char Path[]);

//This Function looks in the path (parameter path) and writes all the Files in the directory into a List (parameter NameList). In the parameter NumberOfListMember will be written, how many Files are found in the directory.

//weder path noch NomberOfListMember funktionieren
int GetDirectoryList(char NameList[100][512], char path[],int *NumberOfListMember);

int setColour(int colour);
int getColour();

int SetSodokuFieldColor(int xCoordinate, int yCoordinate, SF GameFields[9][9],int Color);

int GetSodokuFieldColor(int xCoordinate, int yCoordinate, SF GameFields[9][9]);

int printcoloredNR(int number, int color);

int SetSodokuFieldEditability(int xCoordinate, int yCoordinate, SF GameFields[9][9],int editable);

int GetSodokuFieldEditability(int xCoordinate, int yCoordinate, SF GameFields[9][9]);

int movearrow(int *x,int *y,int direction);

//The parameter decides which instructions should be printed; GAME = 1 and  MENU = 2
int printInstructions(int menuorgame);

int setNumber(SF GameFields[9][9],int number, int x, int y);

// // generates Menu
int generateMenu(int position);
int movemenuPosition(int *x, int direction, int maxMenuLength);
int menuLoop();


//Menu Graphic Functions

int menuGraphic();
int startGameGraphic(int selected);
int startRandomGameGraphic(int selected);
int loadGameGraphic(int selected);
int exitGraphic(int selected);

//Gameloop
int gameloop(int loopvar, SF GameFields[9][9]);
int ChooserLoop(char path[]);

//Color Constants
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

// Sets the appropriate Console Window Settings

int consolewindowsettings();


