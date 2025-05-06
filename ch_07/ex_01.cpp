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
    string   book_no;
    unsigned units_sold = 0;
    double   revenue    = 0.0;
};

int main()
{
    Sales_data total;
    if (cin >> total.book_no >> total.units_sold >> total.revenue)
    {
        Sales_data temp;
        while (cin >> temp.book_no >> temp.units_sold >> temp.revenue)
        {
            if (total.book_no == temp.book_no)
            {
                total.units_sold += temp.units_sold;
                total.revenue += temp.revenue;
            }
            else
            {
                cout << total.book_no << " " << total.units_sold << " " << total.revenue << endl;
                total = temp;
            }
        }
        cout << total.book_no << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        std::cerr << "No date entered!" << std::endl;
        return -1;
    }
    return 0;
}
