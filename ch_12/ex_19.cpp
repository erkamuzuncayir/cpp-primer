// -----------------------------------------------------------------------------
// File:        ex_19.cpp
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------


#include "ex_19.h"
#include <stdexcept>

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr{*this}; }

StrBlobPtr StrBlob::end() { return StrBlobPtr{*this, this->size()}; }

// StrBlobPtr //

shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i, const string &msg) const
{
    auto ret = wptr.lock();

    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
