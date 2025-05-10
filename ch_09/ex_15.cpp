//
// Created by erkam on 08/05/25.
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main(void)
{
    vector<int> iv_1{1, 2, 3};
    vector<int> iv_2{1, 2, 1, 4};

    iv_1 == iv_2 ? cout << "Equal\n" : cout << "Not equal\n";
    return 0;
}
