/***************************************************************************
 *  @file       ex_18.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-27
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void count_empty_strings(const std::vector<std::string> &vec)
{
    // pointer to std::string::empty()
    auto mem_fn = &std::string::empty;

    // count where .empty() == true
    auto count = std::count_if(vec.begin(), vec.end(),
                               [mem_fn](const std::string &s)
                               {
                                   return (s.*mem_fn)(); // call s.empty()
                               });

    std::cout << "Number of empty strings: " << count << "\n";
}

int main()
{
    std::vector<std::string> vec = {"", "hello", "", "world", ""};
    count_empty_strings(vec);
}
