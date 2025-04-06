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

    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
            temp = nums[i];
        else
        {
            cout << temp + nums[i] << " ";
            temp = 0;
        }
    }

    for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
        cout << nums[i] + nums[j] << " ";

    return 0;
}
