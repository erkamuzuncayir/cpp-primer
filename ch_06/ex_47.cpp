//
// Created by erkam on 4/17/25.
//


#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::iterator;

void print_vector(vector<int>::const_iterator curr, vector<int>::const_iterator end)
{
#ifndef NDEBUG
    cout << "diff between curr and end: " << end - curr << "\n";
#endif
    if (curr != end)
    {
        cout << *curr << " ";
        print_vector(++curr, end);
    }
}

int main(void)
{
    vector<int> v = {0, 1, 2, 3};
    print_vector(v.cbegin(), v.cend());
}
