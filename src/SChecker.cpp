#include "SChecker.h"

//override the function "checkMyLetter"
//create the function definition here


char SChecker::checkMyLetter(char inputChar)
{
//	std::cout << "\nDefault letter 's' used." << std::endl;
	if(inputChar == 's' || inputChar == 'S')
	{		
		return inputChar;
	}
	else
		return defaultLetter;
}

