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
    Sales_data first_book;
    std::cin >> first_book.book_no >> first_book.units_sold >> first_book.price;
    Sales_data second_book;
    std::cin >> second_book.book_no >> second_book.units_sold >> second_book.price;

    if (first_book.book_no == second_book.book_no)
    {
        Sales_data totalOfBook;
        totalOfBook.book_no    = first_book.book_no;
        totalOfBook.units_sold = first_book.units_sold + second_book.units_sold;
        totalOfBook.price      = first_book.price;
        totalOfBook.revenue    = totalOfBook.units_sold * totalOfBook.price;
        std::cout << totalOfBook.book_no << " revenue is " << totalOfBook.revenue << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same book no." << std::endl;

        return -1;
    }
}