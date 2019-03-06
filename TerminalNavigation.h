#include <iostream>
#include <fstream>

using namespace std;

class TerminalNavigation
{

private:
  string printMethod;
  string outFileName;
  string setting;
  bool correctAnswer;
  bool wrongChoice;
  int generationCount;

public:
  TerminalNavigation();//constructor
  ~TerminalNavigation();//destructor

  void UserInterface();
  void PrintResults(string printMethod, int generationCount, char**& board, int boardLength, int boardWidth);
};
