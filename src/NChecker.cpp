#include "NChecker.h"

//override the function "checkMyLetter"
//create the function definition here
 
 char NChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if( inputChar == 'N' && inputChar == 'n')
	{		
		return '*';
	}
	else
		return 'n';
}

