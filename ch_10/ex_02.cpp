// -----------------------------------------------------------------------------
// File:        ex_02.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::vector<std::string> words{
        "hello", "hello", "hello", "hello", "world",
    };

    std::cout << std::count(words.cbegin(), words.cend(), "hello") << std::endl;

    return 0;
}
