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
    int         count = 10;
    int         temp  = 0;
    vector<int> nums;

    while (count-- > 0 && cin >> temp)
        nums.push_back(temp);

    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        cout << *it + *++it << ' ';

    cout << endl;
    for (auto beg_it = nums.cbegin(), end_it = nums.cend() - 1; beg_it != nums.cend(); ++beg_it, --end_it)
        cout << *beg_it + *end_it << ' ';

    cout << endl;

    return 0;
}
