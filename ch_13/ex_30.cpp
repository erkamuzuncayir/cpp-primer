// -----------------------------------------------------------------------------
// File:        ex_30.cpp
// Author:      Erkam Uzuncayir
// Date:        15/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>

class HasPtr
{
public:
    friend void swap(HasPtr &lhs, HasPtr &rhs);
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
    ~HasPtr() { delete ps; };

private:
    std::string *ps;
    int          i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "Swapping " << *lhs.ps << ", " << lhs.i << " with ";
    std::cout << *rhs.ps << ", " << rhs.i << std::endl;
}

int main()
{
    HasPtr first("first");
    HasPtr second("second");
    swap(first, second);
}