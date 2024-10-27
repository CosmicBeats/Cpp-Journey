#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <any>
class SubTopics
{

	
public:
	std::unordered_map<std::string, void(*)()> subTopicActions;
	SubTopics();
	
	static void WhatIsCPlusPlus();
};

