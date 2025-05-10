//
// Created by erkam on 08/05/25.
//

#include <list>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::list;
using std::string;

int main(void)
{
    list<string> inputs;
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
