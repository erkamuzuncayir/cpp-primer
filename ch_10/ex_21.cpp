// -----------------------------------------------------------------------------
// File:        ex_21.cpp
// Author:      Erkam Uzuncayir
// Date:        27/05/2025
// -----------------------------------------------------------------------------

#include <iostream>

int main(void)
{
    int  num = 4;
    auto decremented_num   = [&num]() { return num == 0 ? 0: --num; };
    std::cout << decremented_num() << '\n';
    std::cout << decremented_num() << '\n';
    std::cout << decremented_num() << '\n';
    std::cout << decremented_num() << '\n';
    std::cout << decremented_num() << '\n';
    std::cout << decremented_num() << '\n';

    return 0;
}
