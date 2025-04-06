//
// Created by Erkam on 4/5/2025.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string word("example");

    cout << "Before: " << word << endl;
    for (auto& c : word)
        c = 'X';

    cout << "After: " << word << endl;

    return 0;
}
