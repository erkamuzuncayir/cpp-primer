// -----------------------------------------------------------------------------
// File:        ex_11.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

bool is_shorter(const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); }

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
    std::stable_sort(words.begin(), words.end(), is_shorter);
}

int main(void)
{
    std::vector<std::string> words{
        "slow", "jumps", "red", "over", "jumps", "turtle", "fox", "over", "the", "fox", "quick",
    };

    eliminate_duplicates(words);

    for (auto s : words)
        std::cout << s << ' ';

    return 0;
}
