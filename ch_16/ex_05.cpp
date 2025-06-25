// -----------------------------------------------------------------------------
// File:        ex_05.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

template <typename Array>
void my_print(Array const &arr)
{
    for (auto const &e : arr)
        std::cout << e << " ";
}

int main()
{
    char ch_arr[]  = {'H', 'e', 'l', 'l', 'o'};
    int  int_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    my_print(ch_arr);
    std::cout << std::endl;
    my_print(int_arr);
}
