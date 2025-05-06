//
// Created by erkam on 4/18/25.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const std::string &s) : book_no(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &);

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

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

int main()
{
    Sales_data s_1;
    Sales_data s_2("11");
    Sales_data s_3("22", 4, 5.3);
    Sales_data s_4(cin);

    print(cout, s_1) << endl;
    print(cout, s_2) << endl;
    print(cout, s_3) << endl;
    print(cout, s_4) << endl;
}
