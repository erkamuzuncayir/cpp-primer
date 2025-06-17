// -----------------------------------------------------------------------------
// File:        ex_53.cpp
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
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
    HasPtr(HasPtr &&rhs) noexcept : ps(rhs.ps), i(rhs.i)
    {
        rhs.ps = nullptr;
        rhs.i  = 0;
    }

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

    HasPtr &operator=(HasPtr &&rhs) noexcept
    {
        if (this != &rhs)
        {
            delete ps;
            ps     = rhs.ps;
            i      = rhs.i;
            rhs.ps = nullptr;
            rhs.i  = 0;
        }

        return *this;
    }

    bool operator<(const HasPtr &other) const { return *ps < *other.ps; }

    void print() const { std::cout << *ps << std::endl; }
    ~HasPtr() { delete ps; };

private:
    std::string *ps;
    int          i;
};
