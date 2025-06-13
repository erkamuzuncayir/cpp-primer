// -----------------------------------------------------------------------------
// File:        ex_22.cpp
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------

#include "ex_22.h"
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

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr{*this}; }

ConstStrBlobPtr StrBlob::end() const { return ConstStrBlobPtr{*this, this->size()}; }

// ConstStrBlobPtr //

shared_ptr<vector<string>> ConstStrBlobPtr::check(std::size_t i, const string &msg) const
{
    auto ret = wptr.lock();

    if (!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

string &ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}
