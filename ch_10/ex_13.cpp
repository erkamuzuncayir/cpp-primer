// -----------------------------------------------------------------------------
// File:        ex_13.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

bool is_longer_than_or_equal_to_five_chars(const std::string &s1) { return s1.size() >= 5; }

int main(void)
{
    std::vector<std::string> words{
        "slow", "jumps", "red", "over", "jumps", "turtle", "fox", "over", "the", "fox", "quick",
    };

    auto end_of_five = std::partition(words.begin(), words.end(), is_longer_than_or_equal_to_five_chars);

    for (auto beg = words.cbegin(); beg != end_of_five; beg++)
        std::cout << *beg << ' ';

    return 0;
}
