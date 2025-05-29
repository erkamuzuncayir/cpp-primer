// -----------------------------------------------------------------------------
// File:        ex_36.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5, 0, 6};

    auto it = std::find(nums.crbegin(), nums.crend(), 0);

    std::cout << "0 is between " << *(--it) << " and " << *(it + 1) << '\n';
    return 0;
}
