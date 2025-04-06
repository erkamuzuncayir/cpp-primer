//
// Created by Erkam on 4/5/2025.
//

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int sum = 0;
    int n   = 50;

    while (n < 100)
        sum += n++;

    cout << sum << endl;
    return 0;
}
