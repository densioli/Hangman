#include "AChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char AChecker::checkMyLetter(char strInput)
{
	if(strInput == 'A' || strInput == 'a')
		return 'a';
	else
		return defaultLetter;
}

