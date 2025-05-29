// -----------------------------------------------------------------------------
// File:        ex_37.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> vec_nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int>   li_nums;

    li_nums.resize(vec_nums.size());
    std::copy(vec_nums.crbegin() + 3, vec_nums.crend() - 2, li_nums.begin());

    for (int n : li_nums)
        std::cout << n << ' ';

    return 0;
}
