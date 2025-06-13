// -----------------------------------------------------------------------------
// File:        ex_06.cpp
// Author:      Erkam Uzuncayir
// Date:        11/06/2025
// -----------------------------------------------------------------------------

#include <initializer_list>
#include <iostream>
#include <vector>

std::vector<int> * get_int_vec()
{
    auto vec = new std::vector<int>();
    return vec;
}

void fill_vec(std::vector<int> & vec)
{
    int temp = 0;
    while (std::cin >> temp)
        vec.push_back(temp);
}

void print_vec(const std::vector<int> & vec)
{
    for (const int & it : vec)
        std::cout << it << " ";
}

int main()
{
    std::vector<int> *vec = get_int_vec();
    fill_vec(*vec);
    print_vec(*vec);
    delete vec;
    return 0;
}