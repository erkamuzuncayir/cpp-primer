//
// Created by erkam on 08/05/25.
//

#include <iostream>
#include <vector>

using std::vector;

vector<int>::const_iterator contains(vector<int>::const_iterator beg, vector<int>::const_iterator end, int value)
{
    while (beg != end)
    {
        if (*beg == value)
            return beg;
        ++beg;
    }
    return end;
}

int main(void)
{
    vector<int> vec_int{1, 2, 3, 4, 5};
    contains(vec_int.cbegin(), vec_int.cend(), 3) != vec_int.cend() ? std::cout << "Contain\n"
                                                                    : std::cout << "Not contain\n";
}
