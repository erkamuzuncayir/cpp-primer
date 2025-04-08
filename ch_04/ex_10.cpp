//
// Created by erkam on 4/8/25.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    int stop = 42;
    while ((cin >> n) && n != stop)
        cout << n << endl;
}
