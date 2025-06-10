// -----------------------------------------------------------------------------
// File:        ex_08.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <set>
#include <string>
#include <vector>

bool is_shorter(const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); }

void eliminate_duplicates(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main(void)
{
    std::vector<std::string> vec_words{
        "slow", "jumps", "red", "over", "jumps", "red", "fox", "over", "the", "fox", "quick",
    };

    std::set<std::string> set_words{vec_words.begin(), vec_words.end()};
    eliminate_duplicates(vec_words);

    return 0;
}
