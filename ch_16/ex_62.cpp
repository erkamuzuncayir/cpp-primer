// -----------------------------------------------------------------------------
// File:        ex_62.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

class Sales_data
{
    friend class std::hash<Sales_data>;
    friend     bool operator==(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
public:
    Sales_data() : book_no(""), units_sold(0), revenue(0.0) {}
    Sales_data(const std::string &s) : book_no(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &is) { read(is, *this); }

    double      avg_price() const;
    std::string isbn() const { return book_no; }
    Sales_data &combine(const Sales_data &rhs);

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.book_no == rhs.book_no &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

inline double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

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

namespace std {
    template <>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data& s) const noexcept;
    };
    size_t
    hash<Sales_data>::operator()(const Sales_data& s) const noexcept
    {
        return hash<string>()(s.book_no) ^
        hash<unsigned>()(s.units_sold) ^
        hash<double>()(s.revenue);
    }
}

int main()
{
    std::unordered_multiset<Sales_data> transactions = {
        Sales_data("ISBN123", 3, 20.0),
        Sales_data("ISBN456", 2, 15.0),
        Sales_data("ISBN123", 1, 20.0),
        Sales_data("ISBN789", 5, 10.0),
        Sales_data("ISBN456", 2, 15.0)
    };

    for (const auto &item : transactions)
    {
        print(std::cout, item) << std::endl;
    }

    return 0;
}