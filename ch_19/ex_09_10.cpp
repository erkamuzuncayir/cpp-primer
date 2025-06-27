/***************************************************************************
 *  @file       ex_09_10.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-27
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>
#include <string>
#include <typeinfo>

struct Sales_data
{
};

class Base
{
public:
    virtual ~Base() {}
};
class Derived : public Base
{
};

class A
{
public:
    virtual ~A() {}
};
class B : public A
{
};
class C : public B
{
};

int main()
{
    // ex_09
    int     arr[10];
    Derived d;
    Base   *p = &d;

    std::cout << "int: " << typeid(42).name() << "\n";
    std::cout << "int[10]: " << typeid(arr).name() << "\n";
    std::cout << "Sales_data: " << typeid(Sales_data).name() << "\n";
    std::cout << "std::string: " << typeid(std::string).name() << "\n";
    std::cout << "Base*: " << typeid(p).name() << "\n";
    std::cout << "dynamic *p: " << typeid(*p).name() << "\n";

    // ex_10
    A *pa = new C;
    std::cout << "(a) typeid(pa): " << typeid(pa).name() << "\n";

    C  cobj;
    A &ra = cobj;
    std::cout << "(b) typeid(&ra): " << typeid(&ra).name() << "\n";

    B *px  = new B;
    A &ra2 = *px;
    std::cout << "(c) typeid(ra2): " << typeid(ra2).name() << "\n";

    delete pa;
    delete px;
}
