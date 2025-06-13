// -----------------------------------------------------------------------------
// File:        ex_23.cpp
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------

#include <cstring>
#include <iostream>
#include <string>

int main()
{
    const char *str_lit_one = "one";
    const char *str_lit_two = "two";
    char       *concat      = new char[strlen(str_lit_one) + strlen(str_lit_two) + 1];
    strcpy(concat, str_lit_one);
    strcat(concat, str_lit_two);
    std::cout << "Literal: " << concat << std::endl;
    delete[] concat;

    std::string str_one    = "one";
    std::string str_two    = "two";
    char       *concat_str = new char[str_one.size() + str_two.size() + 1];
    strcpy(concat_str, str_one.c_str());
    strcat(concat_str, str_two.c_str());
    std::cout << "Library: " << concat_str << std::endl;
    delete[] concat_str;
}
