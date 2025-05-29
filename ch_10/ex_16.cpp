// -----------------------------------------------------------------------------
// File:        ex_16.cpp
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
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    eliminate_duplicates(words);
    std::stable_sort(words.begin(), words.end(), is_shorter);

    auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &s) { return s.size() >= sz; });

    for_each(wc, words.end(), [](const std::string &s) { std::cout << s << ' '; });
    std::cout << std::endl;
}

int main(void)
{
    std::vector<std::string> words{
        "slow", "jumps", "red", "over", "jumps", "turtle", "fox", "over", "the", "fox", "quick",
    };

    biggies(words, 5);

    return 0;
}
