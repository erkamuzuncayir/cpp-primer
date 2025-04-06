//
// Created by Erkam on 4/5/2025.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> first_vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> second_vec(first_vec);

    for (const auto s : second_vec)
        cout << s << " ";

    cout << endl;

    return 0;
}
