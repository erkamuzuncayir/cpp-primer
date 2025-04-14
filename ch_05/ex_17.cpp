//
// Created by erkam on 4/14/25.
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> vec_one{1, 2};
    vector<int> vec_two{1, 2, 3, 4};

    for (int i = 0; i < vec_one.size(); ++i)
    {
        if (vec_one[i] != vec_two[i])
        {
            cout << "Not prefix\n";
            return 0;
        }
    }

    cout << "Prefix\n";
}
