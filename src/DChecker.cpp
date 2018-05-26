#include "DChecker.h"

char DChecker::checkMyLetter(char inputChar)
{
	int asciiInput = inputChar;	
	if(asciiInput == 68 || asciiInput == 100)
		return 'd';
	else
		return '*';
}
