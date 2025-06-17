// -----------------------------------------------------------------------------
// File:        ex_44.h
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_44_H
#define EX_44_H

#include <memory>

class MyString
{
public:
    MyString() : first_ch(nullptr), last_ch(nullptr) {}
    MyString(const char *s);
    ~MyString();
    size_t size() const { return last_ch - first_ch; }
    void   print();

private:
    std::allocator<char> alloc;
    void                 free();
    void                 allocate(size_t);
    char                *first_ch;
    char                *last_ch;
};
#endif // EX_44_H
