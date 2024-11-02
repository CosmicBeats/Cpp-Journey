#include "SubTopics.h"

SubTopics::SubTopics()
{
	makeBlue = { "void", "static", "int", "double", "float", "bool", "char", "true", "false",
				"const", "delete", "nullptr", "public", "private", "protected", "namespace", "auto", "using"};

	makeGreen = { "string", "vector", "unordered_map", "map" };

	makePurple = { "if", "else", "for", "each", "do", "while", "continue", "return"};

	makeYellow = { "main" };

	

	subTopicActions["What is C++?"] = WhatIsCPlusPlus;
	subTopicActions["Why Learn C++?"] = WhyLearnCPlusPlus;
	subTopicActions["First C++ Program"] = FirstCPlusPlusProgram;
	
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
			std::cout << std::endl;
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
			manual.PrintSlowText(line);
			std::cout << std::endl;
		}
		inFile.close();
	}
	else
	{
		std::cout << "Unable to open file for reading" << std::endl;
	}
}

void SubTopics::FirstCPlusPlusProgram() 
{
	std::ifstream inFile("WritingFirstCPlusPlusProgram.txt");
	SubTopics subTopic;
	Manual manual;

	if (inFile.is_open()) {
		std::string line;

		while (getline(inFile, line))
		{
			if (line == "Snipet")
			{
				subTopic.inSnipet = true;
				continue;
			}

			if (line == "End Snipet")
			{
				subTopic.inSnipet = false;
				continue;
			}

			if (subTopic.inSnipet)
			{
				size_t firstNonSpace = line.find_first_not_of(" \t"); // Finds the first non-space character
				if (firstNonSpace != std::string::npos && line.substr(firstNonSpace, 2) == "//")
				{
					manual.PrintSlowText(subTopic.COMMENTGREEN + line + subTopic.RESET);
					std::cout << std::endl;
					continue;
				}
				
				subTopic.ChangeColor(line);
				
				
				std::cout << std::endl;
			}
			else
			{
				manual.PrintSlowText(line);
				std::cout << std::endl;
			}
		}

		inFile.close();
	}
	else 
	{
		std::cout << "Unable to open file for reading" << std::endl;
	}
}

void SubTopics::ChangeColor(const std::string& line)
{
	Manual manual;
	std::string output;
	size_t pos = 0;

	// Regex to match words inside <> or ""
	std::regex pattern(R"(<[^>]*>|\"[^\"]*\")");
	std::sregex_iterator it(line.begin(), line.end(), pattern);
	std::sregex_iterator end;

	// Process Orange and Text Coloring
	std::string coloredLine;
	bool isColored = false;
	std::string word;

	for (size_t i = 0; i < line.size(); ++i)
	{
		// Handle whitespace (spaces and tabs)
		if (std::isspace(line[i]))
		{
			coloredLine += line[i];
			continue;
		}

		// Extract the word
		word.clear();
		size_t start = i;
		while (i < line.size() && !std::isspace(line[i]))
		{
			word += line[i];
			++i;
		}
		--i;

		// Check if the word is in <>
		std::smatch match;
		if (std::regex_search(word, match, pattern))
		{
			if (word.front() == '<' && word.back() == '>' || word.front() == '"' && word.back() == '"')
			{
				coloredLine += ORANGE + word + RESET;
			}
			
		}
		else if (std::find(makeBlue.begin(), makeBlue.end(), word) != makeBlue.end())
		{
			coloredLine += BLUE + word + RESET;
			isColored = true;
		}
		else if (std::find(makeGreen.begin(), makeGreen.end(), word) != makeGreen.end())
		{
			coloredLine += GREEN + word + RESET;
			isColored = true;
		}
		else if (std::find(makePurple.begin(), makePurple.end(), word) != makePurple.end())
		{
			coloredLine += BRIGHTMAGENTA + word + RESET;
			isColored = true;
		}
		else if (std::find(makeYellow.begin(), makeYellow.end(), word) != makeYellow.end())
		{
			coloredLine += YELLOW + word + RESET;
			isColored = true;
		}
		else
		{
			coloredLine += word;
		}

		
	}

	manual.PrintSlowText(coloredLine);
	std::cout << std::endl;
}