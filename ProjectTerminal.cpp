#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

void PrintSlowText(std::string text);

int main()
{
    PrintSlowText("Yoooooooo!!!!\n");
}

void PrintSlowText(std::string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        std::cout << text[i];
        Sleep(25);
    }
}
