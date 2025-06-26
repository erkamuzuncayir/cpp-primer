/***************************************************************************
 *  @file       ex_30.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>

// Class
class Class
{
public:
    Class() { std::cout << "Class default\n"; }
    Class(const Class &) { std::cout << "Class copy\n"; }
    explicit Class(int) { std::cout << "Class(int)\n"; }
};

// Base inherits from Class
class Base : public Class
{
public:
    Base() { std::cout << "Base default\n"; }
    Base(const Base &) { std::cout << "Base copy\n"; }
    explicit Base(int i) : Class(i) { std::cout << "Base(int)\n"; }
};

// D1 virtually inherits Base
class D1 : virtual public Base
{
public:
    D1() : Base() { std::cout << "D1 default\n"; }
    D1(const D1 &d) : Base(d) { std::cout << "D1 copy\n"; }
    explicit D1(int i) : Base(i) { std::cout << "D1(int)\n"; }
};

// D2 virtually inherits Base
class D2 : virtual public Base
{
public:
    D2() : Base() { std::cout << "D2 default\n"; }
    D2(const D2 &d) : Base(d) { std::cout << "D2 copy\n"; }
    explicit D2(int i) : Base(i) { std::cout << "D2(int)\n"; }
};

// MI inherits D1 and D2
class MI : public D1, public D2
{
public:
    MI() : Base(), D1(), D2() { std::cout << "MI default\n"; }
    MI(const MI &m) : Base(m), D1(m), D2(m) { std::cout << "MI copy\n"; }
    explicit MI(int i) : Base(i), D1(i), D2(i) { std::cout << "MI(int)\n"; }
};

// Final inherits MI and Class directly
class Final : public MI, public Class
{
public:
    Final() : MI(), Class() { std::cout << "Final default\n"; }
    // error: ‘Class’ is an ambiguous base of ‘Final’
    Final(const Final &f) : MI(f), Class(f) { std::cout << "Final copy\n"; }
    Final(int i) : MI(i), Class(i) { std::cout << "Final(int)\n"; }
};

int main()
{
    std::cout << "===== Default Constructor =====\n";
    Final f1;

    std::cout << "\n===== Int Constructor =====\n";
    Final f2(42);

    std::cout << "\n===== Copy Constructor =====\n";
    Final f3(f2);
}
