//
// Created by Erkam on 4/2/2025.
//

#include <iostream>

int main()
{
    int low, high;

    std::cout << "Please enter two integer: ";
    std::cin >> low;
    std::cin >> high;

    if (low > high)
    {
        const int temp = low;
        low            = high;
        high           = temp;
    }

    while (low < high - 1)
        std::cout << ++low << " ";

    std::cout << std::endl;

    return 0;
}
