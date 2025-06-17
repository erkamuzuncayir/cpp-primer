// -----------------------------------------------------------------------------
// File:        ex_44.cpp
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------


#include "ex_44.h"

#include <iostream>

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

int main()
{
    MyString my_string_1, my_string_2("test");
    my_string_1.print();
    my_string_2.print();
}
