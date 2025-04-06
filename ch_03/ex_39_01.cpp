//
// Created by Erkam on 4/6/2025.
//

#include <iostream>
#include <cstring>

using std::cout;
using std::strcmp;

int main()
{
    char str_one[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str_two[10] = {'h', 'e', 'l', 'l', 'o', 'w', '\0'};

    if (std::strcmp(&str_one[0], &str_two[0]) == 0)
        cout << "equal\n";
    else
        cout << "not equal\n";
}
