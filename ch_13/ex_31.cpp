// -----------------------------------------------------------------------------
// File:        ex_30.cpp
// Author:      Erkam Uzuncayir
// Date:        15/06/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    HasPtr &operator=(const HasPtr &rhs)
    {
        if (this == &rhs)
            return *this;
        const auto temp_ps = new std::string(*rhs.ps);
        delete ps;
        ps = temp_ps;
        i  = rhs.i;
        return *this;
    }
    bool operator<(const HasPtr &other) const { return *ps < *other.ps; }

    void print() const { std::cout << *ps << std::endl; }
    ~HasPtr() { delete ps; };

private:
    std::string *ps;
    int          i;
};

int main()
{
    std::vector<HasPtr> vec({HasPtr("3"), HasPtr("2"), HasPtr("1")});

    for (const auto &i : vec)
        i.print();

    std::sort(vec.begin(), vec.end());

    for (const auto &i : vec)
        i.print();

    return 0;
}
