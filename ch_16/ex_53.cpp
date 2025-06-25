// -----------------------------------------------------------------------------
// File:        ex_53.cpp
// Author:      Erkam Uzuncayir
// Date:        24/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &...rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    std::cout << "--- One argument ---\n";
    print(std::cout, 42) << '\n';

    std::cout << "--- Two arguments ---\n";
    print(std::cout, 3.14, "Pi") << '\n';

    std::cout << "--- Five arguments (all different types) ---\n";
    print(std::cout, 1, 2.5, std::string("hello"), 'x', true) << '\n';

    return 0;
}
