//
// Created by Erkam on 4/5/2025.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
    string   book_no;
    unsigned units_sold = 0;
    double   price      = 0.0;
    double   revenue    = 0.0;
};

int main()
{
    Sales_data firstBook;
    cin >> firstBook.book_no >> firstBook.units_sold >> firstBook.price;

    firstBook.revenue = firstBook.units_sold * firstBook.price;

    cout << firstBook.book_no << " revenue is " << firstBook.revenue << endl;
    return 0;
}
