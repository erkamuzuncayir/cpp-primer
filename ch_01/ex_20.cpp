//
// Created by Erkam on 4/2/2025.
//

#include <iostream>
#include "Sales_item.h"

int main()
{
    int        n = 3;
    Sales_item book;
    while (n-- > 0)
    {
        std::cin >> book;
        std::cout << book << std::endl;
    }
    return 0;
}
