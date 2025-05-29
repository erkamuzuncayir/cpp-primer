// -----------------------------------------------------------------------------
// File:        ex_24.cpp
// Author:      Erkam Uzuncayir
// Date:        28/05/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::string;

bool check_size(const string &s, string::size_type sz) { return s.size() < sz; }

int main(void)
{
    std::vector<int> nums{1, 4, 2, 24, 5, 21, 3, 5, 6};
    string           word{"Hello"};
    auto             it = std::find_if(nums.cbegin(), nums.cend(), bind(check_size, word, std::placeholders::_1));

    std::cout << *it << '\n';

    return 0;
}
