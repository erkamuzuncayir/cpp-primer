// -----------------------------------------------------------------------------
// File:        ex_Sales_data_02_06_09_10_11_13_20_22_45.cpp
// Author:      Erkam Uzuncayir
// Date:        18/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <utility>

class Sales_data
{
    friend std::istream &operator>>(std::istream &is, Sales_data &s);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend Sales_data    operator+(const Sales_data &, const Sales_data &);
    friend Sales_data    operator-(const Sales_data &, const Sales_data &);

public:
    Sales_data() = default;
    Sales_data(std::string s, unsigned n, double p) : book_no(std::move(s)), units_sold(n), revenue(p * n) {}

    explicit    operator std::string() const { return book_no; }
    explicit    operator double() const { return revenue; }
    Sales_data &operator=(const std::string &new_isbn);
    Sales_data &operator+=(const Sales_data &rhs);
    Sales_data &operator-=(const Sales_data &rhs);

    std::string isbn() const { return book_no; }

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data result = lhs;
    result -= rhs;
    return result;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data &Sales_data::operator=(const std::string &new_isbn)
{
    book_no = new_isbn;
    return *this;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

// Prints
// 0-201-99999-9 10 249.5
// 10 24 22.8
std::istream &operator>>(std::istream &is, Sales_data &s)
{
    double price;
    is >> s.book_no >> s.units_sold >> price;
    if (is)
        s.revenue = s.units_sold * price;
    else
        s = Sales_data();
    return is;
}

// Nothing happened, works.
// istream& operator>>(istream& in, Sales_data& s)
// {
//     {
//         double price;
//         in >> s.bookNo >> s.units_sold >> price;
//         s.revenue = s.units_sold * price;
//         return in;
//     }
// }

std::ostream &operator<<(std::ostream &os, const Sales_data &s)
{
    os << s.book_no << " " << s.units_sold << " " << s.revenue;
    return os;
}

int main()
{
    Sales_data book_1, book_2;

    std::cout << "Enter book1: (ISBN units_sold price): ";
    std::cin >> book_1;

    std::cout << "Enter book2: (same ISBN recommended): ";
    std::cin >> book_2;

    Sales_data total = book_1 + book_2;

    std::cout << "\nCombined Sales Data:\n";
    std::cout << total << std::endl;
}
