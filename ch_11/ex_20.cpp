// -----------------------------------------------------------------------------
// File:        ex_20.cpp
// Author:      Erkam Uzuncayir
// Date:        05/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string;

int main()
{
    std::map<string, size_t> word_count_map;
    string                   word;

    while (std::cin >> word)
    {
        auto input = word_count_map.insert(make_pair(word, 1));
        if (!input.second)
            ++input.first->second;
    }

    for (const auto& w : word_count_map)
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << '\n';

    std::map<string, std::vector<int>> test;
    std::pair<std::string, std::vector<int>> newEntry;
    test.insert(newEntry);




}
