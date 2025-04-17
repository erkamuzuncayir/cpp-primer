//
// Created by erkam on 4/16/25.
//

#include <iostream>

unsigned my_abs(int n)
{
    return static_cast<unsigned>(n);
}

int main(void)
{
    std::cout << "Absolute value of -5 is: " << my_abs(5) << std::endl;
}