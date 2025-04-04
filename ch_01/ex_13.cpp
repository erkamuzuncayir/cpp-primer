//
// Created by Erkam on 4/2/2025.
//

#include <iostream>

int main()
{
    int sum = 0, n_1, n_2;;

    for (int i = 0; i <= 10; i++)
        sum += i;

    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

    //   ----   //

    for (int i = 10; i > 0; i--)
        std::cout << i << std::endl;

    //   ----   //

    std::cout << "Please enter two integer: ";
    std::cin >> n_1;
    std::cin >> n_2;

    for (n_1++; n_1 < n_2; n_1++)
        std::cout << n_1 << " ";

    return 0;
}
