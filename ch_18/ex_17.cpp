/***************************************************************************
 *  @file       ex_17.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>

namespace Exercise
{
    int       ivar  = 10;
    double    dvar  = 2.718;
    const int limit = 1000;
}

int ivar = 42; // global ivar

// CASE A: using declarations at position 1
using Exercise::dvar;
using Exercise::ivar;
using Exercise::limit;

void manip_case_A()
{
    double dvar = 3.1416;
    int    iobj = limit + 1; // OK
    ++ivar;                  // refers to Exercise::ivar
    ++::ivar;                // refers to global ivar

    std::cout << "CASE A:\n";
    std::cout << "Exercise::ivar = " << Exercise::ivar << "\n";
    std::cout << "::ivar = " << ::ivar << "\n";
}

// CASE B: using declarations at position 2
void manip_case_B()
{
    double dvar = 3.1416;
    using Exercise::dvar;
    using Exercise::ivar;
    using Exercise::limit;

    int iobj = limit + 1;

    // ++ivar;  // ❌ ambiguous — which ivar? global or Exercise? Commented to prevent error
    ++::ivar;

    std::cout << "CASE B:\n";
    std::cout << "Exercise::ivar = " << Exercise::ivar << "\n";
    std::cout << "::ivar = " << ::ivar << "\n";
}

// CASE C: using directive
void manip_case_C()
{
    using namespace Exercise;

    double dvar = 3.1416;
    int    iobj = limit + 1;

    // ++ivar;  // ❌ ambiguous with global ivar
    ++::ivar;

    std::cout << "CASE C:\n";
    std::cout << "Exercise::ivar = " << Exercise::ivar << "\n";
    std::cout << "::ivar = " << ::ivar << "\n";
}

int main()
{
    manip_case_A();
    manip_case_B();
    manip_case_C();

    return 0;
}
