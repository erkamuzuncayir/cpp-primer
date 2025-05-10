//
// Created by erkam on 08/05/25.
//

#include <forward_list>
#include <iostream>
#include <vector>

using std::cout;
using std::forward_list;
using std::vector;

int main(void)
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto              prev = flst.before_begin();
    auto              curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    cout << "Forward list: ";
    for (auto e : flst)
        cout << e << ' ';

    return 0;
}
