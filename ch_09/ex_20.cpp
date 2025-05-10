//
// Created by erkam on 08/05/25.
//

#include <deque>
#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::deque;
using std::list;

int main(void)
{
    list<int>  i_l{1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> i_d_e;
    deque<int> i_d_o;

    auto it = i_l.cbegin();
    while (it != i_l.cend())
    {
        *it % 2 == 0 ? i_d_e.push_back(*it) : i_d_o.push_back(*it);
        it++;
    }

    cout << "Odds: ";
    for (auto o : i_d_o)
        cout << o << ' ';
    cout << '\n';

    cout << "Evens: ";
    for (auto e : i_d_e)
        cout << e << ' ';
    cout << '\n';

    return 0;
}
