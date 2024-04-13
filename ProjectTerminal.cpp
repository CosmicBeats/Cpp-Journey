#include <iostream>
#include <Windows.h>
#include <vector>
#include <unordered_map>
#include <string>

void Start();
void PrintSlowText(std::string text);
void UserValidation(int& pUserInput);
void DisplayTopic(int& pUserInput);

int main()
{
    void Start();
}

void Start()
{
    int userInput = 0;

    std::vector<std::string> topics{ "1.  C++ Basics", "2.  C++ Variables and Constants", "3.  C++ Data Types and Literals", "4.  C++ Operators", "5.  C++ Input/Output",
                              "6.  C++ Control Statements", "7.  C++ Funtions", "8.  C++ Pointer and References", "9.  C++ Arrays", "10. C++ Strings" };

    PrintSlowText("Hello user!!!\nWhat would you like to review today?\n\n");

    for (int i = 0; i < topics.size(); i++)
    {
        std::cout << topics[i] << std::endl;
    }

    PrintSlowText("\n\nPlease choose a number:");
    UserValidation(userInput);
}

void DisplayTopic(int& pUserInput)
{
    switch(pUserInput)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    }
}

// Helper function for input validation
void UserValidation(int& pUserInput)
{
    while (true)
    {
        std::cin >> pUserInput;
        if (std::cin.fail() && !isdigit(pUserInput))
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            PrintSlowText("\n\nThat is not a number!!!\nPlease choose a number:");
        }
        else if (pUserInput > 10 || pUserInput < 1)
        {
            PrintSlowText("\n\nThat is not a choice!!!\nPlease choose a number:");
        }
        else
        {
            break;
        }
    }
    
}

// Helper function to print text slowly
void PrintSlowText(std::string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        std::cout << text[i];
        Sleep(25);
    }
}
