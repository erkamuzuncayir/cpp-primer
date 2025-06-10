// -----------------------------------------------------------------------------
// File:        ex_07.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string;

int main(void)
{
    std::map<string, std::vector<string>> family_child_name_map;
    string                                family_name, child_name;

    std::cout << "Enter a family name (or \"exit\" to quit): ";
    while (std::cin >> family_name && family_name != "exit")
    {
        std::cout << "Enter children names (type \"done\" when finished): ";

        while (std::cin >> child_name && child_name != "done")
            family_child_name_map[family_name].push_back(child_name);

        std::cout << "Enter a family name (or \"exit\" to quit): ";
    }

    for (const auto &f_n : family_child_name_map)
    {
        std::cout << "Children names of " << f_n.first << " family are: ";
        for (const auto &c_n : f_n.second)
        {
            std::cout << c_n << ", ";
        }
        std::cout << std::endl;
    }
}
