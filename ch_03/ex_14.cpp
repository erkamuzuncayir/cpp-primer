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
    int         count = 5, num;
    vector<int> nums;

    while (count-- > 0 && cin >> num)
        nums.push_back(num);

    for (auto num : nums)
        cout << num << endl;

    return 0;
}
