// -----------------------------------------------------------------------------
// File:        ex_06.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <numeric>
#include <vector>

int main(void)
{
    std::vector<int> nums{0, 2, 2, 2, 4, 5};
    std::fill_n(nums.begin(), 5, 0);

    for (auto n : nums)
        std::cout << n << ' ';

    return 0;
}
