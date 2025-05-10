// -----------------------------------------------------------------------------
// File:        ex_38.cpp
// Author:      Erkam Uzuncayir
// Date:        09/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;
    for (std::string temp; std::cin >> temp; v.push_back(temp))
        std::cout << v.capacity() << std::endl;

    return 0;
}
