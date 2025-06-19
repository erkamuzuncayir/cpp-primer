// -----------------------------------------------------------------------------
// File:        ex_MyString_16_18.cpp
// Author:      Erkam Uzuncayir
// Date:        18/06/2025
// -----------------------------------------------------------------------------

#include <memory>

class MyString
{
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend bool operator<(const MyString &lhs, const MyString &rhs);

public:
    MyString() : first_ch(nullptr), last_ch(nullptr) {}
    MyString(const char *s);
    MyString(const MyString &s);
    MyString(MyString &&rhs) noexcept;
    char       operator[](size_t i) { return first_ch[i]; }
    const char operator[](size_t i) const { return first_ch[i]; }
    MyString  &operator=(const MyString &s);
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

bool operator==(const MyString &lhs, const MyString &rhs)
{
    return lhs.size() == rhs.size() && std::equal(lhs.first_ch, lhs.last_ch, rhs.first_ch);
}

bool operator!=(const MyString &lhs, const MyString &rhs) { return !(lhs == rhs); }

bool operator<(const MyString &lhs, const MyString &rhs)
{
    size_t min_len = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
    for (size_t i = 0; i < min_len; i++)
    {
        if (lhs.first_ch[i] != rhs.first_ch[i])
            return lhs.first_ch[i] < rhs.first_ch[i];
    }

    return lhs.size() < rhs.size();
}

bool operator>(const MyString &lhs, const MyString &rhs) { return rhs < lhs; }
