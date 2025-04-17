//
// Created by erkam on 4/17/25.
//

#include <initializer_list>
#include <iostream>

using std::cout;
using std::initializer_list;

int sum(const initializer_list<int> nums)
{
    int sum = 0;
    for (auto beg = nums.begin(); beg != nums.end(); ++beg)
        sum += *beg;

    return sum;
}

int main(void)
{
    std::cout << sum({1, 2, 3}) << std::endl;
}
