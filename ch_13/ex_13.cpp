// -----------------------------------------------------------------------------
// File:        ex_13.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X &operator=(const X &)
    {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() {std::cout << "~X()" << std::endl;}
};

void test(const X &x_1, X x_2)
{
    std::vector<X> v;
    v.push_back(X());
    v.push_back(X());
}

int main()
{
    X x1;
    X x2;
    x2 = x1;
    X *x_ptr_1 = new X;
    X *x_ptr_2 = new X();
    test(*x_ptr_1, *x_ptr_2);
    delete x_ptr_1;
    delete x_ptr_2;
}