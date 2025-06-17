// -----------------------------------------------------------------------------
// File:        ex_14.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include <iostream>

// They all will share same `mysn` data because it just copies reference between instances.

class numbered
{
public:
    numbered(){mysn = unique;++unique;};
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