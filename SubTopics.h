#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "Manual.h"

class SubTopics
{
	std::vector<std::string> makeBlue;
	std::vector<std::string> makePurple;
	std::vector<std::string> makeGreen;
	
public:
	std::unordered_map<std::string, void(*)()> subTopicActions;
	SubTopics();
	std::string ChangeColor(std::vector<std::string> vec);
	static void WhatIsCPlusPlus();
	static void WhyLearnCPlusPlus();
	
};

