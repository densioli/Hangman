/********************************************************
* LetterFunction class - creates letter checker objects
* and uses their checkMyLetter function to check
* if the user input matches the correct letter
* 
* Created by: Dennis Li (dennis.li@ubisoft.org)
********************************************************/

#include <vector>

#include "AChecker.h"
#include "BChecker.h"
#include "CChecker.h"
#include "DChecker.h"
#include "EChecker.h"
#include "FChecker.h"
#include "GChecker.h"
#include "HChecker.h"
#include "IChecker.h"
#include "JChecker.h"
#include "KChecker.h"
#include "LChecker.h"
#include "MChecker.h"
#include "NChecker.h"
#include "OChecker.h"
#include "PChecker.h"
#include "QChecker.h"
#include "RChecker.h"
#include "SChecker.h"
#include "TChecker.h"
#include "UChecker.h"
#include "VChecker.h"
#include "WChecker.h"
#include "XChecker.h"
#include "YChecker.h"
#include "ZChecker.h"

class LetterFunction
{
	public:
		LetterFunction();
		~LetterFunction();
		char check(char inputChar);
	private:
		std::vector<LetterChecker*> vCheckers;
};

