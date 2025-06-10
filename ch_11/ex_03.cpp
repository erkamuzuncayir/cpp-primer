// -----------------------------------------------------------------------------
// File:        ex_03.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>

using std::string;

int main(void)
{
    std::map<string, size_t> word_count_map;
    string                   word;

    while (std::cin >> word)
        ++word_count_map[word];

    for (const auto &w : word_count_map)
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << '\n';
}
