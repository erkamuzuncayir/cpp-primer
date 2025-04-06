//
// Created by Erkam on 4/6/2025.
//

#include <iostream>
#include <iterator>

using std::cout;
using std::begin;
using std::end;

int main()
{
    bool is_equal    = true;
    int  arr_one[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int  arr_two[10] = {99, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto b_one = begin((arr_one)), e_one = end(arr_one);
    auto b_two = begin((arr_two)), e_two = end(arr_two);

    while (b_one != e_one)
    {
        if (*b_one++ != *b_two++)
        {
            is_equal = false;
            break;
        }
    }

    if (b_two != e_two)
        is_equal = false;

    if (is_equal)
        cout << "equal\n";
    else
        cout << "not equal\n";
}
