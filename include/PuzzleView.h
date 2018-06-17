/********************************************************
* PuzzleView class for Hangman's views
* includes display
* 
* Created by: 
********************************************************/

#include <string>
#include <vector>
#include <iostream>

class PuzzleView
{
public:
	void displayWelcomeMessage();
	void displayHangMan(int lives);
	void displayPuzzleString(std::string puzzleString);
	void displayBoard(std::string strBoard);
	void displayScores(int lives, int gamesWon, int gamesLost);
	void displayResult(bool isWin, std::string answer);
};
