//
// Created by erkam on 4/8/25.
//

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int  x[10];
    int* p = x;
    cout << sizeof(x) / sizeof(*x) << endl; // It is return element count of x.
    cout << sizeof(p) / sizeof(*p) << endl; // It is return size of a pointer divided by int
}
