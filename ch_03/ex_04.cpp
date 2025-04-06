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
    string word_one, word_two;

    cin >> word_one;
    cin >> word_two;

    if (word_one == word_two)
        cout << "Words are the same" << endl;
    else if (word_one > word_two)
        cout << "Word one larger" << endl;
    else
        cout << "Word two larger" << endl;

    if (word_one.length() == word_two.length())
        cout << "Lengths are equal" << endl;
    else if (word_one.length() > word_two.length())
        cout << "Word one taller" << endl;
    else
        cout << "Word two taller" << endl;


    return 0;
}
