//
// Created by erkam on 4/14/25.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string s_one, s_two, response;

    do
    {
        cin >> s_one;
        cin >> s_two;

        cout << (s_one == s_two ? "Equal\n" : s_one <= s_two ? "Less\n" : "Greater\n");

        cout << "Continue? (y/n): ";
        cin >> response;
    } while (response == "y");
}
