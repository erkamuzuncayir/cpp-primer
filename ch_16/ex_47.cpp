// -----------------------------------------------------------------------------
// File:        ex_47.cpp
// Author:      Erkam Uzuncayir
// Date:        24/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void l_ref(int &a, int &b) { std::cout << "lref(int&, int&): " << a << ", " << b << '\n'; }

void r_ref(int &&a, int &&b) { std::cout << "rref(int&&, int&&): " << a << ", " << b << '\n'; }

void mix(int &a, int &&b) { std::cout << "mix(int&, int&&): " << a << ", " << b << '\n'; }

int main()
{
    int a = 10, b = 20;

    flip(l_ref, a, b); // OK: a, b are lvalues
    flip(r_ref, 1, 2); // OK: both rvalues

    return 0;
}
