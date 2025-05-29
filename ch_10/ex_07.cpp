// -----------------------------------------------------------------------------
// File:        ex_07.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <numeric>
#include <vector>

int main(void)
{
    std::vector<int> vec;
    std::list<int>   lst;
    int              i;
    while (std::cin >> i)
        lst.push_back(i);

    copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));

    std::vector<int> vec_2;
    vec_2.resize(10); // reserve is covered in § 9.4 (p. 356)
    fill_n(vec_2.begin(), 10, 0);

    return 0;
}
