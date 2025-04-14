//
// Created by erkam on 4/14/25.
//

#include <iostream>

int main()
{
    double first_num, second_num;

    std::cout << "Enter two number: ";
    std::cin >> first_num >> second_num;

    if (second_num == 0)
        throw std::runtime_error("Second number cannot be zero!");

    std::cout << first_num / second_num << std::endl;
}
