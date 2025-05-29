// -----------------------------------------------------------------------------
// File:        ex_25.cpp
// Author:      Erkam Uzuncayir
// Date:        28/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>


bool is_shorter(const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); }

bool check_size(const std::string &s, std::string::size_type sz) { return s.size() >= sz; }

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

    auto wc = std::partition(words.begin(), words.end(), bind(check_size, std::placeholders::_1, sz));

    for_each(words.begin(), wc, [](const std::string &s) { std::cout << s << ' '; });
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
