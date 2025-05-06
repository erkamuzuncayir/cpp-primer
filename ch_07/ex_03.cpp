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
    std::string isbn() const { return book_no; }
    Sales_data& combine(const Sales_data& rhs);

    std::string book_no;
    unsigned    units_sold = 0;
    double      revenue    = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    Sales_data total;
    if (cin >> total.book_no >> total.units_sold >> total.revenue)
    {
        Sales_data temp;
        while (cin >> temp.book_no >> temp.units_sold >> temp.revenue)
        {
            if (total.isbn() == temp.isbn())
            {
                total.combine(temp);
            }
            else
            {
                cout << total.book_no << " " << total.units_sold << " " << total.revenue << endl;
                total = temp;
            }
        }
        cout << total.isbn() << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        std::cerr << "No date entered!" << std::endl;
        return -1;
    }
    return 0;
}
