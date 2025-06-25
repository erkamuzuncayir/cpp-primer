// -----------------------------------------------------------------------------
// File:        ex_16.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <initializer_list>
#include <iostream>

#include <memory>

template <typename T>
class Vec
{
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(std::initializer_list<T> il) : Vec()
    {
        reserve(il.size());
        for (auto it = il.begin(); it != il.end(); ++it)
            push_back(*it);
    }
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    Vec(Vec &&) noexcept;
    ~Vec();
    void   push_back(const T &);
    void   reserve(size_t);
    void   resize(size_t);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T     *begin() const { return elements; }
    T     *end() const { return first_free; }

private:
    std::allocator<T> alloc;
    void              chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void                free();
    void                reallocate();
    T                  *elements;
    T                  *first_free;
    T                  *cap;
};

template <typename T>
void Vec<T>::push_back(const T &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::reserve(const size_t req_cap)
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

template <typename T>
void Vec<T>::resize(size_t req_size)
{
    if (req_size < size())
    {
        while (first_free != elements + req_size)
            alloc.destroy(--first_free);
    }
    else if (req_size > size())
    {
        reserve(req_size);
        while (first_free != elements + req_size)
            alloc.construct(first_free++, T());
    }
}

template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements; /* empty */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements     = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
Vec<T>::Vec(Vec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

template <typename T>
void Vec<T>::reallocate()
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

int main()
{
    std::cout << ">>> Constructor with initializer_list:\n";
    Vec<std::string> v1{"hello", "world", "erkam"};
    for (auto &s : v1)
        std::cout << s << ' ';
    std::cout << "\nSize: " << v1.size() << ", Capacity: " << v1.capacity() << "\n\n";

    std::cout << ">>> Testing push_back:\n";
    v1.push_back("kool");
    for (auto &s : v1)
        std::cout << s << ' ';
    std::cout << "\nSize: " << v1.size() << ", Capacity: " << v1.capacity() << "\n\n";

    std::cout << ">>> Copy constructor:\n";
    Vec<std::string> v2 = v1;
    for (auto &s : v2)
        std::cout << s << ' ';
    std::cout << "\n\n";

    std::cout << ">>> Move constructor:\n";
    Vec<std::string> v3 = std::move(v2);
    for (auto &s : v3)
        std::cout << s << ' ';
    std::cout << "\n\n";

    std::cout << ">>> Assignment operator:\n";
    Vec<std::string> v4;
    v4 = v1;
    for (auto &s : v4)
        std::cout << s << ' ';
    std::cout << "\n\n";

    std::cout << ">>> Testing reserve:\n";
    v4.reserve(20);
    std::cout << "Capacity after reserve(20): " << v4.capacity() << "\n\n";

    std::cout << ">>> Testing resize (shrink):\n";
    v4.resize(2);
    for (auto &s : v4)
        std::cout << s << ' ';
    std::cout << "\nSize after resize(2): " << v4.size() << "\n\n";

    std::cout << ">>> Testing resize (expand):\n";
    v4.resize(5); // Will fill new elements with " " (string with one space)
    for (auto &s : v4)
        std::cout << '[' << s << "] ";
    std::cout << "\nSize after resize(5): " << v4.size() << "\n";

    return 0;
}
