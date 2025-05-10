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
    list<int>   il{4, 5, 6};
    vector<int> iv(il.begin(), il.end());

    for (auto e : iv)
        cout << e << ' ';

    return 0;
}
