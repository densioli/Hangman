/********************************************************
* Puzzle class for Hangman's game functions
* includes initialization, display, and most game logic
* 
* Created by: Dennis Li (dennis.li@ubisoft.com)
********************************************************/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Puzzle
{
private:
	int nWins, nLosses, nLives;
	bool _isGame, _isAlive, _isWin;
	std::vector<std::string> vWordList;
	std::string answerString, puzzleString, strBoard;
		
public:
	bool initDictionary(const std::string& strFileName);
	std::string pickWord();
	bool isInBoard(const char c);
	int findInAnswer(const char c);	
	void openPuzzle(const int ansIndex);
	
	void initGame(const std::string& strDict);   //get puzzle from dictionary
	void initPuzzle(); 							//reset lives, get a new word
	void displayWordList();
	
	bool isWin() { return _isWin; }	
	bool isAlive() { return _isAlive; }
	bool isGame() { return _isGame; }
	
	std::string getAnswer() {return answerString; }
	int getWins() {return nWins; }
	int getLosses() {return nLosses; }
	int getLives() {return nLives; }
	std::string getPuzzleString() {return puzzleString; }
	std::string getStrBoard() {return strBoard;	}
	
	void addWin() { nWins++; }
	void addLoss() { nLosses++; }	
	void endGame() {  _isGame = false; }	
	
	void loseLife();	
		
	Puzzle();
	Puzzle(std::string strDict);
	~Puzzle();
};
