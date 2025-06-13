// -----------------------------------------------------------------------------
// File:        ex_24.cpp
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
int main()
{
    int char_count;
    std::cout << "Enter string length: ";
    std::cin >> char_count;
    std::cin.ignore();

    char *str = new char[char_count + 1];
    std::cin.read(str, char_count);
    str[char_count] = '\0';

    std::cout << str << std::endl;

    delete[] str;
}
