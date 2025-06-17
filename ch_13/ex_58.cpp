// -----------------------------------------------------------------------------
// File:        ex_58.cpp
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------


#include <algorithm>
#include <iostream>
#include <vector>
class Foo
{
public:
    Foo(std::initializer_list<int> il) : data(il) {};

    Foo sorted() &&;
    Foo sorted() const &;

private:
    std::vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    Foo ret(*this);
    return ret.sorted(); // Infinite recursion
}

int main()
{
    Foo f = {5, 1, 4, 3};

    std::cout << "Calling sorted() on lvalue:\n";
    Foo f2 = f.sorted();

    std::cout << "\nCalling sorted() on rvalue:\n";
    Foo f3 = Foo({9, 8, 7}).sorted();

    std::cout << "\nSorted results:\n";

    return 0;
}
