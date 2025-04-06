//
// Created by Erkam on 4/6/2025.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> int_vec(begin(arr), end(arr));

    for (auto i : int_vec)
        cout << i << ' ';
}