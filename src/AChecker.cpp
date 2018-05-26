#include "AChecker.h"

/*void AChecker::setMyLetter()
{	
	std::cout << "My letter is A so I set my letter to A " << std::endl;	
	myLetter = 'a';
}*/

char AChecker::checkMyLetter(char inputChar)
{
	if(inputChar == 'A' || inputChar == 'a')
		return 'a';
	else
		return '*';
}
