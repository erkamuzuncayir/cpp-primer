// -----------------------------------------------------------------------------
// File:        ex_14.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <iostream>

int main(void)
{
    auto sum = [](int num_1, int num_2) { return num_1 + num_2; };
    std::cout << sum(2, 4) << ' ';

    return 0;
}
