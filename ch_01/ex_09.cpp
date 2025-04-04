//
// Created by Erkam on 4/2/2025.
//

#include <iostream>

int main()
{
    int sum   = 0;
    int n = 50;

    while (n < 100)
        sum += n++;

    std::cout << sum << std::endl;
    return 0;
}
