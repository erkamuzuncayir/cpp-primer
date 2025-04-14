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
    string last,      curr,       most;
    int    count = 1, most_count, max_input = 10;

    while (cin >> curr && --max_input > 0)
    {
        if (last != curr)
        {
            if (count >= most_count)
            {
                most_count = count;
                most       = last;
            }
            count = 1;
        }
        last = curr;
        count++;
    }

    if (most_count > 1)
        cout << most << " is repeated " << most_count << " times.\n";
    else
        cout << "No word is repeated.\n";
}
