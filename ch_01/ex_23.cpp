//
// Created by Erkam on 4/2/2025.
//

#include <iostream>
#include "Sales_item.h"

int main()
{
    int        n = 10, count = 0;
    Sales_item book;

    std::cin >> book;
    Sales_item cur_book = book;
    while (n-- > 0)
    {
        if (book.isbn() == cur_book.isbn())
            count++;
        else
        {
            std::cout << "Transaction count of " <<
                cur_book.isbn() << " is " <<
                count << std::endl;
            cur_book = book;
            count    = 1;
        }
        std::cin >> book;
    }

    std::cout << "Transaction count of " <<
        cur_book.isbn() << " is " <<
        count << std::endl;

    return 0;
}
