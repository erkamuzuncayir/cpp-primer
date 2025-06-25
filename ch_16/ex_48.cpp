// -----------------------------------------------------------------------------
// File:        ex_48.cpp
// Author:      Erkam Uzuncayir
// Date:        24/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
std::string debug_rep(const T &t);
template <typename T>
std::string debug_rep(T *p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char *p);
std::string debug_rep(const char *p);

template <typename T>
std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
std::string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;

    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";

    return ret.str();
}

std::string debug_rep(const std::string &s) { return '"' + s + '"'; }
std::string debug_rep(char *p) { return debug_rep(std::string(p)); }
std::string debug_rep(const char *p) { return debug_rep(std::string(p)); }

int main()
{
    std::cout << "Test debug_rep(const T&) with int:\n";
    std::cout << "Input: 42\nOutput: " << debug_rep(42) << "\n\n";

    std::cout << "Test debug_rep(const std::string&):\n";
    std::cout << "Input: \"hello\"\nOutput: " << debug_rep(std::string("hello")) << "\n\n";

    std::cout << "Test debug_rep(const char*):\n";
    std::cout << "Input: \"world\"\nOutput: " << debug_rep("world") << "\n\n";

    std::cout << "Test debug_rep(char*):\n";
    char cstr[] = "test";
    std::cout << "Input: char cstr[] = \"test\"\nOutput: " << debug_rep(cstr) << "\n\n";

    std::cout << "Test debug_rep(T*) with valid int pointer:\n";
    int x = 99;
    std::cout << "Input: pointer to x = 99\nOutput: " << debug_rep(&x) << "\n\n";

    std::cout << "Test debug_rep(T*) with null pointer:\n";
    int *null_int = nullptr;
    std::cout << "Input: nullptr\nOutput: " << debug_rep(null_int) << "\n\n";

    std::cout << "Tests complete. Visually check outputs.\n";
}
