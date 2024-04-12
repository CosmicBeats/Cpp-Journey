#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

void PrintSlowText(std::string text);

int main()
{
    // Needed variables to work with ^.^
    std::vector<std::string> topics {"1.  C++ Basics", "2.  C++ Variables and Constants", "3.  C++ Data Types and Literals", "4.  C++ Operators", "5.  C++ Input/Output",
                              "6.  C++ Control Statements", "7.  C++ Funtions", "8.  C++ Pointer and References", "9.  C++ Arrays", "10. C++ Strings"};

    PrintSlowText("Hello user!!!\nWhat would you like to review today?\n\n");

    for (int i = 0; i < topics.size(); i++)
    {
        std::cout << topics[i] << std::endl;
    }
}

void PrintSlowText(std::string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        std::cout << text[i];
        Sleep(25);
    }
}
