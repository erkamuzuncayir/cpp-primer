// -----------------------------------------------------------------------------
// File:        ex_44.cpp
// Author:      Erkam Uzuncayir
// Date:        09/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>

using std::cout;
using std::string;

void replace(string &s, string oldVal, string newVal)
{
    for (auto it = s.begin(); it <= (s.end() - oldVal.size());)
    {
        if (oldVal == string{it, it + oldVal.size()})
            s.replace(it - s.begin(), oldVal.size(), newVal);
        else
            ++it;
    }
    cout << s;
}

int main(void)
{
    string str{"thougthohtho"};
    replace(str, "tho", "thru");
    return 0;
}
