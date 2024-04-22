#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>


class Manual
{
	// Variables to work with

	std::string userMainTopicInput;

    std::string userSubTopicInput;
  
    std::vector<std::pair<std::string, std::vector<std::string>>> topics;

    //Functions

public:
    Manual();
    void Start();
    void MainInputValidation();
    void SubInputValidation();
    void PrintSlowText(std::string text);

    std::vector < std::pair<std::string, std::vector<std::string>>>::const_iterator FindMainTopic();

    std::string FindSubTopic();
    std::string ToLower(const std::string& str);

    

};

