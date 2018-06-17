#include "PuzzleView.h"

void PuzzleView::displayWelcomeMessage(){
	std::cout << "Welcome to Hangman!" << std::endl;
	system("pause");
}

void PuzzleView::displayHangMan(int nLives)
{
	switch(nLives)
	{
		case 6 : std::cout << "-----\n";
			     std::cout << " |  |\n";
			     std::cout << " |  \n";
			     std::cout << " |  \n";
			     std::cout << " |   \n";
			     std::cout << " |\n";
			     std::cout << "---\n\n";
			     break;
		case 5 : std::cout << "-----\n";
			     std::cout << " |  |\n";
			     std::cout << " |  O\n";
			     std::cout << " |  \n";
			     std::cout << " |  \n";
			     std::cout << " |\n";
			     std::cout << "---\n\n";
			     break;
		case 4 : std::cout << "-----\n";
			     std::cout << " |  |\n";
			     std::cout << " |  O\n";
			     std::cout << " | / \n";
			     std::cout << " |  \n";
			     std::cout << " |\n";
			     std::cout << "---\n\n";
			     break;
		case 3 : std::cout << "-----\n";
			     std::cout << " |  |\n";
			     std::cout << " |  O\n";
			     std::cout << " | /| \n";
			     std::cout << " |  \n";
			     std::cout << " |\n";
			     std::cout << "---\n\n";
			     break;
		case 2 : std::cout << "-----\n";
			     std::cout << " |  |\n";
			     std::cout << " |  O\n";
			     std::cout << " | /|\\ \n";
			     std::cout << " |  \n";
			     std::cout << " |\n";
			     std::cout << "---\n\n";
			     break;
		case 1 : std::cout << "-----\n";
			     std::cout << " |  |\n";
			     std::cout << " |  O\n";
			     std::cout << " | /|\\ \n";
			     std::cout << " | /  \n";
			     std::cout << " |\n";
			     std::cout << "---\n\n";
			     break;
		case 0 : std::cout << "-----\n";
			     std::cout << " |  |\n";
			     std::cout << " |  O\n";
			     std::cout << " | /|\\ \n";
			     std::cout << " | / \\ \n";
			     std::cout << " |\n";
			     std::cout << "---\n\n";
			     break;
	}
}

void PuzzleView::displayPuzzleString(std::string puzzleString)
{
	std::cout << "     ";
	for(char &c: puzzleString)
	{	
		std::cout << c << " ";
	}		
	std::cout << "\n\n";
}

void PuzzleView::displayBoard(std::string strBoard)
{
	for(char& c : strBoard)
	{
		std::cout << "[" << c << "] ";
	}
	std::cout << "\n\n";	
}

void PuzzleView::displayScores(int lives, int gamesWon, int gamesLost)
{
	std::cout << "Hangman! Current Lives: " << lives << " | wins: "<< gamesWon << " | losses: " << gamesLost << "\n\n";
}

void PuzzleView::displayResult(bool isWin, std::string answer)
{
	if(isWin)
		std::cout << "\nCongratulations, you correctly guessed the word [" << answer << "]!"<< std::endl;
	else
		std::cout << "\nSorry, the correct word is [" << answer << "]!" << std::endl;
}
