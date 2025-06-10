// -----------------------------------------------------------------------------
// File:        ex_32.cpp
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
    std::multimap<string, string> ordered_authors;

    ordered_authors.insert(authors.begin(), authors.end());
    for (const auto& it : ordered_authors)
        std::cout << it.first << " " << it.second << std::endl;
}
