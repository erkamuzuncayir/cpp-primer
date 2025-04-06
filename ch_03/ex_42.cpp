//
// Created by Erkam on 4/6/2025.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec(10, 42);
    int         arr[10];

    for (int i = 0; i < vec.size(); ++i)
        arr[i] = vec[i];

    for (int e : arr)
        cout << e << ' ';

    return 0;
}
