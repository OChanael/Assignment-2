#include "SelectMode.h"
#include "TerminalNavigation.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

Modes::Modes() // constructor declaring variables
{
  int generationCount;
  string printString = "";
  string printFile = "";
}

Modes::~Modes() // destructor
{

}


TerminalNavigation t; // used as an attempt to call PrintResults

// modes are placed here so other functions know how to call them
int Modes::ClassicMode(int boardLength, int boardWidth, char**& board) // classic mode
{
  //TerminalNavigation t; no effect
	int count = 0; // internal counter to check if cells are next to each other or not
	bool stable = false; // used to check if simulation has room for change or not
  generationCount = 1; // initial generation counter

    char** newGeneration = new char*[boardLength]; // creates second board from first board dimensions

    for (int i = 0; i < boardLength; ++i)
    {
    	newGeneration[i] = new char[boardWidth];
    }

    while(stable == false) // creating 2d array
    {
	    for (int i = 0; i < boardLength; ++i) // i is for length
      {
    	    for (int j = 0; j < boardWidth; ++j) // j is for width
          {
        	    count = 0;
            	if (i == 0 && j == 0) // starting cell checking
              {
                if (board[i+1][j] == 'X') count++;
	              if (board[i][j+1] == 'X') count++;
    	          if (board[i+1][j+1] == 'X') count++;
        	    }
            	else if (i == 0 && j == (boardWidth - 1))
              {
                if (board[i+1][j] == 'X') count++;
            	  if (board[i][j-1] == 'X') count++;
                if (board[i+1][j-1] == 'X') count++;
	            }
    	        else if (i == (boardLength - 1) && j == 0)
              {
        	      if (board[i-1][j] == 'X') count++;
            	  if (board[i][j+1] == 'X') count++;
                if (board[i-1][j+1] == 'X') count++;
	            }
    	        else if (i == (boardLength - 1) && j == (boardWidth - 1))
              {
        	      if (board[i-1][j] == 'X') count++;
            	  if (board[i][j-1] == 'X') count++;
                if (board[i-1][j-1] == 'X') count++;
	            }
        	    else if (i == 0) // checks sides
              {
            	  if (board[i+1][j] == 'X') count++;
	              if (board[i][j+1] == 'X') count++;
    	          if (board[i+1][j+1] == 'X') count++;
        	      if (board[i][j-1] == 'X') count++;
	              if (board[i+1][j-1] == 'X') count++;
    	        }
        	    else if (j == 0)
              {
            	  if (board[i-1][j] == 'X') count++;
                if (board[i+1][j] == 'X') count++;
	              if (board[i][j+1] == 'X') count++;
    	          if (board[i+1][j+1] == 'X') count++;
        	      if (board[i-1][j+1] == 'X') count++;
            	}
	            else if (i == (boardLength - 1))
              {
                if (board[i-1][j] == 'X') count++;
        	      if (board[i][j+1] == 'X') count++;
            	  if (board[i-1][j+1] == 'X') count++;
	              if (board[i][j-1] == 'X') count++;
    	          if (board[i-1][j-1] == 'X') count++;
        	    }
            	else if(j == (boardWidth - 1))
              {
                if (board[i-1][j] == 'X') count++;
	              if (board[i+1][j] == 'X') count++;
    	          if (board[i][j-1] == 'X') count++;
        	      if (board[i+1][j-1] == 'X') count++;
            	  if (board[i-1][j-1] == 'X') count++;
	            }
    	        else
              {
                if(board[i+1][j] == 'X') count++;
					      if(board[i][j+1] == 'X') count++;
					      if(board[i+1][j+1] == 'X') count++;
					      if(board[i][j-1] =='X') count++;
		            if(board[i-1][j] == 'X') count++;
					      if(board[i-1][j-1] == 'X') count++;
					      if(board[i+1][j-1] =='X') count++;
					      if(board[i-1][j+1] == 'X') count++;
				       }
        		if (count < 2)
            {
	            newGeneration[i][j] = '-'; // kills cell if one or fewer neighbors
    	    	}
        		else if (count == 2)
            {
              newGeneration[i][j] = board[i][j]; // if exactly two neighbors, no change
	        	}
    	    	else if (count == 3)
            {
              newGeneration[i][j] = 'X'; // creates cell if it has three neighbors and an empty space
        		}
        		else if (count > 3)
            {
              newGeneration[i][j] = '-'; // overloads to death if four or more neighbors
        		}
        	}
        }
        int checker = 0;

        for (int i = 0; i <boardLength; ++i)
        {
       		for (int j = 0; j < boardWidth; ++j)
          {
	       		if (newGeneration[i][j] == board[i][j])
            {
	       			checker++;
	          }
           		else
              {
           			stable = false;
         		  }
       		 }
    	   }

    	if (checker == (boardLength*boardWidth))
      {
    		stable = true; // assigns stable to true, halts creation of more generations
    		cout << "\nThis generation is stable, there can be no more changes." << endl;
    	}

    	if (stable == false) //
      {
        std::stringstream sstm; // uses std prefix to manually cast back to sstream, does not work otherwise
    		sstm << "Generation: " << generationCount << "\n";
        printString += sstm.str();

        if (generationCount == 1)
        {
          for(int i = 0; i < boardLength; ++i)
          {
      		  for(int j = 0; j < boardWidth; ++j)
            {
      			  std::stringstream sstm;
   						sstm << board[i][j];
   					  printString += sstm.str();
   					}
            std::stringstream sstm;
   				  sstm << "\n";
   				  printString += sstm.str();
  				 }
           // same as before, attempting to call method
           t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);

           for(int i = 0; i < boardLength; ++i)
           {
             for(int j = 0; j < boardWidth; ++j)
             {
      			   board[i][j] = newGeneration[i][j]; // assigns end result of board to new generation
             }
      		 }
        }
        else
        {
          for(int i = 0; i < boardLength; ++i)
          {
            for(int j = 0; j < boardWidth; ++j)
            {
              board[i][j] = newGeneration[i][j];
      			  std::stringstream sstm;
      		 	  sstm << board[i][j];
      			  printString += sstm.str();
            }
              std::stringstream sstm;
              sstm << "\n";
              printString += sstm.str();
          }
              // intention is to call the method from TerminalNavigation.cpp
            t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
              // cannot recognize printMethod, is the source of the issue
      		 }
    	 }
       generationCount++;
    }

    if(printFile != "") // opens and prints results to file if supplied
    {
      ofstream outputFile;
    	outputFile.open(printFile.c_str());
    	outputFile << printString << "\n";
    	outputFile.close();
	  }
    return 0;
}

int Modes::DonutMode(int boardLength, int boardWidth, char**& board)
{
  //TerminalNavigation t; no effect
	int count = 0;
	generationCount = 1;
	bool stable = false;

    char** newGeneration = new char*[boardLength]; // creates second board from first board dimensions

    for (int i = 0; i < boardLength; ++i)
    {
      newGeneration[i] = new char[boardWidth];
    }

    while(stable == false)
    {
   		for(int i = 0; i < boardLength; ++i)
      {
			for(int j = 0; j < boardWidth; ++j)
      {
				count = 0;
				if (i == 0 && j == 0) // donut shape logic
        {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[boardLength-1][j] == 'X') count++; // bottom of row and same column connect
					if(board[boardLength-1][j+1] == 'X') count++; // bottom row and bottom column +1 connect
					if(board[boardLength-1][boardWidth-1] == 'X') count++; // opposite corner connect
					if(board[i][boardWidth-1] == 'X') count++; // opposite side connect
					if(board[i+1][boardWidth-1] == 'X') count++; // opposite side and down one connect
				}
				else if (i == 0 && j == (boardWidth - 1))
        {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j-1] == 'X') count++;
					if(board[i+1][j-1] == 'X') count++;
					if(board[boardLength-1][j] == 'X') count++;
					if(board[boardLength-1][j-1] == 'X') count++;
					if(board[boardLength-1][0] == 'X') count++;
					if(board[i][0] == 'X') count++; // opposite corner
					if(board[i+1][0] == 'X') count++;
				}
				else if (i == (boardLength - 1 ) && j == (boardWidth - 1))
        {
					if(board[i-1][j] == 'X') count++;
					if(board[i][j-1] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[0][j-1] == 'X') count++;
					if(board[0][j] == 'X') count++;
					if(board[0][0] == 'X') count++;
					if(board[i][0] == 'X') count++;
					if(board[i-1][0] == 'X') count++;
				}
				else if (i == (boardLength - 1) && j == 0)
        {
					if(board[i-1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i-1][j+1] == 'X') count++;
					if(board[0][j] == 'X') count++;
					if(board[0][j+1] == 'X') count++;
					if(board[0][boardWidth-1] == 'X') count++;
					if(board[i-1][boardWidth-1] == 'X') count++;
					if(board[i][boardWidth-1] == 'X') count++;
				}
				else if (j == 0)
        {
					if(board[i-1][j] == 'X') count++;
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i-1][j+1] == 'X') count++;
					if(board[i-1][boardWidth-1] == 'X') count++;
					if(board[i][boardWidth-1] == 'X') count++;
					if(board[i+1][boardWidth-1] == 'X') count++;
				}
				else if (i == 0)
        {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count++;
					if(board[i+1][j-1] == 'X') count++;
					if(board[boardLength-1][j-1] == 'X') count++;
					if(board[boardLength-1][j] == 'X') count++;
					if(board[boardLength-1][j+1] == 'X') count++;
        }
        else if (i == (boardLength - 1))
        {
					if(board[i-1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i-1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[0][j-1] == 'X') count++;
					if(board[0][j] == 'X') count++;
					if(board[0][j+1] == 'X') count++;
				}
				else if (j == (boardWidth - 1))
        {
					if(board[i-1][j] == 'X') count++;
					if(board[i+1][j] == 'X') count++;
					if(board[i][j-1] == 'X') count++;
					if(board[i+1][j-1] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i-1][0] == 'X') count++;
					if(board[i][0] == 'X') count++;
					if(board[i+1][0] == 'X') count++;
				}
				else
        {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count++;
					if(board[i-1][j] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i+1][j-1] =='X') count++;
					if(board[i-1][j+1] == 'X') count++;
				}
        		if (count < 2)
            {
           			newGeneration[i][j] = '-'; // kills cell if one or fewer neighbors
        		}
	        	else if (count == 2)
            {
        	    	newGeneration[i][j] = board[i][j]; // if exactly two neighbors, no change
        		}
	        	else if (count == 3)
            {
        	    	newGeneration[i][j] = 'X'; // creates cell if it has three neighbors and an empty space
        		}
        		else if (count > 3)
            {
            		newGeneration[i][j] = '-'; // overloads to death if four or more neighbors
        		}
        	}
    	}

        int checker = 0;

        for (int i = 0; i <boardLength; ++i)
        {
       		for (int j = 0; j < boardWidth; ++j)
          {
	       		if (newGeneration[i][j] == board[i][j])
            {
	       			checker++;
	          }
           		else
              {
           			stable = false;
         		  }
       		 }
    	   }

    	if (checker == (boardLength*boardWidth))
      {
    		stable = true;
    		cout << "\nThis generation is stable, there can be no more changes." << endl;
    	}
     	if (stable == false)
      {
    		std::stringstream sstm;
    		sstm << "Generation: " << generationCount << "\n";
            printString += sstm.str();

            if (generationCount == 1)
            {
            	for(int i = 0; i < boardLength; ++i)
              {
      				for(int j = 0; j < boardWidth; ++j)
              {
      					std::stringstream sstm;
   						sstm << board[i][j];
   						printString += sstm.str();
   					  }
   					std::stringstream sstm;
   					sstm << "\n";
   					printString += sstm.str();
  				    }
              // and again
            	t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);

            	for(int i = 0; i < boardLength; ++i)
              {
      				for(int j = 0; j < boardWidth; ++j)
              {
      					board[i][j] = newGeneration[i][j];
      				}
      			  }

            }
            else
            {

            	for(int i = 0; i < boardLength; ++i)
              {
      				for(int j = 0; j < boardWidth; ++j)
              {
      					board[i][j] = newGeneration[i][j];
      					std::stringstream sstm;
      					sstm << board[i][j];
      					printString += sstm.str();
      				}
      				std::stringstream sstm;
   					sstm << "\n";
   					printString += sstm.str();
      			  }
              // and again
      			t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
      		  }
    	  }

    	generationCount++;
    }

    if(printFile != "")
    {
    	ofstream outputFile;
    	outputFile.open(printFile.c_str());
    	outputFile << printString << "\n";
    	outputFile.close();
	  }
    return 0;
}

int Modes::MirrorMode(int boardLength, int boardWidth, char**& board)
{
  //TerminalNavigation t; no effect
	int count = 0;
	generationCount = 1;
	bool stable = false;

    char** nextGen = new char*[boardLength]; // creates second board based off the first

    for (int i = 0; i < boardLength; ++i)
    {
    	nextGen[i] = new char[boardWidth];
    }

    while(stable == false)
    {
    	for(int i = 0; i < boardLength; ++i)
      {
			for(int j = 0; j < boardWidth; ++j)
      {
        count = 0;

				if (i == 0 && j == 0)
        {
					if(board[i+1][j] == 'X') count+=2; // count+=2 is neighbor and its reflection
					if(board[i][j+1] == 'X') count+=2;
					if(board[i+1][j+1] == 'X') count++; // count++ is one neighbor, no reflection
					if(board[i][j] == 'X') count+=3; // count+=3 is its own reflection in the corner
				}
				else if (i == 0 && j == (boardWidth - 1))
        {
					if(board[i+1][j] == 'X') count+=2;
					if(board[i][j-1] == 'X') count+=2;
					if(board[i+1][j-1] == 'X') count++;
					if(board[i][j] == 'X') count+=3;
				}
				else if (i == (boardLength - 1 ) && j == (boardWidth - 1))
        {
					if(board[i-1][j] == 'X') count+=2;
					if(board[i][j-1] == 'X') count+=2;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i][j] == 'X') count+=3;
				}
				else if (i == (boardLength - 1) && j == 0)
        {
					if(board[i-1][j] == 'X') count+=2;
					if(board[i][j+1] == 'X') count+=2;
					if(board[i-1][j+1] == 'X') count++;
					if(board[i][j] == 'X') count+=3;
        }
	      else if (i == 0)
        {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count+=2;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count+=2;
					if(board[i+1][j-1] == 'X') count++;
					if(board[i][j] == 'X') count++;
    	  }
				else if (j == 0)
        {
					if(board[i-1][j] == 'X') count+=2;
					if(board[i+1][j] == 'X') count+=2;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i-1][j+1] == 'X') count++;
					if(board[i][j] == 'X') count++;
				}
	      else if (i == (boardLength - 1))
        {
					if(board[i-1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count+=2;
					if(board[i-1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count+=2;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i][j] == 'X') count++;
				}
				else if (j == (boardWidth - 1))
        {
					if(board[i-1][j] == 'X') count+=2;
					if(board[i+1][j] == 'X') count+=2;
					if(board[i][j-1] == 'X') count++;
					if(board[i+1][j-1] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i][j] == 'X') count++;
				}
				else
        {
					if(board[i+1][j] == 'X') count++;
					if(board[i][j+1] == 'X') count++;
					if(board[i+1][j+1] == 'X') count++;
					if(board[i][j-1] =='X') count++;
					if(board[i-1][j] == 'X') count++;
					if(board[i-1][j-1] == 'X') count++;
					if(board[i+1][j-1] =='X') count++;
					if(board[i-1][j+1] == 'X') count++;
        }
	            if (count < 2)
              {
        	   		nextGen[i][j] = '-'; // kills cell if one or fewer neighbors
        		}
        		else if (count == 2)
            {
    	        	nextGen[i][j] = board[i][j]; // if exactly two neighbors, no change
        		}
        		else if (count == 3)
            {
            		nextGen[i][j] = 'X'; // creates cell if it has three neighbors and an empty space near
        		}
	        	else if (count > 3)
            {
        	    	nextGen[i][j] = '-'; // overloads to death if four or more neighbors
        		}
	        }
    	}

        int checker = 0;

        for (int i = 0; i <boardLength; ++i)
        {
       		for (int j = 0; j < boardWidth; ++j)
          {
	       		if (nextGen[i][j] == board[i][j])
            {
	       			checker++;
	           	}
           		else
              {
           			stable = false;
         		  }
       		 }
    	   }

    	if (checker == (boardLength*boardWidth))
      {
    		stable = true;
    		cout << "\nThis generation is stable, there can be no more changes." << endl;
    	}
        //Print out to a File
    	if (stable == false)
      {

    		std::stringstream sstm;
    		sstm << "Generation: " << generationCount << "\n";
            printString += sstm.str();

            if (generationCount == 1)
            {
            	for(int i = 0; i < boardLength; ++i)
              {
      				  for(int j = 0; j < boardWidth; ++j)
                {
      					  std::stringstream sstm;
   						    sstm << board[i][j];
   						    printString += sstm.str();
   					    }
                std::stringstream sstm;
   					    sstm << "\n";
   					    printString += sstm.str();
  				    }

            	t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);

            	for(int i = 0; i < boardLength; ++i)
              {
                for(int j = 0; j < boardWidth; ++j)
                {
      					  board[i][j] = nextGen[i][j];
      				  }
      		  	}
            }
            else
            {
            	for(int i = 0; i < boardLength; ++i)
              {
      				  for(int j = 0; j < boardWidth; ++j)
                {
      					  board[i][j] = nextGen[i][j];
      					  std::stringstream sstm;
      					  sstm << board[i][j];
      					  printString += sstm.str();
      				}
      				std::stringstream sstm;
   					sstm << "\n";
   					printString += sstm.str();
      			}
            //again
      			t.PrintResults(printMethod, generationCount, board, boardLength, boardWidth);
      		}
    	}
    	generationCount++;
    }

    if(printFile != "")
    {
    	ofstream outputFile;
    	outputFile.open(printFile.c_str());
    	outputFile << printString << "\n";
    	outputFile.close();
	}
    return 0;
}

void Modes::ModeSelection(int& boardLength, int& boardWidth, char**& board) // mode selection prompts
{
  string mode = "";
  bool pass = true;

  while(pass == true)
  {
    cout << "Choose game mode: Classic, Mirror, or Donut.\n" << endl;
    cin >> mode;

    if((mode == "Classic") || (mode == "classic"))
    {
      ClassicMode(boardLength, boardWidth, board);
      pass = false;
    }
    else if((mode == "Mirror") || (mode == "mirror"))
    {
      MirrorMode(boardLength, boardWidth, board);
      pass = false;
    }
    else if((mode == "Donut") || (mode == "donut"))
    {
      DonutMode(boardLength, boardWidth, board);
      pass = false;
    }
  }
}

void Modes::CreateBoardFile(string inputfile) // creating board from input file
{
  ifstream inputStream;
	inputStream.open(inputfile.c_str()); // opens file to read

	int boardLength = 0; // setting base variables
	int boardWidth = 0;
	int counter = 0;
	string line = "";

	while(!inputStream.eof()) // begins file reading
  {
		getline(inputStream, line); // checks amount of lines

		if (counter == 0) // reading length
    {
			boardLength = atoi(line.c_str()); // atoi converts strings to integers
		}
    else if (counter == 1) // reading width
    {
			boardWidth = atoi(line.c_str());
		}
    else
    {
			break;
		}
		counter++;
	}
	counter = 0;

	char** newBoard = new char*[boardLength]; // transfering read length to new board

    for (int i = 0; i < boardLength; ++i)
    {
      	newBoard[i] = new char[boardWidth];
    }

    for (int i = 0; i < boardLength; i++)
    {
		  for (int j = 0; j < boardWidth; j++)
      {
			newBoard[i][j] = '-';
		  }
	  }

	inputStream.seekg(0, inputStream.beg);

	int row = 0;

	while(!inputStream.eof())
  {
		getline(inputStream, line);

		if (counter == 0)
    {

		}
    else if (counter == 1)
    {

		}
    else
    {
			for(int i = 0; i < boardWidth; i++)
      {
				char element = line[i];
				newBoard[row][i] = element;
			}
			row++;
		}
		counter++;
	}
	ModeSelection(boardLength, boardWidth, newBoard); // calls ModeSelection to detetmine game mode after reading is completed
}

void Modes::CreateBoardRandom(int& boardLength, int& boardWidth) // create random board
{

	double density = 0.0;
	int cellTotal = 0;
	int length = 0;
  int width = 0;
  bool input = false;

	cout << "Input the length of the board.\n" << endl; // choosing length
	cin >> boardLength;

	cout << "Input the width of the board.\n" << endl; // choosing width
	cin >> boardWidth;

	while (input == false) // choosing starting cell density
  {
		cout << "Choose a decimal between 0 and 1.\n" << endl; // 0 and 1 will result in a blank or full stable generation
		cin >> density;

		if((density >= 0.0) && (density <= 1.0))
    {
			input = true; // correct value
		}
    else
    {
			input = false; // incorrect value, will loop back
		}
	}

	char** newBoard = new char*[boardLength]; // makes new board from the first

    for (int i = 0; i < boardLength; ++i)
    {
      	newBoard[i] = new char[boardWidth];
    }

	cellTotal = round((boardLength*boardWidth)*density);

	for (int i = 0; i < boardLength; i++)
  {
		for (int j = 0; j < boardWidth; j++)
    {
			newBoard[i][j] = '-';
		}
	}
	srand(time(NULL)); // uses time to create random variables

	for (int k = 0; k < cellTotal; k++)
  {
		length = rand() % (boardLength); // random cells along length
		width = rand() % (boardWidth); // random cells along width

		int numCells = 1;

		while(numCells > 0)
    {
			if(newBoard[length][width] == '-')
      {
				newBoard[length][width] = 'X';
				numCells--;
			}
      else
      {
				length = rand() % (boardLength);
				width = rand() % (boardWidth);
			}
		}
	}
	ModeSelection(boardLength, boardWidth, newBoard);
}
