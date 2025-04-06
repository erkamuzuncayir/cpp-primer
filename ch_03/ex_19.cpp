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
    vector<int> v1 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42}; // Same as below
    vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};    // Same as above
    vector<int> v3(10, 42);                             // Preferred due to ease of use.

    cout << "v1" << endl;
    cout << v1.size() << endl;
    for (auto i : v1)
        cout << i << endl;

    cout << "v2" << endl;
    cout << v2.size() << endl;
    for (auto i : v2)
        cout << i << endl;

    cout << "v3" << endl;
    cout << v3.size() << endl;
    for (auto i : v3)
        cout << i << endl;


    return 0;
}
