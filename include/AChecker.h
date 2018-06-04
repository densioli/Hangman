#include "LetterChecker.h"

class AChecker : public LetterChecker
{
	//override the function "checkMyLetter"	
	//create the function declaration here
	
	public: 	
	/******************************************************************************
	 * This method will check if the input character is equivalent to the Checker's letter
	 * if equivalent, returns the lower case char of the letter
	 * if not equivalent, returns the defaultLetter
	 * 
	 * @return char   the checker's letter, or the default letter
	 * @params char   the inputted letter to be checked			 
	 ******************************************************************************/	
	virtual char checkMyLetter(char inputChar);
	

};
