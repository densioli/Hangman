#include "LetterFunction.h"

LetterFunction::LetterFunction()
{
	vCheckers = {};
	vCheckers.push_back(new AChecker());
	vCheckers.push_back(new BChecker());
	vCheckers.push_back(new CChecker());
	vCheckers.push_back(new DChecker());
	vCheckers.push_back(new EChecker());
}

LetterFunction::~LetterFunction()
{
	vCheckers.clear();
}

char LetterFunction::check(char inputChar)
{
	char checkedChar;
	for(LetterChecker* lc : vCheckers)
	{
		checkedChar = lc->checkMyLetter(inputChar);
		if(checkedChar!='*')
			break;
	}		
	std::cout << "\ncheckedChar = " << checkedChar << std::endl;
	return checkedChar;
}
