#include <vector>

#include "AChecker.h"
#include "BChecker.h"
#include "CChecker.h"
#include "DChecker.h"

class LetterFunction
{
	public:
		LetterFunction();
		~LetterFunction();
		char check(char inputChar);
	private:
		std::vector<LetterChecker*> vCheckers;
};

