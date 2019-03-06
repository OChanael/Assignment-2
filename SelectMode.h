#include <iostream>
#include <fstream>

using namespace std;

class Modes
{

  private:
    int generationCount;
    string printString;
    string printFile;

  public:
    Modes(); //constructor
    ~Modes();//destructor

  //game modes
    int MirrorMode(int boardLength, int boardWidth, char**& board);
    int DonutMode(int boardLength, int boardWidth, char**& board);
    int ClassicMode(int boardLength, int boardWidth, char**& board);

    void ModeSelection(int& boardLength, int& boardWidth, char**& board);

    void CreateBoardFile( string inputfile); // creates board from imported file
    void CreateBoardRandom(int& boardLength, int& boardWidth); // creates board from inputted variables
    //void PrintResults(string printMethod, int countGen, char**& board, int boardLength, int boardWidth);
};
