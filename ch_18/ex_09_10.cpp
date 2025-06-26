/***************************************************************************
 *  @file       ex_09_10.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data    operator+(const Sales_data &lhs, const Sales_data &rhs);
    Sales_data          &operator+=(const Sales_data &rhs);

public:
    Sales_data() : Sales_data("", 0, 0.0) { std::cout << "1\n"; }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { std::cout << "2\n"; }
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is, *this);
        std::cout << "3\n";
    }
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n)
    {
        std::cout << "4\n";
    }

    double      avg_price() const;
    std::string isbn() const { return book_no; }
    Sales_data &combine(const Sales_data &rhs);

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

class out_of_stock : public std::runtime_error
{
public:
    explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
};
class isbn_mismatch : public std::logic_error
{
public:
    explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
    isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) :
        std::logic_error(s), left(lhs), right(rhs)
    {
    }
    const std::string left, right;
};

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
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

int main()
{
    // Valid: Same ISBNs
    Sales_data s1("978-0-201-88954-1", 5, 10.0);
    Sales_data s2("978-0-201-88954-1", 3, 12.0);

    // Invalid: Different ISBNs
    Sales_data s3("999-9-999-99999-9", 2, 25.0);

    try
    {
        Sales_data sum = s1 + s2;
        std::cout << "Addition successful: ";
        print(std::cout, sum) << '\n';
    }
    catch (const isbn_mismatch &e)
    {
        std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")\n";
    }

    try
    {
        Sales_data invalid_sum = s1 + s3;
        std::cout << "Addition successful: ";
        print(std::cout, invalid_sum) << '\n';
    }
    catch (const isbn_mismatch &e)
    {
        std::cerr << "ERROR: " << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")\n";
    }

    return 0;
}
