// -----------------------------------------------------------------------------
// File:        ex_47.h
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_47_H
#define EX_47_H

#include <memory>

class MyString
{
public:
    MyString() : first_ch(nullptr), last_ch(nullptr) {}
    MyString(const char *s);
    MyString(const MyString &s);
    MyString &operator=(const MyString &s);
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
#endif // EX_47_H
