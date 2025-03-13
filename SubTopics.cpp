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

			if (line == "Output")
			{
				subTopic.inOutput = true;
				continue;
			}

			if (line == "End Output")
			{
				subTopic.inOutput = false;
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
			else if (subTopic.inOutput)
			{
				manual.PrintSlowText(subTopic.WHITEBACKGROUND + line + subTopic.RESET);
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

	// Combined regex pattern for detecting both quoted and angle-bracketed text
	std::regex pattern(R"(<[^>]*>|\"[^\"]*\")");  // Matches text within either <> or ""

	std::string::const_iterator searchStart(line.cbegin());
	std::smatch match;

	// Function to add unmatched sections directly to coloredLine
	auto addUnmatchedText = [&coloredLine](std::string::const_iterator start, std::string::const_iterator end) 
		{
		coloredLine += std::string(start, end); // Add unmatched text as is
		};

	// Process the line for text within quotes or angle brackets
	while (searchStart != line.cend())
	{
		if (std::regex_search(searchStart, line.cend(), match, pattern))
		{
			// Append unmatched text before the match
			addUnmatchedText(searchStart, searchStart + match.position());

			// Add the colored match
			coloredLine += ORANGE + match.str() + RESET;
			searchStart += match.position() + match.length();
		}
		else
		{
			// If no more matches, add the remaining text and break
			addUnmatchedText(searchStart, line.cend());
			break;
		}
	}

	// Additional coloring of specific words outside quotes and brackets
	std::string finalColoredLine;
	std::string word;

	for (size_t i = 0; i < coloredLine.size(); ++i)
	{
		char ch = coloredLine[i];
		if (std::isspace(ch))
		{
			// Preserve whitespace
			finalColoredLine += ch;
		}
		else
		{
			// Build a word
			word.clear();
			while (i < coloredLine.size() && !std::isspace(coloredLine[i]))
			{
				word += coloredLine[i++];
			}
			--i;  // Adjust for the outer loop increment

			// Check if the word matches any color list
			if (std::find(makeBlue.begin(), makeBlue.end(), word) != makeBlue.end())
			{
				finalColoredLine += BLUE + word + RESET;
			}
			else if (std::find(makeGreen.begin(), makeGreen.end(), word) != makeGreen.end())
			{
				finalColoredLine += GREEN + word + RESET;
			}
			else if (std::find(makePurple.begin(), makePurple.end(), word) != makePurple.end())
			{
				finalColoredLine += BRIGHTMAGENTA + word + RESET;
			}
			else if (std::find(makeYellow.begin(), makeYellow.end(), word) != makeYellow.end())
			{
				finalColoredLine += YELLOW + word + RESET;
			}
			else
			{
				finalColoredLine += word;
			}
		}
	}

	// Output the result using PrintSlowText
	if (!finalColoredLine.empty())
	{
		manual.PrintSlowText(finalColoredLine);
		
	}
}




