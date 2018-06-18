/********************************************************
* Main entry point for Hangman
* includes the game loop and the basic print info
* 
* Created by: Dennis Li (dennis.li@ubisoft.com)
********************************************************/

#include <time.h>
#include "Puzzle.h"
#include "LetterFunction.h"

int main(int argc, char** argv)
{	
	srand(time(NULL));
	//Puzzle p("dictionary_many.txt");	
	std::string strInput;
	char strDifficulty;
	//p.displayWordList();                      //uncomment to see the word list loaded for the game
	LetterFunction *lf = new LetterFunction();	
	
	retry:
		std::cout << std::string(75, '\n');	
		std::cout <<"Choose a Difficulty: \n[1] Easy \n[2] Medium \n[3] Hard \n> ";
		std::cin >> strDifficulty;
		
		
		std::string strDictionary;
		if (strDifficulty == '1')
			strDictionary="easy";
		else if (strDifficulty == '2')
			strDictionary="medium";
		else if (strDifficulty == '3')
			strDictionary="hard"; 
		else{
			std::cout << "Please choose from 1 to 3\n";
			system("pause");
			goto retry;
		} 
	

	
	Puzzle p("dictionary_" + strDictionary + ".txt");

	while(p.isGame())
	{		
		p.initPuzzle(strDifficulty);	
						
		while (p.isGame() && p.isAlive() && !p.isWin() )
		{
			std::cout << std::string(75, '\n');	
			std::cout << "Hangman"<<strDifficulty<<"! Current Lives: " << p.getLives() << " | wins: "<< p.getWins() << " | losses: " << p.getLosses() << "\n\n";
			p.displayPuzzleString();
			p.displayBoard();
			std::cout <<"Guess a letter > ";
			std::cin >> strInput;
			
			if(strInput.size() == 1) //single char input
			{
				char cInput = lf->check(strInput[0]);
				
				if(p.isInBoard(cInput))
				{
					int ansIndex = p.findInAnswer(cInput);
					if(ansIndex == std::string::npos) //wrong letter
					{
						p.loseLife();
					}
					else //right letter
					{
						p.openPuzzle(ansIndex);
					}
				}
				else
				{
					p.loseLife();
					//no longer in board					
				}				
			}
			else //multi char input
			{
				if(strInput == "quit" || strInput == "exit")
				{				
					p.endGame();
				}
				else 
				{
					std::cout << "invalid input!" << std::endl;
				}
			}
			
			if(p.isWin())
			{
				p.addWin();
				std::cout << "\nCongratulations, you correctly guessed the word [" << p.getAnswer() << "]!"<< std::endl;
				system("pause");
			}
			else if (!p.isAlive())
			{
				p.addLoss();
				std::cout << "\nSorry, the correct word is [" << p.getAnswer() << "]!" << std::endl;
				system("pause");
			}
		}			
	}	
	delete lf;
	
	return 0;
}
