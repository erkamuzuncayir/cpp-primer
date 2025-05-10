// -----------------------------------------------------------------------------
// File:        ex_50.cpp
// Author:      Erkam Uzuncayir
// Date:        10/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main(void)
{
    vector<string> nums{"3.14", "3"};
    int            sum_int = 0;
    double         sum_floating = 0.0;

    auto it = nums.cbegin();
    while (it != nums.cend())
    {
        sum_int += stoi(*it);
        sum_floating += stod(*it);
        ++it;
    }

    cout << sum_int << ' ' << sum_floating;
}
