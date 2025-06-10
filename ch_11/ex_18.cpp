// -----------------------------------------------------------------------------
// File:        ex_18.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <iterator>
#include <map>
#include <string>

using std::copy;

int main(void)
{
    std::map<std::string, int>                 word_count;
    std::map<std::string, int>::const_iterator map_it = word_count.cbegin();
    while (map_it != word_count.cend())
    {
        std::cout << map_it->first << " occurs " << map_it->second << " times" << std::endl;
        ++map_it;
    }
}