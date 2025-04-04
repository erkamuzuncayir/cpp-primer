//
// Created by Erkam on 4/4/2025.
//

#include <iostream>
#include "ex_42.h"

int main()
{
    Sales_data total;
    double     price;

    if (std::cin >> total.book_no >> total.units_sold >> price)
    {
        Sales_data temp; // variable to hold the running sum

        while (std::cin >> temp.book_no >> temp.units_sold)
        {
            if (total.book_no == temp.book_no)
                total.units_sold += temp.units_sold;
            else
            {
                total.revenue = total.units_sold * price;
                std::cout << total.book_no << " revenue is " << total.revenue << std::endl;
                total = temp;
            }
        }

        std::cout << total.book_no << " revenue is " << total.revenue << std::endl;
    }
    else
    {
        std::cerr << "No data!" << std::endl;

        return -1;
    }

    return 0;

}
