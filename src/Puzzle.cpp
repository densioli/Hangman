#include "Puzzle.h"

void Puzzle::initGame(const std::string& strDict)
{
	nWins = 0;
	nLosses = 0;
	_isGame = true;
	createScoreboard();
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

std::string Puzzle::pickWord()
{
	std::string strWord{"default"};
	if(vWordList.size() > 0)
	{
		int nRandomIndex = std::rand() % vWordList.size();
		strWord = vWordList[nRandomIndex];
		vWordList.erase(vWordList.begin() + nRandomIndex);	
	}
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