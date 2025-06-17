// -----------------------------------------------------------------------------
// File:        ex_50.cpp
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------


#include "ex_50.h"

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
    std::cout << "Move constructor called\n";

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

int main()
{
    MyString my_string_1("hello");      // normal constructor
    MyString my_string_2 = my_string_1; // copy constructor

    MyString my_string_3;
    my_string_3 = std::move(my_string_1); // copy assignment

    my_string_1.print();
    my_string_2.print();
    my_string_3.print();

    std::cout << "ex_48\n";

    std::vector<MyString> vec;
    vec.reserve(10);

    vec.push_back(std::move(MyString("one")));
    vec.push_back(MyString("two"));
    vec.push_back(std::move(MyString("one")));
    vec.push_back(MyString("four"));
}
