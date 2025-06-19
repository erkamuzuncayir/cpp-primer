// -----------------------------------------------------------------------------
// File:        ex_30_32.cpp
// Author:      Erkam Uzuncayir
// Date:        18/06/2025
// -----------------------------------------------------------------------------

#include <memory>
#include <string>
#include <vector>

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

public:
    using size_type = vector<string>::size_type;
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

    std::string &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string *operator->() const { return &this->operator*(); }

    string     &deref() const;
    StrBlobPtr &incr();
    size_t      current_position() const { return curr; }

private:
    shared_ptr<vector<string>>    check(std::size_t, const string &) const;
    std::weak_ptr<vector<string>> wptr;
    std::size_t                   curr;
};

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    const std::string &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    const std::string *operator->() const { return &this->operator*(); }

    string          &deref() const;
    ConstStrBlobPtr &incr();
    size_t           current_position() const { return curr; }

private:
    shared_ptr<vector<string>>    check(std::size_t, const string &) const;
    std::weak_ptr<vector<string>> wptr;
    std::size_t                   curr;
};

class StrBlobPtrPtr
{
public:
    StrBlobPtrPtr() = default;
    explicit StrBlobPtrPtr(StrBlobPtr *p) : ptr(p) {}

    StrBlobPtr &operator*() const { return *ptr; }
    StrBlobPtr *operator->() const { return ptr; }

private:
    StrBlobPtr *ptr = nullptr;
};
