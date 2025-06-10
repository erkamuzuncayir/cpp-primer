// -----------------------------------------------------------------------------
// File:        ex_14.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::string;

int main(void)
{
    std::map<string, std::vector<std::pair<string, string>>> family_child_name_map;
    string                                                   family_name, child_name, birthday;

    std::cout << "Enter a family name (or \"exit\" to quit): ";
    while (std::cin >> family_name && family_name != "exit")
    {
        std::cout << "Enter children names and birthday as a DD/MM/YYYY (type \"done\" when finished): ";

        while (std::cin >> child_name && child_name != "done")
        {
            while (std::cin >> birthday && birthday != "done")
            {
                family_child_name_map[family_name].push_back(std::make_pair(child_name, birthday));
                break;
            }
        }
        std::cout << "Enter a family name (or \"exit\" to quit): ";
    }

    for (const auto& f_n : family_child_name_map)
    {
        std::cout << "Children names and birthdays of " << f_n.first << " family are: ";
        for (const auto& c_n : f_n.second)
        {
            std::cout << c_n.first << " birth at the " << c_n.second << ", ";
        }
        std::cout << std::endl;
    }
}
