//
// Created by erkam on 08/05/25.
//

#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;

int main(void)
{
    deque<string> inputs;
    string        temp;

    while (cin >> temp)
        inputs.push_front(temp);

    auto it = inputs.cbegin();
    while (it != inputs.cend())
    {
        cout << *it << ' ';
        ++it;
    }

    return 0;
}
