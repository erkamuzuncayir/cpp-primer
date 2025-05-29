// -----------------------------------------------------------------------------
// File:        ex_05.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

// It doesn't work as intended.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::vector<const char *> words_1 = {
        "hello", "hello", "hello", "hello", "world",
    };

    std::vector<const char *> words_2 = {
        "hello", "hello", "hello", "hello", "world",
    };

    std::cout << std::equal(words_1.cbegin(), words_1.cend(), words_2.cbegin());

    return 0;
}
