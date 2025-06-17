// -----------------------------------------------------------------------------
// File:        ex_39_40.h
// Author:      Erkam Uzuncayir
// Date:        16/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_39_40_H
#define EX_39_40_H
#include <initializer_list>
#include <string>

using std::string;

class StrVec
{
public:
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr)
    {
    }
    StrVec(std::initializer_list<string> il)
    {
        for (auto it = il.begin(); it != il.end(); ++it)
            push_back(*it);
    }
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
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
#endif // EX_39_40_H
