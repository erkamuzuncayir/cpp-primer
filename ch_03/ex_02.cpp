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
    int count = 5;
    string line, word;

    // while (getline(cin, line) && count-- > 0)
    //     cout << line << endl;

    while (count-- > 0 && cin >> word)
        cout << word << endl;

    return 0;
}