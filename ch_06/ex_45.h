//
// Created by erkam on 4/17/25.
//

#ifndef EX_45_H
#define EX_45_H

#include <iostream>
using std::cout;
using std::cin;

inline unsigned my_abs(int n)
{
    return static_cast<unsigned>(n);
}

inline void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1      = *n2;
    *n2      = temp;
}

inline void reset(int& n)
{
    n = 0;
}

inline int detect_larger(const int* ptr_int, const int n)
{
    return *ptr_int > n ? *ptr_int : n;
}

inline void swap_pointers(int*& ptr_1, int*& ptr_2)
{
    int* temp = ptr_1;
    ptr_1     = ptr_2;
    ptr_2     = temp;
}


#endif //EX_45_H
