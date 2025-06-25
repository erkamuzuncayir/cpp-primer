// -----------------------------------------------------------------------------
// File:        ex_51_52.cpp
// Author:      Erkam Uzuncayir
// Date:        24/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

template <typename T, typename... Args>
void foo(T t, Args... args)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}

int main()
{
    foo(1, 2);
    foo(1, 23, 4, 5, 6);
}
