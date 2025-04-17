//
// Created by erkam on 4/16/25.
//

#include <iostream>

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1      = *n2;
    *n2      = temp;
}

int main(void)
{
    int n1 = 2, n2 = 4;
    std::cout << n1 << n2 << std::endl;
    swap(&n1, &n2);
    std::cout << n1 << n2;
}
