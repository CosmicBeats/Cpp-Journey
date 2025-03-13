#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "SubTopics.h"




class Manual
{
	// Variables to work with

    

    bool inMainTopic;

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
    void SelectTopic();

    std::vector < std::pair<std::string, std::vector<std::string>>>::const_iterator FindMainTopic();

    std::string FindSubTopic();
    std::string ToLower(const std::string& str);

    

};

