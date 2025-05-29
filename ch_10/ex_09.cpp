// -----------------------------------------------------------------------------
// File:        ex_09.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

void eliminate_duplicates(std::vector<std::string> &words)
{
    for (auto c : words)
        std::cout << c << ' ';
    std::cout << std::endl;

    std::sort(words.begin(), words.end());
    for (auto c : words)
        std::cout << c << ' ';
    std::cout << std::endl;

    auto end_unique = std::unique(words.begin(), words.end());
    for (auto c : words)
        std::cout << c << ' ';
    std::cout << std::endl;

    words.erase(end_unique, words.end());
    for (auto c : words)
        std::cout << c << ' ';
    std::cout << std::endl;
}

int main(void)
{
    std::vector<std::string> words{
        "hello", "hello", "hello", "world", "world", "world",
    };

    eliminate_duplicates(words);
    return 0;
}
