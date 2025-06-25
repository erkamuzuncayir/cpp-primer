// -----------------------------------------------------------------------------
// File:        ex_02_03.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
class Sales_data
{
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

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    if (lhs < rhs)
        return -1;
    if (rhs < lhs)
        return 1;
    return 0;
}

int main()
{
    Sales_data s_1, s_2;
    // error C2676: binary '<': 'const T' does not define this operator or
    // a conversion to a type acceptable to the predefined operator
    std::cout << compare(s_1, s_2) << std::endl;
}
