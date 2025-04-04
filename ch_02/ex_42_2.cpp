//
// Created by Erkam on 4/4/2025.
//

#include <iostream>
#include "ex_42.h"

int main()
{
    double     price, total_price = 0.0f;
    Sales_data first_book;
    std::cin >> first_book.book_no >> first_book.units_sold >> price;
    Sales_data second_book;
    std::cin >> second_book.book_no >> second_book.units_sold >> price;

    if (first_book.book_no == second_book.book_no)
    {
        Sales_data total_book;
        total_book.book_no    = first_book.book_no;
        total_book.units_sold = first_book.units_sold + second_book.units_sold;
        total_price += price;
        total_book.revenue = total_book.units_sold * price;
        std::cout << total_book.book_no << " revenue is " << total_book.revenue << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same book no." << std::endl;

        return -1;
    }
}
