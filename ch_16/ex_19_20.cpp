// -----------------------------------------------------------------------------
// File:        ex_19_20.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

template <typename T>
void print(const T& cont)
{
    for (auto it: cont)
        std::cout << it;

    std::cout << std::endl;

    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
        std::cout << *it;
}

int main()
{
    print(std::string("Hello World!"));
}