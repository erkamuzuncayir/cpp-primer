// -----------------------------------------------------------------------------
// File:        ex_49_StrVec.cpp
// Author:      Erkam Uzuncayir
// Date:        17/06/2025
// -----------------------------------------------------------------------------

#include "ex_49_StrVec.h"
#include <memory>
#include <string>

using std::string;

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(const size_t req_cap)
{
    if (req_cap <= capacity())
        return;

    auto data_start = alloc.allocate(req_cap);
    auto dest       = data_start;
    auto elem       = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();

    elements   = data_start;
    first_free = dest;
    cap        = elements + req_cap;
}

void StrVec::resize(size_t req_size)
{
    if (req_size < size())
    {
        while (first_free != elements + req_size)
            alloc.destroy(--first_free);
    }
    else if (req_size > size())
    {
        while (first_free != elements + req_size)
            alloc.construct(first_free++, " ");
    }
}

std::pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements; /* empty */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements     = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::StrVec(StrVec &&rhs) : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata     = alloc.allocate(newcapacity);
    auto dest        = newdata;
    auto elem        = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements   = newdata;
    first_free = dest;
    cap        = elements + newcapacity;
}
