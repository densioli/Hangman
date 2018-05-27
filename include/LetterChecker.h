/********************************************************
* Letter Checker base class to be extended for each 
* letter's (A-Z) checker
* 
* Created by: Dennis Li (dennis.li@ubisoft.org)
********************************************************/

#ifndef __LETTERCHECKER_H_INCLUDED__
#define __LETTERCHECKER_H_INCLUDED__

#include <iostream>

class LetterChecker
{
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
	
	LetterChecker();	
protected:
	char defaultLetter;
};

#endif //__LETTERCHECKER_H_INCLUDED__
