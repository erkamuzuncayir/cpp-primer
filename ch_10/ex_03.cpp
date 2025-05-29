// -----------------------------------------------------------------------------
// File:        ex_03.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <numeric>
#include <vector>

int main(void)
{
    std::vector<int> nums{0, 2, 2, 2, 4, 5};

    std::cout << std::accumulate(nums.cbegin(), nums.cend(), 0) << std::endl;

    return 0;
}
