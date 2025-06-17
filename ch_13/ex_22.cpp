// -----------------------------------------------------------------------------
// File:        ex_22.cpp
// Author:      Erkam Uzuncayir
// Date:        15/06/2025
// -----------------------------------------------------------------------------

#include <string>
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
    ~HasPtr() { delete ps; };

private:
    std::string *ps;
    int          i;
};
