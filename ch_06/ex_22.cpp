//
// Created by erkam on 4/16/25.
//

#include <iostream>

void swap_pointers(int*& ptr_1, int*& ptr_2)
{
    int* temp = ptr_1;
    ptr_1     = ptr_2;
    ptr_2     = temp;
}

int main(void)
{
    int  n_1   = 2, n_2 = 3;
    int* ptr_1 = &n_1;
    int* ptr_2 = &n_2;

    std::cout << "*ptr_1 = " << *ptr_1 << ", *ptr_2 = " << *ptr_2 << std::endl;
    swap_pointers(ptr_1, ptr_2);
    std::cout << "*ptr_1 = " << *ptr_1 << ", *ptr_2 = " << *ptr_2 << std::endl;
}
