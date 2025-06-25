// -----------------------------------------------------------------------------
// File:        ex_07.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

template <typename T, std::size_t N>
std::size_t constexpr my_size(T (&arr)[N])
{
    return N;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << my_size(arr) << std::endl;
}
