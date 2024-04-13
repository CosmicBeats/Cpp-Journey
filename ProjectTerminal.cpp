#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

void PrintSlowText(std::string text);
void UserValidation(int& pUserInput);
//void DisplayTopic(int& pUserInput);

int main()
{
    // Needed variables to work with ^.^

    int userInput = 0;

    std::vector<std::string> topics {"1.  C++ Basics", "2.  C++ Variables and Constants", "3.  C++ Data Types and Literals", "4.  C++ Operators", "5.  C++ Input/Output",
                              "6.  C++ Control Statements", "7.  C++ Funtions", "8.  C++ Pointer and References", "9.  C++ Arrays", "10. C++ Strings"};

    PrintSlowText("Hello user!!!\nWhat would you like to review today?\n\n");

    for (int i = 0; i < topics.size(); i++)
    {
        std::cout << topics[i] << std::endl;
    }

    PrintSlowText("\n\nPlease choose a number:");
    UserValidation(userInput);


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
