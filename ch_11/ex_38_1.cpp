// -----------------------------------------------------------------------------
// File:        ex_38_1.cpp
// Author:      Erkam Uzuncayir
// Date:        10/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

int main(void)
{
    std::unordered_map<string, size_t> word_count_map;
    string                             word;

    while (std::cin >> word)
        ++word_count_map[word];

    for (const auto& w : word_count_map)
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << '\n';
}
