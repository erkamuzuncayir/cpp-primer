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

int get_input()
{
    int input;
    std::cout << "Enter an integer: ";
    std::cin >> input;
    return input;
}

int main(void)
{
    const int result = fact(get_input());
    std::cout << "Factorial of input is: " << result << std::endl;

    return 0;
}
