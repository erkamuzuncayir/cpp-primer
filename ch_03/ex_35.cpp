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
    int  arr[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto b       = begin((arr)), e = end(arr);

    while (b != e)
        *b++ = 0;

    for (auto i : arr)
        cout << i << " ";
}
