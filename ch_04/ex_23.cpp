//
// Created by erkam on 4/8/25.
//

#include <string>
using std::string;

int main()
{
    string s = "word";
    string pl = s + (s[s.size() - 1] == 's' ? "" : "s"); // Precedence of '+' is higher than '?'
}
