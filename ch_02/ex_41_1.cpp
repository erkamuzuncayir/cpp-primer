//
// Created by Erkam on 4/4/2025.
//

#include <iostream>

struct Sales_data
{
    std::string book_no;
    unsigned    units_sold = 0;
    double      price      = 0.0;
    double      revenue    = 0.0;
};

int main()
{
    Sales_data firstBook;
    std::cin >> firstBook.book_no >> firstBook.units_sold >> firstBook.price;

    firstBook.revenue = firstBook.units_sold * firstBook.price;

    std::cout << firstBook.book_no << " revenue is " << firstBook.revenue << std::endl;
    return 0;
}
