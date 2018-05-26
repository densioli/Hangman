#include "AChecker.h"

char AChecker::checkMyLetter(char inputChar)
{
	if(inputChar == 'A' || inputChar == 'a')
		return 'a';
	else
		return defaultLetter;
}
