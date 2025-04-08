//
// Created by erkam on 4/8/25.
//

#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;

int main()
{
    short s = SHRT_MAX;
    int n = INT_MAX;
    unsigned u = UINT_MAX;

    cout << "Max short value: " << s << "If we increment by 1: " << (s + 1) << endl;
    cout << "Max integer value: " << n << "If we increment by 1: " << (n + 1) << endl;
    cout << "Max unsigned value: " << u << "If we increment by 1: " << (u + 1) << endl;
}
