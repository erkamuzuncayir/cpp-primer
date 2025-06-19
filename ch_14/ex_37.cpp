// -----------------------------------------------------------------------------
// File:        ex_37.cpp
// Author:      Erkam Uzuncayir
// Date:        18/06/2025
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>
class Is_Equal
{
public:
    Is_Equal(int v) : val(v) {}
    bool operator()(int v) const { return v == val; }

private:
    int val;
};

int main()
{
    std::vector<int> i_vec{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

    for (auto i : i_vec)
        std::cout << i << ' ';
    std::cout << std::endl;

    std::replace_if(i_vec.begin(), i_vec.end(), Is_Equal(1), -1);

    for (auto i : i_vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}
