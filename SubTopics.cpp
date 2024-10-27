#include "SubTopics.h"

SubTopics::SubTopics()
{
	subTopicActions["what is c++?"] = WhatIsCPlusPlus;
}
void SubTopics::WhatIsCPlusPlus()
{
	std::cout << "Function Called";
}