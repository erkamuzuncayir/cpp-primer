//
// Created by Erkam on 4/4/2025.
//

#include <iostream>

int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;

    std::cout << i << " " << sum << std::endl;  // Legal, it prints "100 45".
}
