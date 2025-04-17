//
// Created by erkam on 4/17/25.
//

#include <iostream>
using std::cout;

void f()
{
    cout << "f()" << '\n';
}

void f(int)
{
    cout << "f(int)" << '\n';
}

void f(int, int)
{
    cout << "f(int, int)" << '\n';
}

void f(double, double = 3.14)
{
    cout << "f(double, double)" << '\n';
}

int main()
{
    f(2.56, 42); // Ambiguous function call.
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}
