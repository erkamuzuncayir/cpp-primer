
//
// Created by erkam on 07/05/25.
//

#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
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

    double      avg_price() const;
    std::string isbn() const { return book_no; }
    Sales_data &combine(const Sales_data &rhs);

private:
    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

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

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    ofstream out;
    out.open(argv[2], ofstream::app);

    Sales_data total(in);
    if (read(in, total))
    {
        Sales_data temp(in);
        while (read(in, total))
        {
            if (total.isbn() == temp.isbn())
            {
                total.combine(temp);
            }
            else
            {
                print(out, total) << endl;
                total = temp;
            }
        }
        print(out, total) << endl;
    }
    else
    {
        std::cerr << "No data entered!" << std::endl;
        return -1;
    }

    return 0;
}
