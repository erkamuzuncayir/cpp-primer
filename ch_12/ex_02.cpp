// -----------------------------------------------------------------------------
// File:        ex_02.cpp
// Author:      Erkam Uzuncayir
// Date:        11/06/2025
// -----------------------------------------------------------------------------

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool      empty() const { return data->empty(); }

    void push_back(const std::string &s) const;
    void pop_back();

    std::string       &front();
    const std::string &front() const;
    std::string       &back();
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void                                      check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::push_back(const std::string &s) const { data->push_back(s); }

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void test(StrBlob &sb)
{
    try
    {
        sb.push_back("c");
        sb.push_back("def");
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        sb.pop_back();
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        sb.pop_back();
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    }
    catch (std::out_of_range &err)
    {
        std::cerr << err.what() << " out of range" << std::endl;
    }
    catch (std::exception &err)
    {
        std::cerr << err.what() << std::endl;
    }
}

void test(const StrBlob &sb)
{
    try
    {
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    }
    catch (std::out_of_range &err)
    {
        std::cerr << err.what() << " out of range" << std::endl;
    }
    catch (std::exception &err)
    {
        std::cerr << err.what() << std::endl;
    }
}

int main()
{
    StrBlob       sb1;
    StrBlob       sb2{"Hello", "World"};
    StrBlob       sb3 = {"Bye", "World"};
    const StrBlob csb1;
    const StrBlob csb2{"This", "is", "Blob"};

    test(sb1);
    std::cout << std::endl;
    test(sb2);
    std::cout << std::endl;
    test(sb3);
    std::cout << std::endl;
    test(csb1);
    std::cout << std::endl;
    test(csb2);
    std::cout << std::endl;
    test({"ppp", "qqq"});
    std::cout << std::endl;

    return 0;
}
