#include "LetterChecker.h"

class UChecker : public LetterChecker
{	
	//override the function "checkMyLetter"	
	//create the function declaration here
	public: 	

	virtual char checkMyLetter(char inputChar);
		
	protected:
		char defaultLetter;
};
