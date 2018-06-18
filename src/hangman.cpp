/********************************************************
* Main entry point for Hangman
* includes the game loop and the basic print info
* 
* Created by: Dennis Li (dennis.li@ubisoft.com)
********************************************************/

#include <time.h>
#include "Puzzle.h"
#include "LetterFunction.h"
using namespace std;

int GetInput()
{
	int choice;
	cin >> choice;
	return choice;
}

 void DisplayMainMenu()
 {
		cout << "Main Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Start game\n";
    cout << "2 - Show scoreboard\n";
    cout << "3 - Quit\n";
    cout << "Selection: ";
 }

int main(int argc, char** argv)
{	
	int choice = 0;

    do
    {
		srand(time(NULL));
		Puzzle p("dictionary_many.txt");
		std::string strInput;
		//p.displayWordList();                      //uncomment to see the word list loaded for the game
		LetterFunction *lf = new LetterFunction();

        system("cls");
        DisplayMainMenu();
        choice = GetInput();
        switch(choice) {
                case 1:
						while(p.isGame())
						{
							p.initPuzzle();
							while (p.isGame() && p.isAlive() && !p.isWin() )
							{
								cout << std::string(75, '\n');
								cout << "Hangman! Current Lives: " << p.getLives() << " | wins: "<< p.getWins() << " | losses: " << p.getLosses() << "\n\n";
								p.displayPuzzleString();
								p.displayBoard();
								cout <<"Guess a letter > ";
								cin >> strInput;

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
										cout << "invalid input!" << std::endl;
									}
								}

								if(p.isWin())
								{
									p.addWin();
									cout << "\nCongratulations, you correctly guessed the word [" << p.getAnswer() << "]!"<< std::endl;
									system("pause");
								}
								else if (!p.isAlive())
								{
//									p.addLoss();
									std::cout << "\nSorry, the correct word is [" << p.getAnswer() << "]!" << std::endl;
									system("pause");

                                    std::string name;
                                    do {
                                        std::cout <<"Enter your name (max of 3 characters): ";
                                        std::cin >> name;
                                    } while (name.size() > 3);

                                    p.appendToScoreBoard(name, p.getWins());
                                    p.displayScoreboard();
                                    p.endGame();
								}
							}
						}
						delete lf;
                        break;
                case 2:
                        p.displayScoreboard();
                        break;
                case 3:
                        cout << "Goodbye!";
                        break;

                default:
                		std::cin.clear();
                		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        break;
               }
       } while(choice!=3 || std::cin.fail());
	system("PAUSE");
    return EXIT_SUCCESS;
}
