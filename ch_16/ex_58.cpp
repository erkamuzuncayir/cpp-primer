// -----------------------------------------------------------------------------
// File:        ex_58.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <initializer_list>
#include <string>

using std::string;

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<string> il)
    {
        for (auto it = il.begin(); it != il.end(); ++it)
            push_back(*it);
    }
    StrVec(const StrVec &);

    std::string       operator[](size_t i) { return elements[i]; }
    const std::string operator[](size_t i) const { return elements[i]; }
    StrVec           &operator=(const StrVec &);
    StrVec           &operator=(std::initializer_list<string> il);
    template <class... Args>
    void emplace_back(Args &&...args);
    StrVec(StrVec &&);
    ~StrVec();
    void    push_back(const string &);
    void    reserve(size_t);
    void    resize(size_t);
    size_t  size() const { return first_free - elements; }
    size_t  capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }

private:
    std::allocator<string> alloc;
    void                   chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<string *, string *> alloc_n_copy(const string *, const string *);
    void                          free();
    void                          reallocate();
    string                       *elements;
    string                       *first_free;
    string                       *cap;
};

StrVec &StrVec::operator=(std::initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) { return !(lhs == rhs); }

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    size_t min_len = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
    for (size_t i = 0; i < min_len; i++)
    {
        if (lhs.begin()[i] != rhs.begin()[i])
            return lhs.begin()[i] < rhs.begin()[i];
    }

    return lhs.size() < rhs.size();
}

bool operator>(const StrVec &lhs, const StrVec &rhs) { return rhs < lhs; }

template <class... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}