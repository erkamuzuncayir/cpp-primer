// -----------------------------------------------------------------------------
// File:        ex_07.cpp
// Author:      Erkam Uzuncayir
// Date:        11/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> get_int_vec()
{
    return std::make_shared<std::vector<int>>();
}

void fill_vec(std::shared_ptr<std::vector<int>> &vec)
{
    int temp = 0;
    while (std::cin >> temp)
        vec->push_back(temp);
}

void print_vec(const std::shared_ptr<std::vector<int>> &vec)
{
    for (const int &it : *vec)
        std::cout << it << " ";
}

int main()
{
    auto vec = get_int_vec();
    fill_vec(vec);
    print_vec(vec);
    return 0;
}
