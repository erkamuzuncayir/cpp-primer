// -----------------------------------------------------------------------------
// File:        ex_27.cpp
// Author:      Erkam Uzuncayir
// Date:        28/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> nums{1, 2, 3, 4, 5, 5, 5, 6, 6};
    std::vector<int> unique_nums;

    std::unique_copy(nums.cbegin(), nums.cend(), std::inserter(unique_nums, unique_nums.begin()));

    for (auto i : unique_nums)
        std::cout << i << ' ';
}
