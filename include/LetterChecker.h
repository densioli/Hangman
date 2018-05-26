#ifndef __LETTERCHECKER_H_INCLUDED__
#define __LETTERCHECKER_H_INCLUDED__

#include <iostream>

class LetterChecker
{
public: 
	//virtual void setMyLetter();	
	virtual char checkMyLetter(char inputChar);
	LetterChecker();	
private:
	char myLetter;
};

#endif //__LETTERCHECKER_H_INCLUDED__
