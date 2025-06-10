// -----------------------------------------------------------------------------
// File:        ex_17.cpp
// Author:      Erkam Uzuncayir
// Date:        30/05/2025
// -----------------------------------------------------------------------------

#include <iterator>
#include <set>
#include <string>
#include <vector>

using std::copy;

int main(void)
{
    std::multiset<std::string> c;
    std::vector<std::string> v;

    copy(v.begin(), v.end(), std::inserter(c, c.end()));  // legal
    copy(v.begin(), v.end(), std::back_inserter(c));      // illegal, push_back isn't supported in multiset.
    copy(c.begin(), c.end(), std::inserter(v, v.end()));  // legal
    copy(c.begin(), c.end(), std::back_inserter(v));      // legal
}
