#include "SubTopics.h"

SubTopics::SubTopics()
{
	makeBlue = { "void", "static", "int", "double", "float", "bool", "char", "true", "false",
				"const", "delete", "nullptr", "public", "private", "protected", "namespace", "auto"};

	makeGreen = { "string", "vector", "unordered_map", "map" };

	makePurple = { "if", "else", "for", "each", "do", "while", "continue"};

	subTopicActions["What is C++?"] = WhatIsCPlusPlus;
	subTopicActions["Why Learn C++?"] = WhyLearnCPlusPlus;
	
}
void SubTopics::WhatIsCPlusPlus()
{
	
	std::ifstream inFile("WhatIsCPlusPlus.txt");

	Manual manual;

	if (inFile.is_open())
	{
		std::string line;
		while (getline(inFile, line))
		{
			manual.PrintSlowText(line);
		}
		inFile.close();
	}
	else
	{
		std::cout << "Unable to open file for reading" << std::endl;
	}
}

void SubTopics::WhyLearnCPlusPlus()
{
	std::ifstream inFile("WhyLearnCPlusPlus.txt");

	Manual manual;

	if (inFile.is_open())
	{
		std::string line;
		while (getline(inFile, line))
		{
			for (char& ch : line)
			{
				manual.PrintSlowText(std::string(1, ch));
				if (ch == '.')
				{
					std::cout << std::endl;
				}
			}
		}
		inFile.close();
	}
	else
	{
		std::cout << "Unable to open file for reading" << std::endl;
	}
}