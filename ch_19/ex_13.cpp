/***************************************************************************
 *  @file       ex_13.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-27
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>
#include <string>

class Sales_data
{
public:
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n) {}

    std::string isbn() const { return book_no; }

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;

    // Grant access to private members for test
    friend int main();
};

int main()
{
    Sales_data data("123-456", 5, 20.0);

    std::string Sales_data::*pBookNo = &Sales_data::book_no;

    // Access through object
    std::cout << "Book no (object): " << data.*pBookNo << "\n";

    // Access through pointer to object
    Sales_data *ptr = &data;
    std::cout << "Book no (pointer): " << ptr->*pBookNo << "\n";
}
