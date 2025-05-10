// -----------------------------------------------------------------------------
// File:        ex_45.cpp
// Author:      Erkam Uzuncayir
// Date:        09/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>

using std::cout;
using std::string;

string add_prefix_suffix(const string &name, const string &pfx, const string &sfx)
{
    string full_name(pfx);
    full_name.append(" ");
    full_name.append(name);
    full_name.append(" ");
    full_name.append(sfx);
    return full_name;
}

int main(void)
{
    string name{"Erkam"};

    string full_name = add_prefix_suffix(name, "Mr.", "III");
    cout << full_name;

    return 0;
}
