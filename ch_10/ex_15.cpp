// -----------------------------------------------------------------------------
// File:        ex_15.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <iostream>

int main(void)
{
    int  num_2 = 4;
    auto sum = [num_2](int num_1) { return num_1 + num_2; };
    std::cout << sum(2) << ' ';

    return 0;
}
