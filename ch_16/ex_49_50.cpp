// -----------------------------------------------------------------------------
// File:        ex_49_50.cpp
// Author:      Erkam Uzuncayir
// Date:        24/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

template <typename T>
void f(T)
{
    std::cout << "f(T) called with T = " << typeid(T).name() << "\n";
}

template <typename T>
void f(const T *)
{
    std::cout << "f(const T*) called with T = " << typeid(T).name() << "\n";
}

template <typename T>
void g(T)
{
    std::cout << "g(T) called with T = " << typeid(T).name() << "\n";
}

template <typename T>
void g(T *)
{
    std::cout << "g(T*) called with T = " << typeid(T).name() << "\n";
}

int main()
{
    int        i  = 42;
    int       *p  = &i;
    const int  ci = 0;
    const int *p2 = &ci;

    std::cout << "--- g(42) ---\n";
    g(42); // g(T)

    std::cout << "--- g(p) ---\n";
    g(p); // g(T*)

    std::cout << "--- g(ci) ---\n";
    g(ci); // g(T)

    std::cout << "--- g(p2) ---\n";
    g(p2); // g(T*)

    std::cout << "--- f(42) ---\n";
    f(42); // f(T)

    std::cout << "--- f(p) ---\n";
    f(p); // f(T)

    std::cout << "--- f(ci) ---\n";
    f(ci); // f(T)

    std::cout << "--- f(p2) ---\n";
    f(p2); // f(const T*)

    return 0;
}
