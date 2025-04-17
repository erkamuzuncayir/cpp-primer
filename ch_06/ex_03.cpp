//
// Created by erkam on 4/16/25.
//

#include <iostream>

int fact(int val)
{
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1)
        ret *= val--; // assign ret * val to ret and decrement val
    return ret;       // return the result
}

int main(void)
{
    std::cout << "fact(5) = " << fact(5) << std::endl;
}
