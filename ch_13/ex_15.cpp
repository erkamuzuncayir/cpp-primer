// -----------------------------------------------------------------------------
// File:        ex_15.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

// It'll change because this time it won't pass same serial number. All of them will be different.

class numbered
{
public:
    numbered(){mysn = unique;++unique;};
    numbered(const numbered& n){mysn = unique;++unique;};
    int mysn;
    static int unique;
};
int numbered::unique = 282;
void f (numbered s)
{ std::cout << s.mysn << std::endl;};

int main()
{
    numbered a, b = a, c=b;
    f(a); f(b); f(c);
}