// -----------------------------------------------------------------------------
// File:        ex_42.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <list>

void eliminate_duplicates(std::list<std::string> &words)
{
    for (auto c : words)
        std::cout << c << ' ';
    std::cout << std::endl;

    words.sort();
    for (auto c : words)
        std::cout << c << ' ';
    std::cout << std::endl;

    words.unique();
    for (auto c : words)
        std::cout << c << ' ';
    std::cout << std::endl;
}

int main(void)
{
    std::list<std::string> words{
        "hello", "hello", "hello", "world", "world", "world",
    };

    eliminate_duplicates(words);
    return 0;
}
