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
	std::string coloredLine;
	std::string word;
	bool insideQuotes = false;
	bool insideAngleBrackets = false;

	for (size_t i = 0; i < line.size(); ++i)
	{

		if (i + 1 < line.size() && ((line[i] == '<' && line[i + 1] == '<') || (line[i] == '>' && line[i + 1] == '>')))
		{
			coloredLine += line[i];
			coloredLine += line[i + 1];
			i++;  // Skip the next character
			continue;
		}

		// Preserve whitespace (spaces and tabs) in the output
		if (std::isspace(line[i]))
		{
			coloredLine += line[i];
			continue;
		}

		word.clear();

		// Detect the start of quoted text with " or <>
		if (line[i] == '"' && !insideAngleBrackets)
		{
			insideQuotes = !insideQuotes;  // Toggle insideQuotes flag
			word += line[i];

			// If we closed the quotes, apply the color to the collected word
			if (!insideQuotes)
			{
				coloredLine += ORANGE + word + RESET;
				continue;
			}
		}
		else if (line[i] == '<' && !insideQuotes)
		{
			insideAngleBrackets = true;
			word += line[i];
		}
		else if (line[i] == '>' && insideAngleBrackets)
		{
			insideAngleBrackets = false;
			word += line[i];
			coloredLine += ORANGE + word + RESET;
			continue;
		}
		else if (insideQuotes || insideAngleBrackets)
		{
			// Collect characters within quotes or angle brackets
			word += line[i];
		}
		else
		{
			// Handle text outside quotes and brackets
			while (i < line.size() && !std::isspace(line[i]) && line[i] != '<' && line[i] != '>' && line[i] != '"')
			{
				word += line[i++];
			}
			--i;

			// Check if the word matches any color list
			if (std::find(makeBlue.begin(), makeBlue.end(), word) != makeBlue.end())
			{
				coloredLine += BLUE + word + RESET;
			}
			else if (std::find(makeGreen.begin(), makeGreen.end(), word) != makeGreen.end())
			{
				coloredLine += GREEN + word + RESET;
			}
			else if (std::find(makePurple.begin(), makePurple.end(), word) != makePurple.end())
			{
				coloredLine += BRIGHTMAGENTA + word + RESET;
			}
			else if (std::find(makeYellow.begin(), makeYellow.end(), word) != makeYellow.end())
			{
				coloredLine += YELLOW + word + RESET;
			}
			else
			{
				coloredLine += word;
			}
		}

		// If inside quotes or angle brackets, add the current part of `word`
		if (insideQuotes || insideAngleBrackets)
		{
			coloredLine += ORANGE + word + RESET;
		}

		if (!coloredLine.empty())
		{
			continue;
		}

		if (!coloredLine.empty() && coloredLine.back() == '\n') 
		{
			coloredLine.pop_back();
		}
			
	}

	// Output the result using PrintSlowText
	if (!coloredLine.empty())
	{
		manual.PrintSlowText(coloredLine);
		
	}
	
}



