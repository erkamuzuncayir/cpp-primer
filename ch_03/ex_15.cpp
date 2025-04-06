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
    int            count = 5;
    string         temp;
    vector<string> words;

    while (count-- > 0 && cin >> temp)
        words.push_back(temp);

    for (auto num : words)
        cout << num << endl;

    return 0;
}
