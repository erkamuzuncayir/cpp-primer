//
// Created by Erkam on 4/6/2025.
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    vector<int>    v_one(10, 24);
    vector<int>    v_two(10, 42);

    if (v_one == v_two)
        cout << "equal\n";
    else
        cout << "not equal\n";

    return 0;
}
