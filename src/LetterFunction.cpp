#include "LetterFunction.h"

LetterFunction::LetterFunction()
{
	vCheckers = {};
	vCheckers.push_back(new AChecker());
	vCheckers.push_back(new BChecker());
	vCheckers.push_back(new CChecker());
	vCheckers.push_back(new DChecker());
	vCheckers.push_back(new EChecker());
	vCheckers.push_back(new FChecker());
	vCheckers.push_back(new GChecker());
	vCheckers.push_back(new HChecker());
	vCheckers.push_back(new IChecker());
	vCheckers.push_back(new JChecker());
	vCheckers.push_back(new KChecker());
	vCheckers.push_back(new LChecker());
	vCheckers.push_back(new MChecker());
	vCheckers.push_back(new NChecker());
	vCheckers.push_back(new OChecker());
	vCheckers.push_back(new PChecker());
	vCheckers.push_back(new QChecker());
	vCheckers.push_back(new RChecker());
	vCheckers.push_back(new SChecker());
	vCheckers.push_back(new TChecker());
	vCheckers.push_back(new UChecker());
	vCheckers.push_back(new VChecker());
	vCheckers.push_back(new WChecker());
	vCheckers.push_back(new XChecker());
	vCheckers.push_back(new YChecker());
	vCheckers.push_back(new ZChecker());	
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
