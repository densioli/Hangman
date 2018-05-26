#include "DChecker.h"

char DChecker::checkMyLetter(char inputChar)
{
	int asciiInput = inputChar;
	std::cout << "\nasciiinput = " << asciiInput << std::endl;
	if(asciiInput == 68 || asciiInput == 100)
		return 'd';
	else
		return '*';
}
