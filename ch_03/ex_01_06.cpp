//
// Created by Erkam on 4/5/2025.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;

struct Sales_data
{
    string   book_no;
    unsigned units_sold = 0;
    double   price      = 0.0;
    double   revenue    = 0.0;
};

int main()
{
    Sales_data total;

    if (cin >> total.book_no >> total.units_sold >> total.price)
    {
        Sales_data temp; // variable to hold the running sum

        while (cin >> temp.book_no >> temp.units_sold)
        {
            if (total.book_no == temp.book_no)
                total.units_sold += temp.units_sold;
            else
            {
                total.revenue = total.units_sold * total.price;
                cout << total.book_no << " revenue is " << total.revenue << endl;
                total = temp;
            }
        }

        cout << total.book_no << " revenue is " << total.revenue << endl;
    }
    else
    {
        cerr << "No data!" << endl;

        return -1;
    }

    return 0;

}
