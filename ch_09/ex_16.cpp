//
// Created by erkam on 08/05/25.
//

#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::vector;

int main(void)
{
    vector<int> iv{1, 2, 3};
    list<int>   il{1, 2, 1};

    int  i = 0;
    auto e = il.cbegin();
    for (; e != il.cend() && i < iv.size(); ++e, ++i)
    {
        if (*e < iv[i])
        {
            cout << "List is smaller\n";
            return 0;
        }
        else if (*e > iv[i])
        {
            cout << "Vector is smaller\n";
            return 0;
        }
    }

    if (i == iv.size())
    {
        if (e == il.cend())
            cout << "They're equal\n";
        else
            cout << "Vector is smaller\n";
    }
    else
        cout << "List is smaller\n";

    return 0;
}
