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
    int         ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> iv;
    list<int>   il;

    for (auto e : ia)
    {
        iv.push_back(e);
        il.push_back(e);
    }

    int i = 0;
    while (i < iv.size())
    {
        if (iv[i] % 2 == 0)
            iv.erase(iv.begin() + i);
        else
            ++i;
    }

    for (auto it = il.begin(); it != il.end();)
        *it % 2 != 0 ? it = il.erase(it) : ++it;

    cout << "Vector: ";
    for (auto e : iv)
        cout << e << ' ';

    cout << "\nList: ";
    for (auto e : il)
        cout << e << ' ';

    return 0;
}
