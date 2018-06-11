#include "GChecker.h"

//override the function "checkMyLetter"
//create the function definition here

// Lol I don't know how xD

char GChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(inputChar == 'g' || inputChar == 'G')
	{		
		return 'g';
	}
	return '*';
	
}
