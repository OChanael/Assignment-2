#include "TerminalNavigation.h"
#include "SelectMode.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>


using namespace std;

TerminalNavigation::TerminalNavigation() //constructor declares variables
{
  string printMethod = "";
  string fileName = "";
  string setting = "";
  bool correctAnswer = false;
  bool wrongChoice = true;
  int generationCount;
}

TerminalNavigation::~TerminalNavigation() //destructor
{

}

Modes m; // accessing functions from SelectMode

void TerminalNavigation::UserInterface()
{
  string setting = "";
  bool WrongChoice = true;
  bool correctAnswer = false;

  while(wrongChoice == true)
  { // how the board is to be printed to the terminal
    cout << "In what manner do you want the data to be printed? (pause, enter, or file)\n" << endl;
    cin >> printMethod;

    if((printMethod == "pause") || (printMethod == "Pause")) // small pause inbetween generations
    {
			wrongChoice = false;
		}
    else if((printMethod == "enter") || (printMethod == "Enter")) // show new generation after enter key is pressed
    {
			wrongChoice = false;
		}
    else if((printMethod == "file") || (printMethod == "File")) // print to file
    {
			cout << "Enter the file you want to print to\n" << endl;
			cin >> outFileName;
			wrongChoice = false;
		}
    else
    {
			cout << "Error. Please type a valid response.\n" << endl;
      wrongChoice = true;
		}
	}

  while(correctAnswer == false) // random board or choose file
  {
    string outFileName = "";

		cout << "Do you want to submit your own file or print a random board? ('random' or 'file')\n" << endl;
		cin >> setting;

		if((setting == "random") || (setting == "Random"))
    {
			int boardLength = 0;
			int boardWidth = 0;

			m.CreateBoardRandom(boardLength, boardWidth); // calls random board creation method from class Modes
			correctAnswer = true;
		}
    else if((setting == "file") || (setting == "File"))
    {
			string fileName;

			cout << "Enter the file you want to use.\n" << endl;
			cin >> fileName;

			m.CreateBoardFile(fileName); // calls file board creation from class Modes

			correctAnswer = true;
		}
    else
    {
			cout << "Error. Please type a valid response.\n" << endl;
			correctAnswer = false;
		}
	}
}

void TerminalNavigation::PrintResults(string printMethod, int generationCount, char**& board, int boardLength, int boardWidth)
{
	bool enter = false; // bool for enter key

	if((printMethod == "pause") || (printMethod == "Pause")) // allows pause option
  {
		sleep(1); // will pause printing for a second before continuing
		cout << "Generation: " << generationCount << "\n";

		for(int i = 0; i < boardLength; ++i) // i for length
    {
			for (int j = 0; j < boardWidth; ++j) // j for width
      {
				cout << board[i][j]; // writes 2d array board to terminal
			}
			cout << "\n";
		}
    // will print when enter key is pressed
	}
  else if((printMethod == "enter") || (printMethod == "Enter")) // enter to continue
  {
		cout << "Press enter key to continue \n" << endl;
		cin.get(); // gets key press rather than text input

		if (cin.get())
    {
			enter = true;
		}

		if (enter = true) // printing generation
    {
			cout << "Generation: " << generationCount << "\n";

			for(int i = 0; i < boardLength; ++i)
      {
				for (int j = 0; j < boardWidth; ++j)
        {
					cout << board[i][j];
				}
				cout << "\n";
			}
		}
	}
}
