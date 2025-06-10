// -----------------------------------------------------------------------------
// File:        ex_31.cpp
// Author:      Erkam Uzuncayir
// Date:        10/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>

using std::string;

int main()
{
    std::multimap<string, string> authors{{"Jane", "A"},  {"Jane", "B"},  {"George", "C"}, {"George", "D"},
                                          {"Roger", "E"}, {"Roger", "F"}, {"Robert", "G"}, {"Robert", "H"},
                                          {"Lewis", "I"}, {"Lewis", "J"}};
    auto                          key_it     = authors.find("Robert");
    string                        search_val = "G";
    if (key_it != authors.end())
    {
        while (key_it != authors.end())
        {
            if (key_it->second == search_val)
            {
                std::cout << "Found " << key_it->second << " at " << key_it->first << std::endl;
                key_it = authors.erase(key_it);
            }
            else
                ++key_it;
        }
    }
    else
        std::cout << "Not found" << std::endl;
}
