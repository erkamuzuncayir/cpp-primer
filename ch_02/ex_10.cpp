//
// Created by Erkam on 4/3/2025.
//

#include <iostream>

std::string global_str;
int         global_int;

int main()
{
    int         local_int;
    std::string local_str;

    std::cout << "gs" << global_str << std::endl; // Default value -> ""
    std::cout << "gi" << global_int << std::endl; // Default value -> 0

    std::cout << "ls" << local_str << std::endl; // Default value defined by class
    std::cout << "li" << local_int << std::endl; // No default value, undefined.
}
