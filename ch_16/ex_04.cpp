// -----------------------------------------------------------------------------
// File:        ex_04.cpp
// Author:      Erkam Uzuncayir
// Date:        23/06/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <vector>

template <typename Iterator, typename T>
Iterator my_find(const Iterator &it_beg, const Iterator &it_end, const T &val)
{
    for (Iterator it = it_beg; it != it_end; ++it)
        if (*it == val)
            return it;

    return it_end;
}

int main()
{
    std::vector<int> i_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int              val   = 3;

    auto res_vec = my_find(i_vec.cbegin(), i_vec.cend(), val);

    std::cout << *res_vec << std::endl;

    std::list<std::string> str_list = {"Hello", "World", "GNOME", "KDE"};
    std::string            str      = "GNOME";

    auto res_list = my_find(str_list.cbegin(), str_list.cend(), str);

    std::cout << *res_list << std::endl;
}
