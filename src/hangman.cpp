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
	Puzzle p("dictionary_many.txt");	
	std::string strInput;
	
	int hint=0; // hint on/off
	int usedHint=0; //tracks if the player has already used a hint for the current round/word
	int numberOfHints=3; // number of hints left for the game
	int wins=0;
	int cheat = 0;
	
//	p.displayWordList();                      //uncomment to see the word list loaded for the game
	LetterFunction *lf = new LetterFunction();
	
	while(p.isGame())
	{		
		p.initPuzzle();
						
		while (p.isGame() && p.isAlive() && !p.isWin() )
		{
//			std::cout << std::string(50, '\n');	
			system("cls");
			std::cout << "\n\nHangman! Current Lives: " << p.getLives() << " | wins: "<< p.getWins() << " | losses: " << p.getLosses() <<  " | hints: " << numberOfHints << "\n\n";
		
			p.displayPuzzleString();

			if(hint==0) //if hint is "off", display normal board
			{
				usedHint=0;
				p.displayBoard();
			}	
				
			if(hint>=1) //if hint is on, display board with reduced letters
			{
				p.displayBoardHint();
			}
			
			if(cheat!=1)	
			{
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
					
					else if(strInput == "hint") //toggle hint
					{
						if(usedHint==0 && numberOfHints==0)
						{
							std::cout << "\nYou're out of hints!\n" << std::endl;
						}
						
						else if(usedHint==1 && numberOfHints>0) // prevent player from using another hint
						{
							std::cout << "\nYou've already used a hint for this word!\n" << std::endl;
						}
						
						else if(usedHint==1 && numberOfHints==0) // prevent player from using another hint
						{
							std::cout << "\nYou just used your last hint for this word!\n" << std::endl;
						}
						
						else //toggle hint
						{
							std::cout << "\nYou used a hint!\n" << std::endl;
							numberOfHints--; // decrease number of hints
							hint=1;
							usedHint=1;
						}
						
						system("pause");
					}	
					
					else if(strInput == "sv_cheats_hangman") //activate cheats
					{
						cheat=1;	
					}	
										
					else //invalid input
					{
						std::cout << "invalid input!" << std::endl;
					}
				}
			}
		
			else if(cheat == 1)
			{
				p.cheat();
				cheat = 0;
//				hint = 0;
			}
		
			if(p.isWin())
			{
				wins++;
				p.addWin();
				std::cout << "\nCongratulations, you correctly guessed the word [" << p.getAnswer() << "]!\n"<< std::endl;
				
				if(wins==5)
				{
					std::cout << "You have earned a hint!\n"<< std::endl;
					numberOfHints++;
					wins=0;
				}
								
				system("pause");
				hint = 0; //turn off hint for next word
				
			}
			
			else if (!p.isAlive())
			{
				p.addLoss();
				std::cout << "\nSorry, the correct word is [" << p.getAnswer() << "]!\n" << std::endl;
				system("pause");
				hint = 0; //turn off hint for next word
			}
		}			
	}	
	delete lf;
	
	return 0;
}
