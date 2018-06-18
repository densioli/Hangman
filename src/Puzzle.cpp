#include "Puzzle.h"
#include "time.h"
#include <array>
#include "conio.h"

struct hint //struct for board hint
{
	char hints[26];
	int letters = 0;	
	int x = 0;
	int win_code = 0;
} hint;

void Puzzle::initGame(const std::string& strDict)
{
	nWins = 0;
	nLosses = 0;
	_isGame = true;
  
	if(!initDictionary(strDict))
	{	
		//throw an exception
	}
}

void Puzzle::initPuzzle()
{
	_isAlive = true;
	_isWin = false;
	nLives = 6;	
	strBoard = {"abcdefghijklmnopqrstuvwxyz"};
	answerString = pickWord(); //Get a word for the player to guess
	puzzleString = "";
	
	//Fill the puzzle string with the same number of blanks as the word to guess
	for(char &c : answerString)
	{	
		puzzleString += '_';
	}	
}

bool Puzzle::initDictionary(const std::string& strFileName)
{	
	std::string strLine;
	std::ifstream fDictionary(strFileName);	
	if(fDictionary.is_open())
	{
		while(getline(fDictionary, strLine))
		{
			vWordList.push_back(strLine);
		}
		fDictionary.close();
		return true;
	}	
	else
	{
		std::cout <<"File not found: " << strFileName << std::endl;
		return false;
	}	
}

void Puzzle::cheat()
{
	char Ccode[15];
	int q = 0;
	int w = 0;
	
	char code[2][15]= 
	{
		{'^','v','^','>', '<','v'},
		{'^','v','<','>','>','>','<','<','v','^','^','v'}
	};
	
	while(q == 0 && w != 14)
	{
		
		switch (getch())
		{
			case 72:
			{ 
				std::cout << "^";
				Ccode[w] = '^';
				w++;
				break;
			}
			case 77:
			{ 
				std::cout << ">";
				Ccode[w] = '>';
				w++;
				break;
			}
			
			case 80:
			{ 
				std::cout << "v";
				Ccode[w] = 'v';
				w++;
				break;
			}
			
			case 75:
			{ 
				std::cout << "<";
				Ccode[w] = '<';
				w++;
				break;
			}
			
			case 13:
			{  
				q++;
				break;
			}
		}
	}
 w--;
 
	if (w== 5)
	{ 
		int x = w;
		while (w >=0)
		{ 
			if(Ccode[w]==code[0][w])
				w--;
				
			if (x==w)
			{
				std::cout << "\n\nInvalid Cheat Code!\n\n";
				system("pause");
				w = -1;
			}
			
			else
			{
				x=w;
			}
				
		}
		
		if (x == -1)
		{
			std::cout << "\n\nGain a life Cheat enabled!\n\n";
			nLives++;
			system("pause");
		}
	}
	
	else if (w== 11) 
	{ 
		int x = w;
		while (w >=0)
		{
			if(Ccode[w]==code[1][w])
			{
				w--;
			}
			
			if (x==w)
			{
				std::cout << "\n\nInvalid Cheat Code!\n\n";
				system("pause");
				w = -1;
			}
			else
			x=w;
		}
		
		if (x == -1)
		{
			std::cout << "\n\nAuto Guess Cheat enabled!\n\n";
			_isWin = true;
			system("pause");
		}
	}
	
	else 
	{
		std::cout << "\n\nInvalid Cheat Code!\n\n";
		system("pause");
		w = -1;
	}
}

std::string Puzzle::pickWord()
{
	std::string strWord{"default"};
	if(vWordList.size() > 0)
	{
		int nRandomIndex = std::rand() % vWordList.size();
		strWord = vWordList[nRandomIndex];
		vWordList.erase(vWordList.begin() + nRandomIndex);	
	}
	hint.x = 0;
	hint.letters = 0;
	return strWord;
}

void Puzzle::displayWordList()
{
	for (auto &s : vWordList)
	{
		std::cout << s << std::endl;
	}
}

void Puzzle::displayPuzzleString()
{
	std::cout << "     ";
	for(char &c: puzzleString)
	{	
		std::cout << c << " ";
	}		
	std::cout << "\n\n";
}

void Puzzle::displayBoard()
{
	for(char& c : strBoard)
	{
		std::cout << "[" << c << "] ";
	}
	std::cout << "\n\n";	
}

void Puzzle::displayBoardHint() //hint function; removes most letters from board
{
	int i = 0;
	int j = 0;
   int k = 0;
    
   if (hint.x == 0)
   {
	   srand(time(NULL));
		for(char& c : strBoard)
		{ 
			if (answerString.find(c) != std::string::npos)
			{
				i++;
			}	
		}
		j = i;
		
		if (j > 13)
		{
			j = 26 - i;
		}
		  				
		for(char& c : strBoard)
		{ 
			if (answerString.find(c) != std::string::npos)
			{
			   hint.hints[hint.letters] = c;  
			 	hint.letters++;
			}		
			
			else if (j != 0 && hint.letters != 25)
			{
			 	if (rand()%100 > 65) 
				{
					hint.hints[hint.letters] = c;
					j--;
					hint.letters++;
			 	}
			}
		}
		
		int v = 0;	
		while (v != hint.letters)
		{
			std::cout << "[" << hint.hints[v] << "]";
			v++;
		}
		hint.x = 1;
	}

	else if (hint.x > 0)
	{
		int v = 0;
		while (v != hint.letters)
		{
			for(char& c : strBoard)
			{
				if(c == hint.hints[v])
				{
					std::cout << "[" << hint.hints[v] << "]";
				}	
			}
			v++;
		}
	}
	std::cout << "\n\n";	
}

bool Puzzle::isInBoard(const char c)
{
	int charIndex = strBoard.find(c);
	if(charIndex < 0) 
	{
		return false;
	}
	else 
	{
		strBoard.erase(strBoard.begin()+charIndex);
		return true;
	}
}

int Puzzle::findInAnswer(const char c)
{
	return answerString.find(c);
}

void Puzzle::openPuzzle(const int ansIndex)
{
	char cLetter = answerString[ansIndex];
	puzzleString[ansIndex] = cLetter;
						
	for(int i=ansIndex+1; i<answerString.size(); i++) //find all same letters
	{
		if(answerString[i] == cLetter)
		{
			puzzleString[i] = cLetter;
		}
	}
	
	if(puzzleString.find('_') == std::string::npos)
	{
		_isWin = true;
	}
}

void Puzzle::loseLife()
{ 
	nLives--; 
	if(nLives < 1) _isAlive = false;
}	

Puzzle::Puzzle()
{
	initGame("dictionary.txt");
}

Puzzle::Puzzle(std::string strDict)
{
	initGame(strDict);
}

Puzzle::~Puzzle()
{
}
