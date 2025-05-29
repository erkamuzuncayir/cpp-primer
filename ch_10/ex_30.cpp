// -----------------------------------------------------------------------------
// File:        ex_30.cpp
// Author:      Erkam Uzuncayir
// Date:        29/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::istream_iterator<int> int_it(std::cin), eof;
    std::vector<int>           nums(int_it, eof);
    std::sort(nums.begin(), nums.end());
    std::ostream_iterator<int> out_it(std::cout);
    std::copy(nums.begin(), nums.end(), out_it);
    return 0;
}
