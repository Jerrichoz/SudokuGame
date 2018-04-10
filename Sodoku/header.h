// GenerateGrid();
int SetField(int xCoordinate, int yCoordinate, int Array[9][9], int Number);
int GetField(int xCoordinate, int yCoordinate, int Array[9][9]);
int GenerateField(int NumberArray[9][9]);

struct SodokuGameStruct
{
    int NumberArray[9][9];
};
