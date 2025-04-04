//
// Created by Erkam on 4/2/2025.
//

#include <iostream>
#include "Sales_item.h"

int main()
{
    int        n = 3;
    Sales_item book;
    Sales_item sum_of_transactions;

    while (n-- > 0)
    {
        std::cin >> book;
        if (book.isbn() == sum_of_transactions.isbn())
            sum_of_transactions += book;
        else
        {
            std::cout << sum_of_transactions << std::endl;
            book = sum_of_transactions;
        }
    }

    std::cout << sum_of_transactions << std::endl;
    return 0;
}
