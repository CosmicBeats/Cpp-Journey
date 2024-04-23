#include "Manual.h"

Manual::Manual()
{
    topics = {
        {"C++ Programming Language",    {"What is C++?", "Why Learn C++?"}},

        {"C++ Basics",                  {"First C++ Program", "C++ Basic Syntax", "C++ Comments", "C++ Tokens", "C++ Identifiers", "C++ Keywords", "Difference between Keyword and Identifier"}},

        {"C++ Variables and Constants", {"C++ Variables", "C++ Constants", "Scope of C++ Variables", "C++ Storage Classes", "C++ Static Variables"}},

        {"C++ Data Types and Literals", {"C++ Data Types", "C++ Literals", "C++ Derived Data Types", "C++ User-Defined Data Types", "C++ Data Type Ranges and Their Macros",
                                         "C++ Type Modifiers", "C++ Data Type Conversion", "C++ Typecasting Operators"}},

        {"C++ Operators",               {"C++ Operators", "C++ Arithmetic Operators", "C++ Unary Operators", "C++ Bitwise Operators", "C++ Relational Operators", "C++ Logical Operators",
                                         "C++ Assignment Operators", "C++ Ternary/Conditional Operators", "C++ Sizeof Operator", "C++ Scope Resolution Operator"}},

        {"C++ Input/Output",            {"C++ Basic Input / Output", "C++ Standard Input Stream (cin)", "C++ Standard Output Stream (cout)", "C++ Standard Error Stream (cerr)",
                                         "C++ Input / Output Manipulator"}},

        {"C++ Control Statements",      {"C++ Decision Making", "C++ if Statement", "C++ if-else Statement", "C++ if-else-if Ladder", "C++ Nested if-else Statement", "C++ Switch Statement",
                                         "C++ Jump Statements", "C++ Loops", "C++ for Loop", "C++ Range-Based for Loop", "C++ while Loop", "C++ do…while Loop"}},

        {"C++ Functions",               {"C++ Functions", "C++ return", "C++ Parameter Passing Techniques", "Difference between Call by Value and Call by Reference", "C++ Default Arguments",
                                         "C++ Recursion", "C++ Inline Functions", "C++ Lambda Expression"}},

        {"C++ Pointers and References", {"C++ Pointers and References", "C++ Pointers", "C++ Pointer Arithmetic", "Dangling, Void, Null, and Wild Pointers", "Applications of Pointers",
                                         "C++ nullptr", "C++ References", "Can references refer to an invalid location in C++?", "Difference Between Pointers and References in C++",
                                         "Passing by pointer Vs Passing by Reference in C++", "When do we pass arguments by reference or pointer?"}},

        {"C++ Arrays",                  {"C++ Arrays", "C++ Multidimensional Arrays", "C++ Pointer to an Array", "Size of Array parameter", "Passing Arrays to Functions in C++",
                                         "What is Array Decay in C++? How can it be prevented?"}}
    };

    inMainTopic = true;
}

void Manual::Start()
{
    PrintSlowText("Hello user!!!\nWhat would you like to review today?\n\n");

    for (const auto& mainTopic : topics)
    {
        std::cout << mainTopic.first << std::endl;
    }

    PrintSlowText("\nPlease enter the name of the main topic you want to review: ");
    MainInputValidation();
}

void Manual::MainInputValidation()
{
    while (inMainTopic)
    {
        std::getline(std::cin, userMainTopicInput);

        if (userMainTopicInput.length() < 3)
        {
            PrintSlowText("\nPlease enter at least 3 characters: ");
            continue;
        }
        else if (userMainTopicInput == "C++")
        {
            std::cout << "\nPlease be more specific: ";
            continue;
        }

        auto iterator = FindMainTopic();

        if (iterator != topics.end())
        {
            

            PrintSlowText("\nYou have selected the topic: ");
            std::cout << iterator->first << std::endl << std::endl;

            inMainTopic = false;

            for (const auto& subtopic : iterator->second)
            {
                std::cout <<  subtopic << std::endl;
            }

            PrintSlowText("\nPlease enter the name of the sub topic you want to review: ");

            SubInputValidation();

        }
        else
        {
            std::cout << "\nSorry, the topic you entered was not found." << std::endl;
            PrintSlowText("\n\nPlease enter the name of the main topic you want to review: ");
        }
    }
}

void Manual::SubInputValidation()
{
    while (inMainTopic == false)
    {
        std::getline(std::cin, userSubTopicInput);

        if (userSubTopicInput.length() < 3)
        {
            PrintSlowText("\nPlease enter at least 3 characters: ");
            continue;
        }
        else if (userSubTopicInput == "C++")
        {
            std::cout << "\nPlease be more specific: ";
            continue;
        }

        std::string subTopics = FindSubTopic();

        if (subTopics != "")
        {
            PrintSlowText("\nYou have selected the topic: ");

            
            std::cout << subTopics << std::endl << std::endl;
            break;
        }
    }


   
}

void Manual::PrintSlowText(std::string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        std::cout << text[i];
        Sleep(25);
    }
}

std::string Manual::ToLower(const std::string& str)
{
    std::string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}


std::vector < std::pair<std::string, std::vector<std::string>>>::const_iterator Manual::FindMainTopic()
{
    std::string lowerTopicName = ToLower(userMainTopicInput);

    for (auto it = topics.begin(); it != topics.end(); ++it)
    {
        std::string lowerMainTopicName = ToLower(it->first);

        if (lowerMainTopicName.find(lowerTopicName) != std::string::npos)
        {
            return it;
        }
    }
    return topics.end();
}

std::string Manual::FindSubTopic()
{
    std::string lowerTopicName = ToLower(userSubTopicInput);

    for (size_t i = 0; i < topics.size(); ++i)
    {
        for (size_t j = 0; j < topics[i].second.size(); ++j)
        {
            std::string lowerSubTopicName = ToLower(topics[i].second[j]);

            if (lowerSubTopicName.find(lowerTopicName) != std::string::npos)
            {
                return topics[i].second[j];
            }
        }
    }
    return "";

}





