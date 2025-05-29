// -----------------------------------------------------------------------------
// File:        ex_28.cpp
// Author:      Erkam Uzuncayir
// Date:        28/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int>   copied_nums_front;
    std::vector<int> copied_nums_back;
    std::vector<int> copied_nums_inserter;

    std::copy(nums.cbegin(), nums.cend(), std::front_inserter(copied_nums_front));
    std::copy(nums.cbegin(), nums.cend(), std::back_inserter(copied_nums_back));
    std::copy(nums.cbegin(), nums.cend(), std::inserter(copied_nums_inserter, copied_nums_inserter.begin()));

    for (auto i : copied_nums_front)
        std::cout << i << ' ';

    std::cout << '\n';
    for (auto i : copied_nums_back)
        std::cout << i << ' ';

    std::cout << '\n';
    for (auto i : copied_nums_inserter)
        std::cout << i << ' ';
}
