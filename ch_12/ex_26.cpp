// -----------------------------------------------------------------------------
// File:        ex_26.cpp
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>

using std::string;

int main()
{
    int                    n = 5;
    std::allocator<string> str_alloc;
    auto const             p = str_alloc.allocate(n);
    string                 temp, *input = p;
    while (std::cin >> temp && input != p + n)
        str_alloc.construct(input++, temp);

    int count = input - p;
    for (int i = 0; i < count; i++)
        std::cout << p[i] << std::endl;

    while (input != p)
        str_alloc.destroy(--input);

    str_alloc.deallocate(p, n);
}
