#include "AChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char AChecker::checkMyLetter(char inputChar)
{
	if(inputChar == 'A' || inputChar == 'a')
		return 'a';
	else
		return defaultLetter;
}
