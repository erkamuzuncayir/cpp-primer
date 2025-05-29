// -----------------------------------------------------------------------------
// File:        ex_20.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

bool is_longer_than_six_chars(const std::string &s1) { return s1.size() > 6; }

int main(void)
{
    std::vector<std::string> words{
        "slow", "jumps", "red", "over", "jumps", "tortoise", "fox", "over", "the", "fox", "quick",
    };

    auto count = std::count_if(words.cbegin(), words.cend(), [](const std::string &s1) { return s1.size() > 6; });

    std::cout << count << ' ';

    return 0;
}
