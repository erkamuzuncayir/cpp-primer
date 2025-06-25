// -----------------------------------------------------------------------------
// File:        ex_63_64.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <cstring>
#include <iostream>
#include <vector>

template <typename T>
std::size_t count_occurrences(std::vector<T> vec, T value)
{
    std::size_t count = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
        if (*it == value)
            ++count;

    return count;
}

template <>
std::size_t count_occurrences(std::vector<const char *> vec, const char *value)
{
    std::size_t count = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
        if (strcmp(*it, value) == 0)
            ++count;

    return count;
}

int main()
{
    std::vector<int> v1 = {1, 2, 3, 2, 4, 2};
    std::cout << "Occurrences of 2 in v1: " << count_occurrences(v1, 2) << "\n";

    std::vector<std::string> v2 = {"apple", "banana", "apple", "cherry"};
    std::cout << "Occurrences of 'apple' in v2: " << count_occurrences(v2, std::string("apple")) << "\n";

    std::vector<const char *> v3 = {"foo", "bar", "foo", "baz"};
    std::cout << "Occurrences of \"foo\" in v3: " << count_occurrences(v3, "foo") << "\n";

    return 0;
}
