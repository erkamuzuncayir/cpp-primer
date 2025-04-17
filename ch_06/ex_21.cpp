//
// Created by erkam on 4/16/25.
//

#include <iostream>

int detect_larger(const int* ptr_int, const int n)
{
    return *ptr_int > n ? *ptr_int : n;
}

int main(void)
{
    int n1 = 5, n2 = 6;
    std::cout << "n1 = " << n1 << std::endl;
    std::cout << "n2 = " << n2 << std::endl;

    std::cout << detect_larger(&n1, n2) << " is the bigger one." << std::endl;
}
