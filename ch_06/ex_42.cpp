//
// Created by erkam on 4/17/25.
//

#include <iostream>
#include <string>

using std::cout;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main(void)
{
    cout << make_plural(2, "confess", "es") << '\n';
    cout << make_plural(2, "value");
}