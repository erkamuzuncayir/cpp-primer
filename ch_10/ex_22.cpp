// -----------------------------------------------------------------------------
// File:        ex_22.cpp
// Author:      Erkam Uzuncayir
// Date:        28/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

bool is_shorter_than_or_equal_to_six_chars(const std::string &s1) { return s1.size() <= 6; }

int main(void)
{
    std::vector<std::string> words{
        "slow", "jumps", "red", "over", "jumps", "tortoise", "fox", "over", "the", "fox", "quick",
    };

    auto count = std::count_if(words.cbegin(), words.cend(), is_shorter_than_or_equal_to_six_chars);

    std::cout << count << ' ';

    return 0;
}
