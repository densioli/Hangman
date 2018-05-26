#include "BChecker.h"

char BChecker::checkMyLetter(char inputChar)
{
	if(inputChar == 'B' || inputChar == 'b')
		return 'b';
	else
		return '*';
}
