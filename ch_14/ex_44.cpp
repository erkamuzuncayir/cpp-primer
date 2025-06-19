// -----------------------------------------------------------------------------
// File:        ex_44.cpp
// Author:      Erkam Uzuncayir
// Date:        19/06/2025
// -----------------------------------------------------------------------------

#include <functional>
#include <iostream>
#include <map>
#include <string>

struct divide
{
    int operator()(int denominator, int divisor) { return denominator / divisor; }
};

int add(int i, int j) { return i + j; }

int main()
{
    auto                                                mod    = [](int i, int j) { return i % j; };
    std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add}, {"-", std::minus<int>()}, {"/", divide()}, {"*", [](int i, int j) { return i * j; }}, {"%", mod}};

    std::cout << "Enter an operation(+, -, /, *, %) and two operands: ";
    std::string op;
    int         lhs, rhs;
    std::cin >> op >> lhs >> rhs;
    double result = binops[op](lhs, rhs);
    std::cout << "Result: " << result << std::endl;
}
