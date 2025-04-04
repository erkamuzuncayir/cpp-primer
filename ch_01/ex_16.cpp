//
// Created by Erkam on 4/2/2025.
//

#include <iostream>

int main()
{
    int sum   = 0;
    int input = 0;

    while (std::cin >> input)
        sum += input;

    std::cout << sum << std::endl;
    return 0;
}
