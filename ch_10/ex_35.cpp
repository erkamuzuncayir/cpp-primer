// -----------------------------------------------------------------------------
// File:        ex_35.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6};

    auto end = nums.cend();
    while (true)
    {
        --end;
        std::cout << *end << ' ';
        if (end == nums.cbegin())
            break;
    }

    return 0;
}
