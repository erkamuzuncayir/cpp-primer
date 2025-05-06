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
    Sales_data() : book_no(""), units_sold(0), revenue(0.0) {}
    Sales_data(const std::string &s) : book_no(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &is) { read(is, *this); }

    std::string isbn() const { return book_no; }
    Sales_data &combine(const Sales_data &rhs);

private:
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

int main()
{
    Sales_data total(cin);
    if (cin)
    {
        Sales_data temp(cin);
        while (cin)
        {
            if (total.isbn() == temp.isbn())
            {
                total.combine(temp);
            }
            else
            {
                print(cout, total) << endl;
                total = temp;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        std::cerr << "No date entered!" << std::endl;
        return -1;
    }
    return 0;
}
