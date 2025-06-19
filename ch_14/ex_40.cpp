// -----------------------------------------------------------------------------
// File:        ex_40.cpp
// Author:      Erkam Uzuncayir
// Date:        19/06/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Is_Shorter
{
public:
    bool operator()(const std::string &s1, const std::string &s2) const { return s1.size() < s2.size(); }
};

class Eliminate_Duplicates
{
public:
    void operator()(std::vector<std::string> &words)
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
};

class Biggies
{
public:
    void operator()(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
    {
        Eliminate_Duplicates elm_dups;
        elm_dups(words);
        std::stable_sort(words.begin(), words.end(), Is_Shorter());

        auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &s) { return s.size() >= sz; });

        std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << ' '; });
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<std::string> words{
        "slow", "jumps", "red", "over", "jumps", "turtle", "fox", "over", "the", "fox", "quick",
    };

    Biggies biggies;
    biggies(words, 5);

    return 0;
}
