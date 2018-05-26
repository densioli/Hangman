#include "CChecker.h"

char CChecker::checkMyLetter(char inputChar)
{
	if(inputChar == 'C' || inputChar == 'c')
		return 'c';
	else
		return '*';
}
