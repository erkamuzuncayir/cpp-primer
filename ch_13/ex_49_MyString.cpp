// -----------------------------------------------------------------------------
// File:        ex_49_MyString.cpp
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------


#include "ex_49_MyString.h"

#include <iostream>
#include <vector>

void MyString::free()
{
    if (first_ch)
    {
        for (auto p = last_ch; p != first_ch; /* empty */)
            alloc.destroy(--p);
        alloc.deallocate(first_ch, last_ch - first_ch);
    }
}
void MyString::allocate(size_t size)
{
    first_ch = alloc.allocate(size);
    last_ch  = first_ch;
}

MyString::MyString(const char *s) : first_ch(nullptr), last_ch(nullptr)
{
    size_t size = strlen(s);
    allocate(size + 1);
    int offset = 0;
    for (; offset < size; ++offset)
        alloc.construct(first_ch + offset, *s++);

    alloc.construct(first_ch + offset, '\0');
    last_ch = first_ch + offset + 1;
}

MyString::MyString(const MyString &s) : first_ch(nullptr), last_ch(nullptr)
{
    std::cout << "Copy constructor called\n";

    size_t size = s.size();
    allocate(size + 1);
    int offset = s.last_ch - s.first_ch;
    std::move(s.first_ch, s.last_ch, first_ch);
    last_ch = first_ch + offset + 1;
}

MyString::MyString(MyString &&rhs) noexcept : first_ch(rhs.first_ch), last_ch(rhs.last_ch)
{
    rhs.first_ch = rhs.last_ch = nullptr;
}

MyString &MyString::operator=(const MyString &s)
{
    std::cout << "Copy assignment operator called\n";

    if (this == &s)
        return *this;

    free();

    size_t size = s.size();
    allocate(size + 1);
    int offset = s.last_ch - s.first_ch;
    std::move(s.first_ch, s.last_ch, first_ch);
    last_ch = first_ch + offset + 1;
    return *this;
}

MyString::~MyString() { free(); }

void MyString::print()
{
    {
        if (first_ch)
            std::cout << first_ch << std::endl;
        else
            std::cout << "(empty)" << std::endl;
    }
}