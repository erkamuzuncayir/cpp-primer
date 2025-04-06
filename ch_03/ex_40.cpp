//
// Created by Erkam on 4/6/2025.
//

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    const char str_one[] = "hello";
    const char str_two[] = "world!";
    char       str_three[13];

    strcpy(str_three, str_one);
    strcat(str_three, " ");
    strcat(str_three, str_two);

    cout << str_three << endl;
}
