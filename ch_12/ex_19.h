// -----------------------------------------------------------------------------
// File:        ex_19.h
// Author:      Erkam Uzuncayir
// Date:        12/06/2025
// -----------------------------------------------------------------------------

#ifndef EX_19_H
#define EX_19_H

#include <memory>
#include <string>
#include <vector>

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }
    bool      empty() const { return data->empty(); }

    void    push_back(const string &t) { data->push_back(t); }
    void    pop_back();
    string &front();
    string &back();

private:
    shared_ptr<vector<string>> data;
    void                       check(size_type i, const string &msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string     &deref() const;
    StrBlobPtr &incr();
    size_t current_position() const { return curr;}
private:
    shared_ptr<vector<string>>    check(std::size_t, const string &) const;
    std::weak_ptr<vector<string>> wptr;
    std::size_t                   curr;
};

#endif // EX_19_H
