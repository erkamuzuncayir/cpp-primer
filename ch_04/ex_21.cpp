//
// Created by erkam on 4/8/25.
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> i_vec_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i : i_vec_1)
        cout << (i % 2 == 0 ? "even\n" : "odd\n");
}
