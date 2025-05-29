// -----------------------------------------------------------------------------
// File:        ex_34.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6};

    for (auto end = nums.crbegin(); end != nums.crend(); ++end)
        std::cout << *end << ' ';

    return 0;
}
