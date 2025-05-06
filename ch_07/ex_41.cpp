//
// Created by erkam on 05/05/25.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);

public:
    Sales_data() : Sales_data("", 0, 0.0)
    {
        std::cout << "1\n";
    }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0)
    {
        std::cout << "2\n";
    }
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is, *this);
        std::cout << "3\n";
    }
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n)
    {
        std::cout << "4\n";
    }

    double avg_price() const;
    std::string isbn() const { return book_no; }
    Sales_data &combine(const Sales_data &rhs);

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

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

int main(void)
{
    Sales_data first;
    Sales_data second("second");
    Sales_data third(std::cin);
    Sales_data fourth("fourth", 1, 2.4);
}
