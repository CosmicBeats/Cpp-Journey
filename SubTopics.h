#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include "Manual.h"

class SubTopics
{
	std::vector<std::string> makeBlue;
	std::vector<std::string> makePurple;
	std::vector<std::string> makeGreen;
	std::vector<std::string> makeYellow;
	

	bool inSnipet = false;
	bool inOutput = false;
	
	const std::string BLUE = "\033[38;5;33m";
	const std::string COMMENTGREEN = "\033[38;5;28m";
	const std::string GREEN = "\033[32m";
	const std::string ORANGE = "\033[38;5;130m";
	const std::string YELLOW = "\033[1;33m";
	const std::string RESET = "\033[0m";
	const std::string BRIGHTMAGENTA = "\033[38;5;141m";

	const std::string WHITEBACKGROUND = "\033[30;47m";
	
public:
	std::unordered_map<std::string, void(*)()> subTopicActions;
	SubTopics();
	void ChangeColor(const std::string& line);
	static void WhatIsCPlusPlus();
	static void WhyLearnCPlusPlus();
	static void FirstCPlusPlusProgram();
	
};

