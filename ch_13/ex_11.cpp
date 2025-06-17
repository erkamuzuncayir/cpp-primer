// -----------------------------------------------------------------------------
// File:        ex_11.cpp
// Author:      Erkam Uzuncayir
// Date:        13/06/2025
// -----------------------------------------------------------------------------

#include <string>
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    HasPtr& operator=(const HasPtr &rhs)
    {
        if (this != &rhs)
        {
            delete ps;
            ps = new std::string(*rhs.ps);
            i = rhs.i;
        }
    }
    ~HasPtr()
    {
        delete ps;
    }
private:
    std::string *ps;
    int          i;
};
