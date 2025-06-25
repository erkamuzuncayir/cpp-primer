// -----------------------------------------------------------------------------
// File:        ex_12_24_29.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include "ex_28.cpp"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <vector>

template <typename T>
class Blob
{
public:
    typedef T                                  value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);
    Blob(std::iterator<T> beg, std::iterator<T> end);
    size_type size() const { return data->size(); }
    bool      empty() const { return data->empty(); }
    void      push_back(const T &t) { data->push_back(t); }
    void      push_back(T &&t) { data->push_back(std::move(t)); }
    void      pop_back();

    T &back();
    T &operator[](size_type i);

    const T &back() const;
    const T &operator[](size_type i) const;

private:
    my_shared_ptr<std::vector<T>> data;
    void                            check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>())
{
}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il))
{
}
template <typename T>
Blob<T>::Blob(std::iterator<T> beg, std::iterator<T> end) : data(std::make_shared<std::vector<T>>(beg, end))
{
}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T &Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T &Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

// -------------------------------- BlobPtr -------------------------------- //

template <typename T>
class BlobPtr
{
    friend bool operator== <T>(const BlobPtr &lhs, const BlobPtr &rhs);
    friend bool operator< <T>(const BlobPtr &lhs, const BlobPtr &rhs);

public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    bool     operator==(const BlobPtr &lhs, const BlobPtr &rhs);
    BlobPtr &operator++();
    BlobPtr &operator--();

private:
    my_shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>>   wptr;
    std::size_t                     curr;
};

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "increment");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    check(curr, "decrement");
    --curr;
    return *this;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}
