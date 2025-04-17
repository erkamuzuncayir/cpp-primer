//
// Created by erkam on 4/16/25.
//

#include <iostream>
#include "../ch_06.h"

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
