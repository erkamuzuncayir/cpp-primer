// -----------------------------------------------------------------------------
// File:        ex_23.cpp
// Author:      Erkam Uzuncayir
// Date:        06/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string;

int main(void)
{
    std::multimap<string, string> family_child_name_map;
    string                        family_name, child_name;

    std::cout << "Enter children full name (type \"done\" when finished): ";
    while (std::cin >> family_name >> child_name && (family_name != "done" && child_name != "done"))
    {
        family_child_name_map.emplace(family_name, child_name);
        std::cout << "Enter children full name (type \"done\" when finished): ";
    }

    for (const auto& f_n : family_child_name_map)
    {
        std::cout << "Children names of " << f_n.first << " family are: " << f_n.second;
        std::cout << std::endl;
    }
}
