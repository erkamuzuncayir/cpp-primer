// -----------------------------------------------------------------------------
// File:        ex_01.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> nums{0, 2, 2, 2, 4, 5};

    std::cout << std::count(nums.cbegin(), nums.cend(), 2) << std::endl;

    return 0;
}
