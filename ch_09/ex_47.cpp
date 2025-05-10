// -----------------------------------------------------------------------------
// File:        ex_47.cpp
// Author:      Erkam Uzuncayir
// Date:        09/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>

using std::cout;
using std::string;

void find_numeric(const string &str)
{
    string nums{"0123456789"}, found_ones;

    string::size_type pos = 0;
    while ((pos = str.find_first_of(nums, pos)) != string::npos)
    {
        found_ones.append(str, pos, 1);
        ++pos;
    }
    cout << found_ones;
}

void find_alphabetic(const string &str)
{
    string nums{"0123456789"}, found_ones;

    string::size_type pos = 0;
    while ((pos = str.find_first_not_of(nums, pos)) != string::npos)
    {
        found_ones.append(str, pos, 1);
        ++pos;
    }
    cout << found_ones;
}

int main(void)
{
    string str{"ab2c3d7R4E6"};

    find_numeric(str);
    cout << '\n';
    find_alphabetic(str);

    return 0;
}
