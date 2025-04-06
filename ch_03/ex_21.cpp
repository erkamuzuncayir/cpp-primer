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
    vector<int>    v1;                        // 0, 0
    vector<int>    v2(10);                  // 10, 0
    vector<int>    v3(10, 42);         // 10, 42
    vector<int>    v4{10};                    // 1, 10
    vector<int>    v5{10, 42};                // 2, {10, 42}
    vector<string> v6{10};                  // 10, ""
    vector<string> v7{10, "hi"};    // 10, "hi"

    cout << "v1" << endl;
    cout << v1.size() << endl;
    for (auto it = v1.cbegin(); it != v1.cend(); ++it)
        cout << *it << " ";

    cout << endl;

    cout << "v2" << endl;
    cout << v2.size() << endl;
    for (auto it = v2.cbegin(); it != v2.cend(); ++it)
        cout << *it << " ";

    cout << endl;

    cout << "v3" << endl;
    cout << v3.size() << endl;
    for (auto it = v3.cbegin(); it != v3.cend(); ++it)
        cout << *it << " ";

    cout << endl;

    cout << "v4" << endl;
    cout << v4.size() << endl;
    for (auto it = v4.cbegin(); it != v4.cend(); ++it)
        cout << *it << " ";

    cout << endl;

    cout << "v5" << endl;
    cout << v5.size() << endl;
    for (auto it = v5.cbegin(); it != v5.cend(); ++it)
        cout << *it << " ";

    cout << endl;

    cout << "v6" << endl;
    cout << v6.size() << endl;
    for (auto it = v6.cbegin(); it != v6.cend(); ++it)
        cout << *it << " ";

    cout << endl;

    cout << "v7" << endl;
    cout << v7.size() << endl;
    for (auto it = v7.cbegin(); it != v7.cend(); ++it)
        cout << *it << " ";

    cout << endl;

    return 0;
}
