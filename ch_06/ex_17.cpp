//
// Created by erkam on 4/16/25.
//

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// This is not change anything so it is const.
bool is_any_upper(const string& s)
{
    for (char c : s)
    {
        if (isupper(c))
            return true;
    }

    return false;
}

// This is changing characters of string so it is not const.
void to_lower(string& s)
{
    for (char& c : s)
        c = tolower(c);
}

int main(void)
{
    string s = "Hello, world!";

    cout << s << (is_any_upper(s) ? " Has uppercase letter." : " Hasn't any uppercase letter.") << endl;

    cout << "All lowercase version of \"" << s << "\" is: ";
    to_lower(s);
    cout << s << endl;
}
