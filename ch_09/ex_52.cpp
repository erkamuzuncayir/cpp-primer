// -----------------------------------------------------------------------------
// File:        ex_52.cpp
// Author:      Erkam Uzuncayir
// Date:        10/05/2025
// -----------------------------------------------------------------------------

#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::stack;
using std::string;

int main(void)
{
    string      str("(!intStack.empty())))");
    stack<char> parenthesis_check;
    unsigned    unmatched_count = 0;
    auto        it              = str.cbegin();
    while (it != str.cend())
    {
        if (*it == ')')
        {
            bool matched = false;
            while (!parenthesis_check.empty())
            {
                if (parenthesis_check.top() == '(')
                {
                    parenthesis_check.pop();
                    matched = true;
                    break;
                }
                else
                    parenthesis_check.pop();
            }
            if (!matched)
                unmatched_count++;
        }
        else
            parenthesis_check.push(*it);

        ++it;
    }

    // Openning parenthesis
    while (!parenthesis_check.empty())
    {
        if (parenthesis_check.top() == '(')
            unmatched_count++;
        parenthesis_check.pop();
    }

    cout << "There are " << unmatched_count << " amount of unmatched parenthesises.";

    return 0;
}
