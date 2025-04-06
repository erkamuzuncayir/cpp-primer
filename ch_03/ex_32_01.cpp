//
// Created by Erkam on 4/5/2025.
//

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    constexpr int size            = 10;
    int first_arr[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int second_arr[size];

    for (int i = 0; i < 10; i++)
        second_arr[i] = first_arr[i];

    for (const auto s : second_arr)
        cout << s << " ";

    cout << endl;

    return 0;
}
