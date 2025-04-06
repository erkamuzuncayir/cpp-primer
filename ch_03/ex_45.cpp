//
// Created by Erkam on 4/6/2025.
//

#include <iostream>

using std::cout;

int main()
{
    int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

    for (auto &row : ia)
    {
        for (auto col : row)
            cout << col << ' ';
    }

    cout << '\n';

    for (auto i = 0; i < 3; ++i)
    {
        for (auto j = 0; j < 4; ++j)
            cout << ia[i][j] << ' ';
    }

    cout << '\n';

    for (auto row = ia; row != ia + 3; ++row)
    {
        for (auto col = *row; col != *row + 4; ++col)
            cout << *col << ' ';
    }
}
