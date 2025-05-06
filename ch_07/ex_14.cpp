//
// Created by erkam on 4/18/25.
//

#include <iostream>
#include <string>

using std::string;

struct Sales_data;
std::istream &read(std::istream &is, Sales_data &item);

struct Sales_data
{
    Sales_data() : book_no(""), units_sold(0), revenue(0.0) {}
    Sales_data(const std::string &s) : book_no(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &is) { read(is, *this); }


    std::string isbn() const { return book_no; }
    Sales_data &combine(const Sales_data &rhs);

    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.book_no >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}
