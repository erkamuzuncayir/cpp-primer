// -----------------------------------------------------------------------------
// File:        ex_06.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

template <typename T, std::size_t N>
T *my_begin(T (&arr)[N])
{
    return arr;
}

template <typename T, std::size_t N>
T *my_end(T (&arr)[N])
{
    return arr + N;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    for (const int *it = my_begin(arr); it != my_end(arr); ++it)
        std::cout << *it << " ";

    std::cout << "\n";
}
