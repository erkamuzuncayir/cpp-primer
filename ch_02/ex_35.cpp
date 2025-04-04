//
// Created by Erkam on 4/4/2025.
//

// const int i = 42;            i is an int.
// auto j = i;                  j is an int.
// const auto &k = i;           k is a const reference to an int.
// auto *p = &i;                p is a const pointer to an int.
// const auto j2 = i, &k2 = i;  j2 is a const int.
//                              k2 is a const reference to an int.

#include <iostream>

int main()
{
    const int   i  = 42;
    auto        j  = i;
    const auto& k  = i;
    auto*       p  = &i;
    const auto  j2 = i, &k2 = i;

    std::cout << "j is " << typeid(j).name() << std::endl;
    std::cout << "k is " << typeid(k).name() << std::endl;
    std::cout << "p is " << typeid(p).name() << std::endl;
    std::cout << "j2 is " << typeid(j2).name() << std::endl;
    std::cout << "k2 is " << typeid(k2).name() << std::endl;

    return 0;
}
