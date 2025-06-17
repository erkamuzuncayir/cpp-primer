// -----------------------------------------------------------------------------
// File:        ex_16.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

// All of them will be different because, because all of them will be copied when instantiated.

class numbered
{
public:
    numbered(){mysn = unique;++unique;};
    numbered(const numbered& n){mysn = unique;++unique;};
    int mysn;
    static int unique;
};
int numbered::unique = 282;
void f (const numbered &s)
{ std::cout << s.mysn << std::endl;};

int main()
{
    numbered a, b = a, c=b;
    f(a); f(b); f(c);
}