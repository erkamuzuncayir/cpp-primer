// -----------------------------------------------------------------------------
// File:        ex_39.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------


#include <iostream>

template <typename T>
int compare(const T &v_1, const T &v_2)
{
    if (v_1 < v_2) return -1;
    if (v_2 < v_1) return 1;
    return 0;
}

int main()
{
    std::cout << compare<std::string>("hello", "worlddd") << std::endl;
}