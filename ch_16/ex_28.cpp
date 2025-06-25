// -----------------------------------------------------------------------------
// File:        ex_28.cpp
// Author:      Erkam Uzuncayir
// Date:        24/06/2025
// -----------------------------------------------------------------------------

#include <functional>
#include <iostream>
#include <memory>
#include <string>

template <typename T>
class my_shared_ptr
{
public:
    my_shared_ptr() : ptr(nullptr), ref_count(nullptr), deleter(Delete()) {}
    explicit my_shared_ptr(T *p) : ptr(p), ref_count(new size_t(1)), deleter(Delete()) {}
    template <typename Deleter>
    my_shared_ptr(T *p, Deleter d) : ptr(p), ref_count(new size_t(1)), deleter(d)
    {
    }
    my_shared_ptr(const my_shared_ptr<T> &rhs) : ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(rhs.deleter)
    {
        if (ref_count)
            ++(*rhs.ref_count);
    }
    my_shared_ptr<T> &operator=(const my_shared_ptr<T> &rhs)
    {
        if (this != &rhs)
        {
            release();
            ptr       = rhs.ptr;
            ref_count = rhs.ref_count;
            deleter   = rhs.deleter;
            if (ref_count)
                ++(*rhs.ref_count);
        }
        return *this;
    }

    ~my_shared_ptr() { release(); }

    T          *get() const { return ptr; }
    T          &operator*() const { return *ptr; }
    T          *operator->() const { return ptr; }
    std::size_t use_count() const { return ref_count ? *ref_count : 0; }

private:
    T                       *ptr;
    std::size_t             *ref_count;
    std::function<void(T *)> deleter;

    void release()
    {
        if (ref_count && --(*ref_count) == 0)
        {
            if (deleter && ptr)
                deleter(ptr);
            delete ref_count;
        }
        ptr       = nullptr;
        ref_count = nullptr;
        deleter   = nullptr;
    }

    struct Delete
    {
        void operator()(T *p) const { delete p; }
    };
};


template <typename T>
class my_unique_ptr
{
public:
    my_unique_ptr() : ptr(nullptr), deleter(Delete()) {}
    explicit my_unique_ptr(T *p) : ptr(p), deleter(Delete()) {}
    template <typename Deleter>
    my_unique_ptr(T *p, Deleter d) : ptr(p), deleter(d)
    {
    }
    my_unique_ptr<T>(const my_unique_ptr<T> &rhs)            = delete;
    my_unique_ptr<T> &operator=(const my_unique_ptr<T> &rhs) = delete;
    my_unique_ptr<T>(my_unique_ptr &&rhs) noexcept : ptr(rhs.ptr), deleter(std::move(rhs.deleter))
    {
        rhs.ptr = nullptr;
    }
    my_unique_ptr<T> &operator=(my_unique_ptr<T> &&rhs) noexcept
    {
        if (this != &rhs)
        {
            release();
            ptr     = rhs.ptr;
            deleter = std::move(rhs.deleter);
            rhs.ptr = nullptr;
        }
        return *this;
    }
    ~my_unique_ptr() { release(); }

    T *get() const { return ptr; }
    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }

private:
    T                       *ptr;
    std::function<void(T *)> deleter;

    void release()
    {
        if (deleter && ptr)
            deleter(ptr);
        ptr = nullptr;
    }

    struct Delete
    {
        void operator()(T *p) const { delete p; }
    };
};

int main()
{
    my_shared_ptr<int> sp1(new int(5));
    my_shared_ptr<int> sp2 = sp1;
    std::cout << "shared count: " << sp1.use_count() << "\n";

    my_unique_ptr<std::string> up(new std::string("erkam"));
    std::cout << "unique value: " << *up << "\n";

    my_unique_ptr<std::string> up2 = std::move(up);
    if (!up.get())
        std::cout << "up is empty after move\n";
}
