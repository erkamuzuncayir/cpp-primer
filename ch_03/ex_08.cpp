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
    string     word("example");
    int        i    = 0;
    const auto size = word.size();

    cout << "Before: " << word << endl;


    while (i < size)
    {
        word[i] = 'X';
        i++;
    }

    for (i      = 0; i < size; i++) // This one. Simple, descriptive and enough.
        word[i] = 'X';

    cout << "After: " << word << endl;

    return 0;
}
