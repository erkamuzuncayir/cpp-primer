//
// Created by erkam on 4/18/25.
//

#include <string>

struct Sales_data
{
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
