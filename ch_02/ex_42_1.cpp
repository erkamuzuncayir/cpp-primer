//
// Created by Erkam on 4/4/2025.
//

#include <iostream>
#include "ex_42.h"

int main()
{
    Sales_data first_book;
    double     price;
    std::cin >> first_book.book_no >> first_book.units_sold >> price;
    first_book.revenue = first_book.units_sold * price;
    std::cout << first_book.book_no << " revenue is " << first_book.revenue << std::endl;

    return 0;
}
