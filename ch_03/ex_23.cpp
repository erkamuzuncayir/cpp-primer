//
// Created by Erkam on 4/5/2025.
//

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> nums(10, 42);

    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        cout << *it << ' ';

    cout << endl;

    for (auto it = nums.begin(); it != nums.end(); ++it)
        *it      = *it * 2;

    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        cout << *it << ' ';

    cout << endl;
    return 0;
}
