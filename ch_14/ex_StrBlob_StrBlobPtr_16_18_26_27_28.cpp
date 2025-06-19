// -----------------------------------------------------------------------------
// File:        ex_StrBlob_StrBlobPtr_16_18_26_27_28.cpp
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
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);


public:
    using size_type = vector<string>::size_type;
    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    std::string       operator[](size_type i) { return *(data->begin() + i); }
    const std::string operator[](size_type i) const { return *(data->begin() + i); }

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

bool operator==(const StrBlob &lhs, const StrBlob &rhs) { return *lhs.data == *rhs.data; }

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) { return !(lhs == rhs); }

bool operator<(const StrBlob &lhs, const StrBlob &rhs) { return *lhs.data < *rhs.data; }

bool operator>(const StrBlob &lhs, const StrBlob &rhs) { return rhs < lhs; }

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    std::string       &operator[](std::size_t i) { return (*wptr.lock())[i]; }
    const std::string &operator[](std::size_t i) const { return (*wptr.lock())[i]; }

    StrBlobPtr operator+(size_t n);
    StrBlobPtr &operator+=(size_t n);
    StrBlobPtr operator-(size_t n);
    StrBlobPtr &operator-=(size_t n);

    StrBlobPtr &operator++()
    {
        check(curr, "Increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    StrBlobPtr operator++(int)
    {
        StrBlobPtr tmp = *this;
        ++*this;
        return tmp;
    }

    StrBlobPtr &operator--()
    {
        check(curr, "Decrement past end of StrBlobPtr");
        --curr;
        return *this;
    }

    StrBlobPtr operator--(int)
    {
        StrBlobPtr tmp = *this;
        --*this;
        return tmp;
    }

    string     &deref() const;
    StrBlobPtr &incr();
    size_t      current_position() const { return curr; }

private:
    shared_ptr<vector<string>>    check(std::size_t, const string &) const;
    std::weak_ptr<vector<string>> wptr;
    std::size_t                   curr;
};

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return lhs.curr == rhs.curr; }

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return !(lhs == rhs); }

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return lhs.curr < rhs.curr; }

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return rhs < lhs; }

StrBlobPtr StrBlobPtr::operator+(size_t n)
{
    StrBlobPtr sum(*this);
    sum += n;
    return sum;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    return *this;
}

StrBlobPtr StrBlobPtr::operator-(size_t n)
{
    StrBlobPtr diff(*this);
    diff -= n;
    return diff;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    return *this;
}
