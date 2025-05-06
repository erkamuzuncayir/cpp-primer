//
// Created by erkam on 06/05/25.
//

#include <vector>

// example.h
class Example {
public:
    static constexpr double rate = 6.5; // Should constexpr
    static const int vecSize = 20;
    static std::vector<double> vec(vecSize); // We may not init in-class initial
};

// example.C
//#include "example.h"
constexpr double Example::rate; // Should constexpr
std::vector<double> Example::vec;
