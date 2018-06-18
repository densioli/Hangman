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
#include <sstream>
#include <algorithm>
#include <iomanip>

class Puzzle
{
private:
	int nWins, nLosses, nLives;
	bool _isGame, _isAlive, _isWin;
	std::vector<std::string> vWordList;
	std::string answerString, puzzleString, strBoard;
	std::string fileName = "scoreboard.txt";
	
public:
	bool initDictionary(const std::string& strFileName);	
	void displayBoard();
	std::string pickWord();
	bool isInBoard(const char c);
	int findInAnswer(const char c);	
	void openPuzzle(const int ansIndex);
	
	void initGame(const std::string& strDict);   //get puzzle from dictionary
	void initPuzzle(); 							//reset lives, get a new word
	void displayWordList();
	void displayPuzzleString();
	
	bool isWin() { return _isWin; }	
	bool isAlive() { return _isAlive; }
	bool isGame() { return _isGame; }
	
	std::string getAnswer() {return answerString; }
	int getWins() {return nWins; }
	int getLosses() {return nLosses; }
	int getLives() {return nLives; }
	
	void addWin() { nWins++; }
	void addLoss() { nLosses++; }
	void endGame() {  _isGame = false; }

	void createScoreboard() {
		if (FILE *file = fopen(fileName.c_str(), "r")) {
			fclose(file);
		} else {
			std::ofstream scoreBoardFile("scoreboard.txt");

			if (!scoreBoardFile.is_open()) {
				std::cout << "Something went wrong with opening the file!";
				endGame();
			}
		}
	}
	void appendToScoreBoard(const std::string name, int nWins) {
	    if (FILE *file = fopen(fileName.c_str(), "r")) {
            std::ofstream scoreBoardFile;
            scoreBoardFile.open(fileName, std::ios_base::app);
            scoreBoardFile << name << " " << nWins << "\n";

            fclose(file);
            scoreBoardFile.close();
        } else {
            std::cout << "Something went wrong with opening the scoreboard file!";
            endGame();
        }

	}

	static bool sortbysec(const std::pair<std::string, long> &a,
                   const std::pair<std::string, long> &b) {
        return (a.second > b.second);
    }

	void displayScoreboard() {
		if (FILE *file = fopen(fileName.c_str(), "r")) {
			std::ifstream scoreBoardFile(fileName);

//            std::map<std::string, long> playerMap;
            std::vector<std::pair<std::string, long>> playerMap;
            std::string str;

            while(std::getline(scoreBoardFile, str)) {
				std::string playerName;
				long playerScore = 0;
				std::stringstream ss(str);
				std::string token;

				while (std::getline(ss, token, ' ')) {
					if (playerName.empty()) {
						playerName = token;
					} else {
						playerScore = strtol(token.c_str(), nullptr, 10);
					}
				}

				playerMap.emplace_back(playerName, playerScore);
            }

            std::sort(playerMap.begin(), playerMap.end(), sortbysec);

			std::cout << "+-----------+-----------+\n";
			std::cout << "|   Player  |   Score   |\n";
			std::cout << "+-----------+-----------+\n";

			int ctr = 0;

            for (auto const &pair : playerMap) {
            	if (ctr >= 10) {
            		break;
            	}

//				std::cout << "|\t" << pair.first << "\t\t|\t" << pair.second << "\t\t|\n";
				std::cout << "|    "  << std::setw(3) << pair.first << "    ";
				std::cout << "|   "  << std::setw(5) << pair.second << "   |\n";
				ctr++;
            }

			std::cout << "+-----------+-----------+\n\n";

			fclose(file);
		} else {
			std::cout << "Something went wrong with opening the file!\n\n";
		}

		system("pause");
	}

	void loseLife();
		
	Puzzle();
	Puzzle(std::string strDict);
	~Puzzle();
};
