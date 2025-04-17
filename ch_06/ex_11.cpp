//
// Created by erkam on 4/16/25.
//

#include <iostream>

void reset(int& n)
{
    n = 0;
}

int main(void)
{
    int n = 5;
    std::cout << n << std::endl;
    reset(n);
    std::cout << n << std::endl;
}
