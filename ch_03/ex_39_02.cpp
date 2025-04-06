//
// Created by Erkam on 4/6/2025.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    const string str_one("hello"), str_two("hellow");

    if (str_one == str_two)
        cout << "equal\n";
    else
        cout << "not equal\n";

    return 0;
}
