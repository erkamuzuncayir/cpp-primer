//
// Created by Erkam on 4/2/2025.
//

#include <iostream>

int main()
{
    int n_1, n_2;

    std::cout << "Please enter two integer: ";
    std::cin >> n_1;
    std::cin >> n_2;

    n_1++;
    while (n_1 < n_2)
        std::cout << n_1++ << " ";

    std::cout << std::endl;

    return 0;
}
