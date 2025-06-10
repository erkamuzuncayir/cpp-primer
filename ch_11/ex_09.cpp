// -----------------------------------------------------------------------------
// File:        ex_09.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <list>

using std::string;

int main(void)
{
    std::map<string, std::list<int>> word_line_number_map;
    int                                line_number = 1;
    std::ifstream                      in("C:/Repository/StudyRepositories/cpp-primer/input.txt");

    if (!in)
    {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    string line;
    while (std::getline(in, line))
    {
        std::istringstream iss(line);
        string             word;

        while (iss >> word)
        {
            word_line_number_map[word].push_back(line_number);
        }
        ++line_number;
    }

    for (const auto &w : word_line_number_map)
    {
        std::cout << w.first << " occurred at ";
        for (const auto &n : w.second)
            std::cout << n << ", ";

        std::cout << " lines.\n";
    }
    return 0;
}
